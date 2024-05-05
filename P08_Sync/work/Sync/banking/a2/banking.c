//******************************************************************************
// Course:  BSy
// File:    banking.c
// Author:  M. Thaler, ZHAW
// Purpose: locking mechanisms
// Version: v.fs20
//******************************************************************************

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#define FATAL(M)            \
    do                      \
    {                       \
        perror(M);          \
        exit(EXIT_FAILURE); \
    } while (0)
#include "banking.h"

//******************************************************************************

typedef struct account_struct_
{
    long int balance;
    pthread_mutex_t acntLock;
} Account;

typedef struct branch_struct
{
    Account *accounts;
    pthread_mutex_t branchLock;
} Branch;

//******************************************************************************

static Branch *Bank;
static int nBranches, nAccounts;

//******************************************************************************
// banking functions

void makeBank(int num_branches, int num_accounts)
{
    nBranches = num_branches;
    nAccounts = num_accounts;
    Bank = (Branch *)malloc(nBranches * sizeof(Branch));

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);

    for (int i = 0; i < nBranches; i++)
    {
        Bank[i].accounts = (Account *)malloc(nAccounts * sizeof(Account));
        pthread_mutex_init(&(Bank[i].branchLock), &attr);
        for (int j = 0; j < nAccounts; j++)
        {
            Bank[i].accounts[j].balance = 0;
            pthread_mutex_init((&(Bank[i].accounts[j].acntLock)), &attr);
        }
    }
}

void deleteBank(void)
{
    for (int i = 0; i < nBranches; i++)
        free(Bank[i].accounts);
    free(Bank);
    nBranches = nAccounts = 0;
}

long int withdraw(int branchNr, int accountNr, long int value)
{
    int rv, tmp;
    rv = 0;

    // mutex lock for account
    if (pthread_mutex_lock(&Bank[branchNr].accounts[accountNr].acntLock) != 0)
    {
        FATAL("lock");
    }
    if(pthread_mutex_lock(&Bank[branchNr].branchLock) != 0) {FATAL("bank lock");}

    tmp = Bank[branchNr].accounts[accountNr].balance - value;
    if (tmp >= 0)
    {
        Bank[branchNr].accounts[accountNr].balance = tmp;
        rv = value;
    }

    if(pthread_mutex_unlock(&Bank[branchNr].branchLock) != 0) {FATAL("bank unlock");}
    // mutex lock for account
    if (pthread_mutex_unlock(&Bank[branchNr].accounts[accountNr].acntLock) != 0)
    {
        FATAL("unlock");
    }

    return rv;
}

void deposit(int branchNr, int accountNr, long int value)
{
    // mutex lock for account
    if (pthread_mutex_lock(&Bank[branchNr].accounts[accountNr].acntLock) != 0)
    {
        FATAL("lock");
    }
    if(pthread_mutex_lock(&Bank[branchNr].branchLock) != 0) {FATAL("bank lock");}
    Bank[branchNr].accounts[accountNr].balance += value;
    if(pthread_mutex_unlock(&Bank[branchNr].branchLock) != 0) {FATAL("bank unlock");}
    // mutex lock for account
    if (pthread_mutex_unlock(&Bank[branchNr].accounts[accountNr].acntLock) != 0)
    {
        FATAL("unlock");
    }
}

void transfer(int fromB, int toB, int accountNr, long int value)
{
    int money = withdraw(fromB, accountNr, value);
    if (money >= 0)
        deposit(toB, accountNr, money);
}

void checkAssets(void)
{
    static long assets = 0;
    long sum = 0;
    for (int i = 0; i < nBranches; i++)
    {
        for (int j = 0; j < nAccounts; j++)
        {
            sum += (long)Bank[i].accounts[j].balance;
        }
    }
    if (assets == 0)
    {
        assets = sum;
        printf("Balance of accounts is: %ld\n", sum);
    }
    else
    {
        if (sum != assets)
            printf("Balance of accounts is: %ld ... not correct\n", sum);
        else
            printf("Balance of accounts is: %ld ... correct\n", assets);
    }
}

//******************************************************************************

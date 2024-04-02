#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#define MAX_STRING_COUNT 10
#define MAX_STRING_LENGTH 11


bool contains(char strings[MAX_STRING_COUNT][MAX_STRING_LENGTH], char text[MAX_STRING_LENGTH]) {
    for (int i = 0; i < MAX_STRING_COUNT; ++i) {
        if (strcmp(strings[i], text) == 0) return true;
    }
    return false;
}

void sort(char unsorted[MAX_STRING_COUNT][MAX_STRING_LENGTH]) {
    for (int i = 0; i < MAX_STRING_COUNT; i++) {
        int j = 0;
        while (strcmp(unsorted[j], unsorted[j + 1]) > 0) {
            char tmp[MAX_STRING_LENGTH];
            strcpy(tmp, unsorted[j]);
            strcpy(unsorted[j], unsorted[j + 1]);
            strcpy(unsorted[j + 1], tmp);

            j++;
        }
    }
}

void string_to_upper(char *startc) {
    while ((*startc++ = *startc & '_'));
}


int main() {
    int count = 0;
    bool inputEnded = false;
    char inputs[MAX_STRING_COUNT][MAX_STRING_LENGTH] = {""};

    while (count < MAX_STRING_COUNT && !inputEnded) {
        char input[MAX_STRING_LENGTH];
        printf("Enter word:\n");
        fgets(input, sizeof(input), stdin);
        if (strcmp("ZZZ\n", input) == 0) {
            inputEnded = true;
            continue;
        }
        if (!contains(inputs, input)) {
            string_to_upper(input);
            strcpy(inputs[count],  input);
        }
        count++;

    }
    printf("\n\nSorted: \n");

    sort(inputs);

    for (size_t i = 0; i < MAX_STRING_COUNT; ++i) {
        if (strlen(inputs[i]) > 0) {
            printf("%s\n", inputs[i]);
        }
    }
    return 0;
}

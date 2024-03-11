#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned int operand1;
  unsigned int operand2;
  char operation;
} Expression;

unsigned int parse_operand(char operand_str[]);
unsigned int bit_operation(Expression expression);
void print_bit_operation_bin(Expression expression, int result);
void print_bit_operation_hex(Expression expression, int result);
void print_bit_operation_dec(Expression expression, int result);

int main() {

  char operand1_str[10];
  char operand2_str[10];
  char operation;

  unsigned int operand1, operand2;

  do {
    printf("Geben sie die Bit-Operation ein:\n");

    scanf("%s %c %s", operand1_str, &operation, operand2_str);

    operand1 = parse_operand(operand1_str);
    operand2 = parse_operand(operand2_str);

    Expression expression = {operand1, operand2, operation};

    unsigned int result = bit_operation(expression);
    print_bit_operation_bin(expression, result);
    print_bit_operation_hex(expression, result);
    print_bit_operation_dec(expression, result);

    printf("\nMoechten sie weiter machen oder abbrechen? [(n)ext|(q)uit] ");
  } while (getchar() == 'n');

  printf("Byebye..\n");
  return EXIT_SUCCESS;
}

unsigned int parse_operand(char operand_str[]) {
  unsigned int operand;
  if (operand_str[0] == '0' && operand_str[1] == 'x') {
    sscanf(&operand_str[2], "%x", &operand);
  } else if (operand_str[0] == '0') {
    sscanf(&operand_str[1], "%o", &operand);
  } else {
    sscanf(operand_str, "%u", &operand);
  }
  return operand;
}

unsigned int bit_operation(Expression expression) {
  switch (expression.operation) {
  case '&':
    return expression.operand1 & expression.operand2;
  case '|':
    return expression.operand1 | expression.operand2;
  case '^':
    return expression.operand1 ^ expression.operand2;
  default:
    return 0;
  }
}
void print_bit_operation_bin(Expression expression, int result);
void print_bit_operation_hex(Expression expression, int result);
void print_bit_operation_dec(Expression expression, int result);

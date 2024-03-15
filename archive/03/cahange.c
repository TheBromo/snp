#include <stdio.h>
#include <stdlib.h>

int main() {
  int a = 3;
  int b = 4;
  printf("a: %d; b: %d\n", a, b);

  b = a ^ b;
  a = b ^ a;
  b = b ^ a;
  printf("a: %d; b: %d\n", a, b);
  return EXIT_SUCCESS;
}

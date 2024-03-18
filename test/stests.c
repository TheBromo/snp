/* strings.c */
#include <stdio.h>
#include <string.h>
char a[4] = "Maus";
char b[] = "Hund";
char c[14] = "Katze";
char d = 'x';
int main(void) {
  printf("strlen(a)=%d\n", strlen(a)); /* Ausgabe? */
  printf("strlen(b)=%d\n", strlen(b)); /* Ausgabe? */
  printf("strlen(c)=%d\n", strlen(c)); /* Ausgabe? */
  strcat(c, b);
  printf("%s\n", c); /* Ausgabe? */
  strcat(c, a);
  printf("%s\n", c); /* Ausgabe? */
  printf("%c\n", d); /* Ausgabe? */
}

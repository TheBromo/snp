#include <stdbool.h>
#include <stdio.h>

int gibIntWert(char name[], int min, int max);
bool istSchaltjahr(int jahr);
int tageProMonat(int jahr, int monat);

enum month_t { JAN = 1, FEB, MAR, APR, MAI, JUN, JUL, AUG, SEP, OKT, NOV, DEZ };

int main(int argc, char *argv[]) {

  int monat, jahr;

  //  Monat einlesen und Bereich ueberpruefen
  monat = gibIntWert("Monat", 1, 12);
  jahr = gibIntWert("Jahr", 1600, 9999);

  //  Ausgabe zum Test
  (void)printf("Monat: %d, Jahr: %d \n", monat, jahr);

  //  Ausgabe zum Test (hier mit dem ternaeren Operator "?:")
  (void)printf("%d ist %s Schaltjahr\n", jahr,
               istSchaltjahr(jahr) ? "ein" : "kein");

  // Ausgabe
  (void)printf("Der Monat %02d-%d hat %d Tage.\n", monat, jahr,
               tageProMonat(jahr, monat));

  return 0;
}

int gibIntWert(char name[], int min, int max) {
  int input;
  scanf("%d", &input);
  if (input <= max && input >= min) {
    return input;
  }
  return 0;
}

bool istSchaltjahr(int jahr) { return jahr % 4 == 0; }

int tageProMonat(int jahr, int monat) {
  switch (monat) {
  case FEB:
    if (istSchaltjahr(jahr)) {
      return 29;
    } else {
      return 28;
    }
  case JAN:
  case MAR:
  case MAI:
  case JUL:
  case SEP:
  case NOV:
    return 30;
  }
  return 31;
}

#include <stdbool.h>
#include <stdio.h>

int gibIntWert(char name[], int min, int max);
bool istSchaltjahr(int jahr);
int tageProMonat(int jahr, int monat);

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

int gibIntWert(char name[], int min, int max) { return 0; }
bool istSchatljahr(int jahr) { return false; }
int tageProMonat(int jahr, int monat) { return 0; }

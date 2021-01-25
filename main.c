/**
 * Gibt an der wie vielte Tag im Jahr es ist
 * Autor: Merlin Schmidt
 * Erstellt am: 11.01.2021
 * Zuletzt bearbeitet: 25.01.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

// Deklaration der LeapYear Funktion
int leapYear (int y);

/**
 * Main-Funktion
 **/
int main() {
  // Variablen die benötigt werden
  int tageProMonat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
  int gueltigeTage = 0;
  int year = 0, month = 0, day = 0;
  int tage = 0;

  // Eingabe des Jahres
  printf("Geben Sie das Jahr ein: \n");
  scanf(" %i", &year);

  // Check für Schaltjahr
  if (leapYear(year) == 1) {
    tageProMonat[1]++;
  }

  // Eingabe die Monats in do-While für den Check der Gültigkeit
  printf("Geben Sie den Monat ein: \n");

  do {
    scanf(" %i", &month);

    if (month < 1 || month > 12) {
      printf("Bitte gültigen Monat eingeben!\n");
    }
  }while(month > 12 || month < 1);

  // Variable um zu speichern wie viele Tage der Monat hat
  gueltigeTage = tageProMonat[month-1];

  // Eingabe des Tages, ebenfalls mit Gültigkeitscheck
  printf("Geben Sie einen Tag ein: \n");

  do{
    scanf(" %i", &day);

    if (day < 1 || day > gueltigeTage) {
      printf("Bitte gültigen Tag eingeben!\n");
    }
  }while(day < 1 || day > gueltigeTage);

  // for-Schleife um Monate zusammen zu rechnen
  for (int i = 0; i < month-1; i++) {
    tage = tage + tageProMonat[i];
  }

  // Tage des letzten Monats drauf rechnen
  tage = tage + day;

  // Ausgabe Ergebniss
  printf("Es ist der %i. Tag im Jahr!\n", tage);

  return 0;
}

// Funktion für die Bestimmung eines Schaltjahres
int leapYear (int y) {
  if (y % 4 == 0) {
    if (y % 100 == 0) {
      if (y % 400 == 0) {
        printf("Schaltjahr!\n");
        return 1;
      }else{
        printf("Kein Schaltjahr!\n");
        return 0;
      }
    }else{
      printf("Schaltjahr!\n");
      return 1;
    }
  }else{
    printf("Kein Schaltjahr!\n");
    return 0;
  }
}

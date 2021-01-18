/**
 * Gibt an der wie vielte Tag im Jahr es ist
 * Autor: Merlin Schmidt
 * Erstellt am: 11.01.2021
 * Zuletzt bearbeitet: 18.01.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

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

  // Bestimmung des Schaltjahres und ändern der Anzahl der Tage im Februar
  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {
        printf("Schaltjahr!\n");
        tageProMonat[1]++;
      }else{
        printf("Kein Schaltjahr!\n");
      }
    }else{
      printf("Schaltjahr!\n");
      tageProMonat[1]++;
    }
  }else{
    printf("Kein Schaltjahr!\n");
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

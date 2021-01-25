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

// Prüft nach Schaltjahr
int is_leapyear(int year);
// Funktion berechnet Tage eines gegeben Datums
int day_of_the_year(int day, int month, int year);
// Gibt Tage des Monats zurück
int get_days_for_month(int month, int year);
// Prüft Gültigkeit des eingegeben Datums
int exists_date(int day, int month, int year);
// User Inputs holen
void input_date(int *day, int *month, int *year);

/**
 * Main-Funktion
 **/
int main() {
  // Variablen die benötigt werden
  int year = 0, month = 0, day = 0;
  
  do {
    input_date(&day, &month, &year);
  }while(exists_date(day, month, year) != 1);

  // Ausgabe Ergebniss
  printf("Es ist der %i. Tag im Jahr!\n", day_of_the_year(day, month, year));

  return 0;
}

int exists_date(int day, int month, int year) {
  if (year > 2400 || year < 1582) {
    printf("Ungültiges Datum!\n");

    return 0;
  } else {

    return 1;
  }
}

void input_date(int *day, int *month, int *year) {
  int gueltige_tage = 0;

  printf("Geben Sie ein Jahr ein: \n")
  scanf(" %i", *year);

  printf("Geben Sie einen Monat ein: \n");
  do {
    scanf(" %i", *month);

    if (*month < 1 || *month > 12) {
      printf("Bitte gültigen Monat eingeben!\n");
    }
  }while(*month > 12 || *month < 1);

  // Variable um zu speichern wie viele Tage der Monat hat
  gueltigeTage = get_days_for_month(*month, *year);

  // Eingabe des Tages, ebenfalls mit Gültigkeitscheck
  printf("Geben Sie einen Tag ein: \n");

  do{
    scanf(" %i", &day);

    if (day < 1 || day > gueltigeTage) {
      printf("Bitte gültigen Tag eingeben!\n");
    }
  }while(day < 1 || day > gueltigeTage);
}

int day_of_the_year(int day, int month, int year) {
  int result = 0;

  for (int i = 0; i < month-1; i++) {
    result = result + get_days_for_month(i);
  }

  result = result + day;

  return result;
}

int get_days_for_month(int month, int year) {
  int tageProMonat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

  if (is_leapyear(year) == 1) {
    tageProMonat[1]++;
  }

  return tageProMonat[month-1];
}

// Funktion für die Bestimmung eines Schaltjahres
int is_leapyear (int year) {
  if (year < 1582) {
    printf("Ungültig!\n");
    return -1;
  }

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

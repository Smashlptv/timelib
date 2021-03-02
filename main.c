/**
 * Gibt an der wie vielte Tag im Jahr es ist
 * Autor: Merlin Schmidt
 * Erstellt am: 11.01.2021
 * Zuletzt bearbeitet: 15.02.2021
 **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "library.h"

/**
 * Main-Funktion
 **/
int main()
{
  // Initialisieren des Structs
  struct date date;
  date.year = 0;
  date.month = 0;
  date.day = 0;

  // Fordern der Inputs bis Gültigkeit
  do {
    input_date(&date.day, &date.month, &date.year);
  }while(exists_date(date) != 1);

  // Ausgabe Ergebniss
  printf("Es ist der %i. Tag im Jahr!\n", day_of_the_year(date));

  return 0;
}

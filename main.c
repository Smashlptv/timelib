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
#include "bib.h"

/**
 * Main-Funktion
 **/
int main()
{
  // Variablen die benötigt werden
  int year = 0, month = 0, day = 0;

  // Fordern der Inputs bis Gültigkeit
  do {
    input_date(&day, &month, &year);
  }while(exists_date(day, month, year) != 1);

  // Ausgabe Ergebniss
  printf("Es ist der %i. Tag im Jahr!\n", day_of_the_year(day, month, year));

  return 0;
}

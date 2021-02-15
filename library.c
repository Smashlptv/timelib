#include "library.h"

// Check ob das Datum legitim ist
int exists_date(int day, int month, int year)
{
  if (year > 2400 || year < 1582) {
    printf("Ungültiges Datum!\n");

    return 0;
  } else {

    return 1;
  }
}

// Inputs vom User anfordern
void input_date(int *day, int *month, int *year)
{
  // Variable um eingegebene Tage auf gültigkeit zu prüfen
  int gueltige_tage = 0;

  printf("Geben Sie ein Jahr ein: \n");
  scanf(" %i", year);

  printf("Geben Sie einen Monat ein: \n");
  do {
    scanf(" %i", month);

    if (*month < 1 || *month > 12) {
      printf("Bitte gültigen Monat eingeben!\n");
    }
  }while(*month > 12 || *month < 1);

  // Variable um zu speichern wie viele Tage der Monat hat
  gueltige_tage = get_days_for_month(*month, *year);

  // Eingabe des Tages, ebenfalls mit Gültigkeitscheck
  printf("Geben Sie einen Tag ein: \n");

  do{
    scanf(" %i", day);

    if (*day < 1 || *day > gueltige_tage) {
      printf("Bitte gültigen Tag eingeben!\n");
    }
  }while(*day < 1 || *day > gueltige_tage);
}

// Berechnung der Tage die schon vergangen sind
int day_of_the_year(int day, int month, int year)
{
  int result = 0;

  for (int i = 1; i < month; i++) {
    result = result + get_days_for_month(i, year);
  }

  result = result + day;

  return result;
}

// Gibt die Tage des Monats unter Berücksichtigung des Schaltjahres aus
int get_days_for_month(int month, int year)
{
  int tageProMonat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

  if (is_leapyear(year) == 1) {
    tageProMonat[1]++;
  }

  return tageProMonat[month-1];
}

// Funktion für die Bestimmung eines Schaltjahres
int is_leapyear (int year)
{
  if (year < 1582) {
    printf("Ungültig!\n");
    return -1;
  }

  if (year % 4 == 0) {
    if (year % 100 == 0) {
      if (year % 400 == 0) {

        return 1;
      }else{

        return 0;
      }
    }else{

      return 1;
    }
  }else{

    return 0;
  }
}

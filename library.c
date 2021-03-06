#include "library.h"

// Check ob das Datum legitim ist
int exists_date(struct date date)
{
  if (date.year > 2400 || date.year < 1582) {
    printf("Ung�ltiges Datum!\n");

    return 0;
  } else {

    return 1;
  }
}

// Inputs vom User anfordern
void input_date(int *day, int *month, int *year)
{
  // Variable um eingegebene Tage auf g�ltigkeit zu pr�fen
  int possible_days = 0;

  printf("Geben Sie ein Jahr ein: \n");
  scanf(" %i", year);

  printf("Geben Sie einen Monat ein: \n");
  do {
    scanf(" %i", month);

    if (*month < 1 || *month > 12) {
      printf("Bitte g�ltigen Monat eingeben!\n");
    }
  }while(*month > 12 || *month < 1);

  // Variable um zu speichern wie viele Tage der Monat hat
  possible_days = get_days_for_month(*month, *year);

  // Eingabe des Tages, ebenfalls mit G�ltigkeitscheck
  printf("Geben Sie einen Tag ein: \n");

  do{
    scanf(" %i", day);

    if (*day < 1 || *day > possible_days) {
      printf("Bitte g�ltigen Tag eingeben!\n");
    }
  }while(*day < 1 || *day > possible_days);
}

// Berechnung der Tage die schon vergangen sind
int day_of_the_year(struct date date)
{
  int result = 0;

  for (int i = 1; i < date.month; i++) {
    result = result + get_days_for_month(i, date.year);
  }

  result = result + date.day;

  return result;
}

// Gibt die Tage des Monats unter Ber�cksichtigung des Schaltjahres aus
int get_days_for_month(int month, int year)
{
  int days_per_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

  if (is_leapyear(year) == 1) {
    days_per_month[1]++;
  }

  return days_per_month[month-1];
}

// Funktion f�r die Bestimmung eines Schaltjahres
int is_leapyear (int year)
{
  if (year < 1582) {
    printf("Ung�ltig!\n");
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

#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

// Pr�ft nach Schaltjahr
int is_leapyear(int year);
// Funktion berechnet Tage eines gegeben Datums
int day_of_the_year(int day, int month, int year);
// Gibt Tage des Monats zur�ck
int get_days_for_month(int month, int year);
// Pr�ft G�ltigkeit des eingegeben Datums
int exists_date(int day, int month, int year);
// User Inputs holen
void input_date(int *day, int *month, int *year);

#endif // LIBRARY_H_INCLUDED

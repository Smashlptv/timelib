#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

struct date{
    int day;
    int month;
    int year;
};

// Pr�ft nach Schaltjahr
int is_leapyear(int year);
// Funktion berechnet Tage eines gegeben Datums
int day_of_the_year(struct date);
// Gibt Tage des Monats zur�ck
int get_days_for_month(int month, int year);
// Pr�ft G�ltigkeit des eingegeben Datums
int exists_date(struct date);
// User Inputs holen
void input_date(int *day, int *month, int *year);

#endif // LIBRARY_H_INCLUDED

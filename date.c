#include "date.h"
#include <stdio.h>  // For sprintf

// Function to check if a given date is valid
int EstValide(const struct sDate date) {
    if (date.mois < 1 || date.mois > 12 || date.heure > 23 || date.minute > 59) {
        return 0;
    }

    int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Adjust for leap year
    if ((date.annee % 4 == 0 && date.annee % 100 != 0) || (date.annee % 400 == 0)) {
        days_in_month[1] = 29;
    }

    if (date.jour < 1 || date.jour > days_in_month[date.mois - 1]) {
        return 0;
    }

    return 1;
}

// Function to compare two dates
int Compare(const struct sDate reference, const struct sDate autreDate) {
    if (reference.annee != autreDate.annee) {
        return reference.annee - autreDate.annee;
    }
    if (reference.mois != autreDate.mois) {
        return reference.mois - autreDate.mois;
    }
    if (reference.jour != autreDate.jour) {
        return reference.jour - autreDate.jour;
    }
    if (reference.heure != autreDate.heure) {
        return reference.heure - autreDate.heure;
    }
    return reference.minute - autreDate.minute;
}

// Function to check if a date is within an interval
int Appartient(const struct sDate date, const struct sDate debut, const struct sDate fin) {
    return (Compare(date, debut) >= 0 && Compare(date, fin) <= 0) ? 1 : 0;
}

// Function to check if two intervals overlap
int Chevauche(const struct sDate debut1, const struct sDate fin1, const struct sDate debut2, const struct sDate fin2) {
    return (Appartient(debut1, debut2, fin2) || Appartient(debut2, debut1, fin1)) ? 1 : 0;
}

// Function to convert date to YYYYMMDDTHHMM format
void YYYYMMDDTHHMM(char* destination, const struct sDate date) {
    sprintf(destination, "%04u%02u%02uT%02u%02u",
            date.annee, date.mois, date.jour, date.heure, date.minute);
}

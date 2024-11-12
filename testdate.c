#include <stdio.h>
#include "date.h"

void testEstValide() {
    struct sDate validDate = {2024, 2, 29, 12, 30};  // Leap year
    struct sDate invalidDate = {2023, 2, 29, 12, 30}; // Non-leap year

    printf("Testing EstValide:\n");
    printf("Valid Date (2024-02-29): %d\n", EstValide(validDate));
    printf("Invalid Date (2023-02-29): %d\n", EstValide(invalidDate));
}

void testCompare() {
    struct sDate date1 = {2024, 5, 10, 10, 30};
    struct sDate date2 = {2024, 5, 10, 10, 30};
    struct sDate date3 = {2023, 12, 31, 23, 59};

    printf("\nTesting Compare:\n");
    printf("Compare date1 and date2 (same): %d\n", Compare(date1, date2)); // Should be 0
    printf("Compare date1 and date3 (date1 > date3): %d\n", Compare(date1, date3)); // Should be positive
    printf("Compare date3 and date1 (date3 < date1): %d\n", Compare(date3, date1)); // Should be negative
}

void testAppartient() {
    struct sDate date = {2024, 5, 15, 10, 30};
    struct sDate start = {2024, 5, 1, 0, 0};
    struct sDate end = {2024, 5, 31, 23, 59};

    printf("\nTesting Appartient:\n");
    printf("Date within range: %d\n", Appartient(date, start, end)); // Should be 1
    printf("Date out of range: %d\n", Appartient((struct sDate){2024, 6, 1, 0, 0}, start, end)); // Should be 0
}

void testChevauche() {
    struct sDate start1 = {2024, 5, 1, 0, 0};
    struct sDate end1 = {2024, 5, 10, 23, 59};
    struct sDate start2 = {2024, 5, 5, 0, 0};
    struct sDate end2 = {2024, 5, 15, 23, 59};

    printf("\nTesting Chevauche:\n");
    printf("Intervals overlap: %d\n", Chevauche(start1, end1, start2, end2)); // Should be 1
    printf("Intervals do not overlap: %d\n", Chevauche((struct sDate){2024, 5, 11, 0, 0}, (struct sDate){2024, 5, 15, 23, 59}, start1, end1)); // Should be 0
}

void testYYYYMMDDTHHMM() {
    struct sDate date = {2024, 12, 31, 23, 59};
    char formattedDate[14];  // Ensure we allocate 14 characters for "YYYYMMDDTHHMM\0"

    YYYYMMDDTHHMM(formattedDate, date);

    printf("\nTesting YYYYMMDDTHHMM:\n");
    printf("Formatted date: %s\n", formattedDate); // Should output "20241231T2359"
}

int main() {
    testEstValide();
    testCompare();
    testAppartient();
    testChevauche();
    testYYYYMMDDTHHMM();
    return 0;
}

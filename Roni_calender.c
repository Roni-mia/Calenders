#include <stdio.h>

int firstDayOfYear(int year) {
    int month = 1;
    int day = 1;

    if (month < 3) {
        month += 12;
        year--;
    }

    int h = (day + 13 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return h;
}

int main() {
    char *months[] = {" January ", "February ", " March ", " April ", " May ", " June ", " July ", " August ", " September", " October ", " November", " December "};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i, d, totalDays, weekDay, space = 0, year;

    printf("Enter your favorite year:\n");
    scanf("%d", &year);
    printf("\n\n********** Welcome to %d ********\n", year);

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        daysInMonth[1] = 29;
    }

    weekDay = firstDayOfYear(year);

    for (i = 0; i < 12; i++) {
        printf("\n ==================== %s ====================", months[i]);
        printf("\n ---------------------------------------------------\n");
        printf("\n Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n");

        for (space = 0; space < weekDay; space++) {
            printf("     ");
        }

        totalDays = daysInMonth[i];

        for (d = 1; d <= totalDays; d++) {
            printf("%-5d", d);
            weekDay++;

            if (weekDay > 6) {
                weekDay = 0;
                printf("\n");
            }
        }

        printf("\n");
    }

    return 0;
}

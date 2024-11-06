#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int main() {
    do {
        clearScreen();

        int day = 0, month = 0, year = 0;
        int n = 0, dayOfWeek = 0;

        printf("This program determines the day of the week based on the date you provide. Your input must be an integer\n");

        printf("Day [1, 31] :\n");
        do {
            scanf(" %d", &day);

            if (day < 1 || day > 31) {
                printf("Invalid input. Please follow the instructions and try again.\n");
                fflush(stdin);
            }
        } while (day < 1 || day > 31);

        printf("Month [1, 12] :\n");
        
        do {
            scanf(" %d", &month);

            if (month < 1 || month > 12) {
                printf("Invalid input. Please follow the instructions and try again.\n");
                fflush(stdin);
            }
        } while (month < 1 || month > 12);

        printf("Year [1900, 2099] :\n");
        do {
            scanf(" %d", &year);

            if (year < 1900 || year > 2099) {
                printf("Invalid input. Please follow the instructions and try again.\n");
                fflush(stdin);
            }
        } while (year < 1900 || year > 2099);

        if (month > 2) {
            n = 0;
        } else if (isLeapYear(year) && month < 3) {
            n = 1;
        } else {
            n = 2;
        }

        int p1 = 365.25 * year;
        int p2 = 30.56 * month;
        dayOfWeek = (p1 + p2 + day + n) % 7;

        const char* weekDays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

        printf("The day of the week is: %s\n", weekDays[dayOfWeek]);

        printf ("Press ENTER to continue, any key to EXIT...\n");
    } while (getch()==13);

    return 0;
}
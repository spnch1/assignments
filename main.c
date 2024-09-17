#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include "./include/functions.h"

int main(void) {
    unsigned char DP=0; //Decimal Places
    double a=0, b=0, c=0; //Sides of the triangle
    double P=0, p=0, S=0, ha=0, hb=0, hc=0, ma=0, mb=0, mc=0, ba=0, bb=0, bc=0; //Perimeter, half-perimeter, area, heights drawn to side N, medians drawn to side N, bisectors drawn to side N
    char choice = 0;

    printf("The program calculates the perimeter, area, heights, medians and bisectors of the given triangle.\n");
    printf("Please enter values of the triangle's sides. The accepted range is [0.001, 1000].\n");

    do {
        a = b = c = 0;
        DP = 0;
        choice = 0;

        while (a + b <= c || a + c <= b || b + c <= a) {
            fflush(stdin);
            printf("\n1st value:\n");
            while (scanf(" %lf", &a) != 1 || a < 0.001 || a > 1000) {
                printf("Invalid input. Please try again...\n");
                fflush(stdin);
            }

            printf("\n2nd value:\n");
            while (scanf(" %lf", &b) != 1 || b < 0.001 || b > 1000) {
                printf("Invalid input. Please try again...\n");
                fflush(stdin);
            }

            printf("\n3rd value:\n");
            while (scanf(" %lf", &c) != 1 || c < 0.001 || c > 1000) {
                printf("Invalid input. Please try again...\n");
                fflush(stdin);
            }

            if (a + b <= c || a + c <= b || b + c <= a) {
                printf("\nInvalid input. These sides do not form a triangle. Press press Enter to try again...\n");
                fflush(stdin);
                getch();
            }
        }

        printf("\nNow enter the number of decimal points [0,12] for the results:\n");

        while (scanf(" %hhu", &DP) != 1 || DP < 0 || DP > 12) {
            printf("\nInvalid input. Please try again...\n");
            fflush(stdin);
        }

        P = a+b+c;
        p = P/2;

        S = sqrt(p*(p-a)*(p-b)*(p-c));

        ha = 2*S/a;
        hb = 2*S/b;
        hc = 2*S/c;

        ma = sqrt(2*b*b+2*c*c-a*a)/2;
        mb = sqrt(2*a*a+2*c*c-b*b)/2;
        mc = sqrt(2*a*a+2*b*b-c*c)/2;

        ba = 2/(b+c)*sqrt(b*c*p*(p-a));
        bb = 2/(a+c)*sqrt(a*c*p*(p-b));
        bc = 2/(a+b)*sqrt(a*b*p*(p-c));

        printf("\nArea of the triangle: %.*lf", DP, S);
        printf("\nPerimeter of the triangle: %.*lf", DP, P);
        printf("\nHeights drawn to the sides a, b, c respectively: %.*lf, %.*lf, %.*lf", DP, ha, DP, hb, DP, hc);
        printf("\nMedians drawn to the sides a, b, c respectively: %.*lf, %.*lf, %.*lf", DP, ma, DP, mb, DP, mc);
        printf("\nBisectors drawn to the sides a, b, c respectively: %.*lf, %.*lf, %.*lf", DP, ba, DP, bb, DP, bc);

        fflush(stdin);

        printf("\n\nRestart the program? [Y/N]\n");

        while (choice == 0) {
            choice = getchar();
            choice = tolower(choice);
            if (choice == 'y' || choice == 'n') {
                break;
            }
            printf("Invalid input. Please enter Y or N.\n");
            fflush(stdin);
        }

        if (choice == 'n') {
            break;
        }

        clearScreen();

        printf("\n");
        fflush(stdin);

    } while (choice == 'y');

    return 0;
}
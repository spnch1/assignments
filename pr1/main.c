#include <stdio.h>
#include <conio.h>

int roman (int, int, char);

int main() {
    int unsigned a;
    printf("Enter a number: \n");
    scanf("%d", &a);

    if (a<1 || a>4999) {
        printf("Invalid Input. Press Enter to exit...\n");
        getch();
        return 1;
    }

    a = roman(a, 1000, 'M');
    a = roman(a, 500, 'D');
    a = roman(a, 100, 'C');
    a = roman(a, 50, 'L');
    a = roman(a, 10, 'X');
    a = roman(a, 5, 'V');
    a = roman(a, 1, 'I');

    printf("\nPress Enter to exit...\n");
    getch();

    return 0;
}

int roman(int i, int j, char c) {
    while  (i >= j) {
        putchar(c);
        i=i-j;
    }
    return i;
}
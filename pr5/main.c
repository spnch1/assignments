#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#include "functions.h"

int main() {
    srand(time(NULL));
    printf("This program sorts strings. A string can only contain English letters. Have fun!\n\n");

    do {
        int n = 0, max_len = 0, choice_method = 0, choice_sorting = 0;

        n = get_int("Enter the amount of strings [2, 999]: ", 2, 999);
        max_len = get_int("Enter the max string length [2, 100]: ", 2, 100);

        char arr[n][max_len + 1];
        char *arr_addr[n];

        for (int i = 0; i < n; i++) {
            arr_addr[i] = arr[i];
        }

        choice_method = get_choice("\nArray filling method (1 - by hand, 2 - random):\n", '1', '2');
        fflush(stdin);

        switch (choice_method) {
            case '1':
                printf("\n--- INPUT:\n");
                get_str(arr_addr, n, max_len);
                break;
            case '2':
                get_random_str(arr_addr, n, max_len);
                printf("\n--- INPUT:\n");
                print_str(arr_addr, n);
                break;
            default:
                break;
        }

        choice_sorting = get_choice("\nSorting type (1 - ascending, 2 - descending):\n", '1', '2');

        switch (choice_sorting) {
            case '1':
                bubble_sort_asc(arr_addr, n);
                break;
            case '2':
                bubble_sort_desc(arr_addr, n);
                break;
            default:
                break;
        }

        printf("\n--- OUTPUT:\n");
        print_str(arr_addr, n);

        printf("\nPress Enter to restart, any key to exit...");
    } while (getch() == 13 && (clear_screen(), 1));

    return 0;
}
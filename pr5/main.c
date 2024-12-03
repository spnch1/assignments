#include <stdio.h>
#include <conio.h>
#include <string.h>

#define N_STR 50
#define STR_SIZE 100

void bubble_sort(char *addr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j; j < n - i - 1; j++) {
            if (strcmp(addr[i], addr[j]) > 0) {
                char *t = addr[i];
                addr[i] = addr[j];
                addr[j] = t;
            }
        }
    }
}

int main() {
    do {
        char list[N_STR][STR_SIZE];
        char *addr[N_STR];

        int n;

        printf("Please enter the amount of strings [1,50]:\n");
        while (scanf("%d", &n) != 1) {
            printf("The accepted range is 1 to 50. Please try again:\n");
            fflush(stdin);
        }

        printf("Please enter the strings:\n");
        for (int i = 0; i < n + 1; i++) {
            fgets(list, STR_SIZE, stdin);
            list[i][strcspn(list, "\n")] = '\0';
            addr[i] = list[i];
            fflush(stdin);
        }

        bubble_sort(addr, n);

        printf("Sorted strings:\n");
        for (int i = 0; i < n + 1; i++) {
            puts(addr[i]);
        }
        fflush(stdin);

        printf("Press Enter to restart, any key to exit...");
    } while (getch() == 13);

    return 0;
}
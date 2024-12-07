#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "functions.h"

// SORTING

void bubble_sort_asc(char *addr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(addr[i], addr[j]) > 0) {
                char *temp = addr[i];
                addr[i] = addr[j];
                addr[j] = temp;
            }
        }
    }
}

void bubble_sort_desc(char *addr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(addr[i], addr[j]) < 0) {
                char *temp = addr[i];
                addr[i] = addr[j];
                addr[j] = temp;
            }
        }
    }
}

// INPUT // VALIDATION

int get_int(char *str, int min, int max) {
    int value = 0, entered_value = 0;

    printf("%s", str);
    do {
        entered_value = scanf("%d", &value);

        if (entered_value != 1 || value < min || value > max) {
            printf("Invalid input. Try again...\n");
            fflush(stdin);
        }
    } while (entered_value != 1 || value < min || value > max);

    return value;
}

int get_choice(char *str, int choice_1, int choice_2) {
    int value = 0;
    printf("%s", str);

    do {
        value = getch();
        if (value != choice_1 && value != choice_2) {
            printf("Invalid input. Try again...\n");
            fflush(stdin);
        }
    } while (value != choice_1 && value != choice_2);

    return value;
}

void get_str(char **str, int n, int max_len) {
    for (int i = 0; i < n; i++) {
        do {
            printf("[%02d] => ", i + 1);
            if (fgets(str[i], max_len + 2, stdin)) {
                size_t len = strlen(str[i]);
                if (len > 0 && str[i][len - 1] == '\n') {
                    str[i][len - 1] = '\0';
                } else {
                    fflush(stdin);
                }
            } else {
                str[i][0] = '\0';
            }
        } while (!isvalid_str(str[i], max_len));
    }
}

int isvalid_str(const char *str, int max_len) {
    size_t str_len = strlen(str);

    if (str_len > max_len) {
        printf("Invalid input: Max length exceeded. Try again...\n");
        return 0;
    }
    if (str_len == 0 || *str == '\n') {
        printf("Invalid input: Empty string. Try again...\n");
        return 0;
    }
    for (size_t i = 0; i < str_len; i++) {
        if (!isalpha(str[i])) {
            printf("Invalid input: The string should only consist of English letters. Try again...\n");
            return 0;
        }
    }

    return 1;
}

char get_random_char(void) {
    int is_uppercase = rand() % 2;
    return is_uppercase ? 'A' + rand() % 26 : 'a' + rand() % 26;
}

void get_random_str(char **str, int n, int max_len) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < max_len; j++) {
            str[i][j] = get_random_char();
        }
        str[i][max_len] = '\0';
    }
}

// OUTPUT

void print_str(char **str, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%02d] => %s\n", i + 1, str[i]);
    }
}

// CLEAR SCREEN

void clear_screen(void) {
#ifdef _WIN32
    system("cls");
#elifdef __unix__
    system("clear");
#endif
}
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void bubble_sort_asc(char *addr[], int n);
void bubble_sort_desc(char *addr[], int n);

int get_int(char *str, int min, int max);
int get_choice(char *str, int choice_1, int choice_2);
void get_str(char **str, int n, int max_len);
int isvalid_str(const char *str, int max_len);
char get_random_char(void);
void get_random_str(char **str, int n, int max_len);

void print_str(char **str, int max_len);

void clear_screen(void);

#endif

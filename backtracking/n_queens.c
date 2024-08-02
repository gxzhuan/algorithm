#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 10
#define QUEEN '@'
#define BLACK '#'


int is_vaild(char** buffer, int ii, int step, int n) {
    if (step == 0)
        return 1;
    for (int i = 0; i <= step; i++) {
        if (*(*(buffer + i) + ii) == QUEEN)
            return 0;
    }
    for (int i = 1; (ii - i >= 0) && (step - i >= 0); i++) {
        if (*(*(buffer + step - i) + ii - i) == QUEEN)
            return 0;
    }
    for (int i = 1; (step - i >= 0) && (ii + i < n); i++) {
        if (*(*(buffer + step - i) + ii + i) == QUEEN)
            return 0;
    }

    return 1;
}

void print_buffer(char** buffer, int n) {
    static int count = 1;
    printf("case %d:\n", count++);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        printf("%c", *(*(buffer + i) + j));
        printf("\n");
    }

    return;
}

void backtracking(char** buffer, int step, int n) {
    if (step == n) {
        print_buffer(buffer, step);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!is_vaild(buffer, i, step, n)) {
            *(*(buffer + step) + i) = BLACK;
            continue;
        }
        *(*(buffer + step) + i) = QUEEN;
        backtracking(buffer, step + 1, n);
        *(*(buffer + step) + i) = BLACK;
    }
    return;
}

int main(void) {
    char** buffer;
    buffer = (char**)malloc(sizeof(char*) * LEN);
    for (int i = 0; i < LEN; i++) {
        *(buffer + i) = (char*)malloc(sizeof(char) * LEN);
        memset(*(buffer + i), BLACK, LEN);
    }
    int n = 9;
    backtracking(buffer, 0, n);

    for (int i = 0; i < LEN; i++) {
        free(*(buffer + i));
    }
    free(buffer);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 10

int is_panlindrome(char* string, int start, int end) {
    for (int i = 0; i <= (end - start + 1) / 2; i++) {
        if (!(string[start + i] == string[end - i]))
            return 0;
    }
    return 1;
}

void print_buffer(char** buffer, int len) {
    for (int i = 0; i < len; i++)
        printf("%s ", *(buffer + i));
    printf("\n");
}

void backtracking(char* string, int len, char** buffer, int start_index, int step) {
    if (start_index == len) {
        print_buffer(buffer, step);
        return;
    }

    for (int i = start_index; i < len; i++) {
        if (!is_panlindrome(string, start_index, i))
            continue;
        // memcpy(*(buffer + step), string + i, i - start_index + 1);
        memcpy(*(buffer + step), string + start_index, i - start_index + 1);
        backtracking(string, len, buffer, i + 1, step + 1);
        memset(*(buffer + step), 0, LEN);
    }
    return;
}

int main(void) {
    char* string = "aabccbaa";
    char** buffer;
    buffer = (char**)malloc(sizeof(char*) * LEN);
    for (int i = 0; i < LEN; i++)
        *(buffer + i) = (char*)malloc(sizeof(char) * LEN);
    int len = 6;
    backtracking(string, len, buffer, 0, 0);

    for (int i = 0; i < LEN; i++) {
        free(*(buffer + i));
    }
    free(buffer);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 10
#define LEFT '('
#define RIGHT ')'
#define BALCK ' '

void print_buffer(char* buffer, int start_index, int ii) {
    for (int i = 0; i < 2 *(ii + 1); i++) {
        printf("%c", *(buffer + i));
    }
    printf("\n");

    return;
}

void push_buffer(char* buffer, int start_index, int ii) {
    int index = 2 * start_index;
    for (; index < 2 * start_index + (ii  - start_index + 1); index++) {
        buffer[index] = LEFT;
    }
    for (; index < 2 * (ii + 1); index++) {
        buffer[index] = RIGHT;
    }
}

void pop_buffer(char* buffer, int start_index, int ii) {
    int index = 2 * start_index;
    for (; index < 2 *(ii + 1); index++) {
        buffer[index] = BALCK;
    }
}

void backtracking(char* buffer, int start_index, int step, int n) {
    if (step == n) {
        return;
    }

    for (int i = start_index; i < n; i++) {
        push_buffer(buffer, start_index, i);
        print_buffer(buffer, start_index, i);
        backtracking(buffer, i + 1, step + 1, n);
        // pop_buffer(buffer, start_index, i);
    }
    return;
}

int main(void) {
    char* buffer;
    buffer = (char*)malloc(sizeof(char) * 2 * LEN);
    int n = 5;
    backtracking(buffer, 0, 0, n);

    free(buffer);
    return 0;
}

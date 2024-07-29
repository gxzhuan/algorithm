#include <stdio.h>
#include <string.h>

#define LEN 10

int backtracking(char* string, int len, char* buffer, int* selected, int step) {
    if (step == len) {
        for (int i = 0; i < len; i++)
            printf("%c ", buffer[i]);
        printf("\n");
    }

    for (int i = 0; i < len; i++) {
        if (selected[i] == 1)
            continue;
        buffer[step] = string[i];
        selected[i] = 1;
        backtracking(string, len, buffer, selected, step + 1);
        selected[i] = 0;
    }

    return 0;
}

int main(void) {
    char* string = "ABCDEFGHIJKLMN";
    int   status[LEN] = {0};
    char  res[LEN];
    memset(res, ' ', LEN);
    int len = 3;
    backtracking(string, len, res, status, 0);
    return 0;
}

#include <stdio.h>
#include <string.h>

#define LEN 10

int backtracking(char* string, int len, char* buffer, int start_index, int step, int num) {
    if (step == num) {
        for (int i = 0; i < num; i++)
            printf("%c ", buffer[i]);
        printf("\n");
    }

    for (int i = start_index; i < len; i++) {
        buffer[step] = string[i];
        backtracking(string, len, buffer, i + 1, step + 1, num);
    }

    return 0;
}

int main(void) {
    char* string = "ABCDEFGHIJKLMN";
    int   status[LEN] = {0};
    char  res[LEN];
    memset(res, ' ', LEN);
    int len = 4;
    int num = 2;
    backtracking(string, len, res, 0, 0, num);
    return 0;
}

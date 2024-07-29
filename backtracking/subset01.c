#include <stdio.h>
#include <string.h>

#define LEN 10

int backtracking(char* string, int len, char* buffer, int start_index, int step) {
    if (step == len)
        return 0;

    for (int i = start_index; i < len; i++) {
        buffer[step] = string[i];
        for (int j = 0; j <= step; j++) {
            printf("%c ", buffer[j]);
        }
        printf("\n");
        backtracking(string, len, buffer, i + 1, step + 1);
    }

    return 0;
}

int main(void) {
    char* string = "ABCDEFGHIJKLMN";
    int   status[LEN] = {0};
    char  res[LEN];
    memset(res, ' ', LEN);
    int len = 4;
    backtracking(string, len, res, 0, 0);
    return 0;
}

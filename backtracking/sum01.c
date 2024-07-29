#include <stdio.h>
#include <string.h>

#define LEN 10
int sum = 0;

int calculate_sum(int* array, int len) {
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += array[i];

    return sum;
}

void print_result(int* array, int len) {
    printf("%3d = ", sum);
    for (int i = 0; i < len; i++) {
        if (i == 0) {
            printf("%2d ", array[i]);
            continue;
        }
        printf("+ %2d ", array[i]);
    }
    printf("\n");

    return;
}

int backtracking(int* array, int len, int* buffer, int start_index, int step) {
    if (step == len)
        return 0;

    for (int i = start_index; i < len; i++) {
        buffer[step] = array[i];
        if (calculate_sum(buffer, step + 1) == sum) {
            print_result(buffer, step + 1);
        }
        backtracking(array, len, buffer, i + 1, step + 1);
    }

    return 0;
}

int main(void) {
    int arr[LEN];
    for (int i = 0; i < LEN; i++)
        arr[i] = i + 1;
    int  res[LEN];
    memset(res, 0, LEN);
    int len = LEN;
    sum = 45;
    backtracking(arr, len, res, 0, 0);
    return 0;
}

## 回溯

#### 全排列

1. 对于集合`{A, B, C}`, 求其全排列

```c
// permutation01.c
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
```

2. 对于集合`{A, B, C, D}`, 从中选取3个元素，求其全排列

```c
// permutation02.c
#include <stdio.h>
#include <string.h>

#define LEN 10

int backtracking(char* string, int len, char* buffer, int* selected, int step, int num) {
    if (step == num) {
        for (int i = 0; i < num; i++)
            printf("%c ", buffer[i]);
        printf("\n");
    }

    for (int i = 0; i < len; i++) {
        if (selected[i] == 1)
            continue;
        buffer[step] = string[i];
        selected[i] = 1;
        backtracking(string, len, buffer, selected, step + 1, num);
        selected[i] = 0;
    }

    return 0;
}

int main(void) {
    char* string = "ABCDEFGHIJKLMN";
    int   status[LEN] = {0};
    char  res[LEN];
    memset(res, ' ', LEN);
    int len = 4; // 总共4个元素
    int num = 3; // 选取3个
    backtracking(string, len, res, status, 0, num);
    return 0;
}
```

#### 组合

1. 对于集合`{A, B, C, D}`, 从中选取2个元素组合

```c
// combination01.c
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
        // 这儿的start_index应该是i + 1，因为第i个元素被选择之后就不能选择了，
        // 只能向后选择
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
```

2. 对于集合`{A, B, C, D}`, 求其子集

```c
// subset01.c
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
```

#### 求和

1. 对于给定的集合`A = {1, ... , N}`, 从中选取`k (0 <= k <= len(A))`个元素，使他们的和为`sum`, 求出所有的可能

```c
// sum01.c
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
```

#### 分割回文字符串

1. 对于给定的字符串，将它进行切割，使得每一个子串都是回文串，比如`aabccb`可以分割成下列的回文串：

`a a b c c b`

`a a b cc b`

`a a bccb`

`aa b c c b`

`aa b cc b`

`aa bccb`

```c
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
        // 这里应该拷贝start_index到i
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
```

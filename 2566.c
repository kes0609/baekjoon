/* Data Structure Assignment1 01, Baekjoon 2566 */
/* Eunsuh Kim, Korea University Data Science 24 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    int m, n, max;
    int i, j;
    int arr[9][9];

    /* Get the numbers in the 9*9 grid */
    for (i = 0;i < 9;i++) {
        for (j = 0;j < 9;j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    m = 0, n = 0;
    max = arr[0][0]; // let the max value the first number

    for (i = 0;i < 9;i++) {
        for (j = 0;j < 9;j++) {
            if (arr[i][j] > max) { // if the number is bigger than max, update max and the index
                max = arr[i][j];
                m = i, n = j;
            }
        }
    }
    printf("%d\n%d %d", max, m + 1, n + 1);
    return 0;
}
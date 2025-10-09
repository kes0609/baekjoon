/* baekjoon 6550*/
/* Ensuh Kim, Korea University Data Science 24 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) { 
    char* s = (char*)malloc(1000005);
    char *t = (char*)malloc(1000005);

    while (scanf("%s %s", s, t)==2) {
        int i = 0, j = 0;
        int ns = (int)strlen(s), nt = (int)strlen(t);

        /* t의 처음부터 차례대로 비교 */
        while (i < nt && j < ns) {
            if (t[i] == s[j]) j++;
            i++;
        }

        puts((j == ns) ? "Yes" : "No");
    }
    free(s);
    free(t);
     
    return 0;
}

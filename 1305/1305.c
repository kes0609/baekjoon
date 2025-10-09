/* Baekjoon 1305 */
/* Eunsuh KIm, Korea University Data Science 24 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAXN 1000005

char s[MAXN];
int failure[MAXN];

/* LPS의 마지막 index 구하기 */
void build_failure(const char* pat, int n) {
    failure[0] = -1;
    for (int j = 1; j < n; j++) {
        int i = failure[j - 1];
        while (i >= 0 && pat[j] != pat[i + 1]) i = failure[i];
        if (pat[j] == pat[i + 1]) failure[j] = i + 1;
        else failure[j] = -1;
    }
}

int main(void) {
    int L;
    if (scanf("%d", &L) != 1) return 0;
    if (scanf("%1000004s", s) != 1) return 0;

    build_failure(s, L);

    int border_len = failure[L - 1] + 1; // 겹치는 prefix=suffix 길이
    int ans = L - border_len;            // 최소 광고 길이 = 전체길이-겹치는길이
    printf("%d\n", ans);
    return 0;
}

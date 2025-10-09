/* Baekjoon 11585 */
/* Eunsuh Kim, Korea University Data Science 24 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAXN 1000000
/* B를 두 번 이어붙인 문자열에서 A를 찾음 (마지막 한 글자 중복 제외) */
static char A[MAXN + 5];          
static char B[MAXN + 5];          
static char T[2 * MAXN + 5];       
static int  failure[MAXN + 5];

/* failure[j] = p[0..j]의 LPS의 마지막 index (없으면 - 1) */
void build_failure(const char* p, int n) {
    failure[0] = -1;
    for (int j = 1; j < n; j++) {
        int i = failure[j - 1];
        while (i >= 0 && p[j] != p[i + 1]) i = failure[i];
        if (p[j] == p[i + 1]) failure[j] = i + 1;
        else failure[j] = -1;
    }
}

/* 모든 매칭 개수 탐색 */
int kmp_count(const char* s, int ns, const char* p, int np) {
    int i = 0, j = 0, cnt = 0;
    while (i < ns) {
        if (s[i] == p[j]) {
            i++; j++;
            if (j == np) {
                cnt++;
                j = (failure[np - 1] >= 0) ? failure[np - 1] + 1 : 0; // 다음 매칭 계속
            }
        }
        else if (j == 0) {
            i++;
        }
        else {
            j = failure[j - 1] + 1;
        }
    }
    return cnt;
}

int gcd(int a, int b) { while (b) { int r = a % b; a = b; b = r; } return a; }

int main(void) {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %c", &A[i]);
    }

    for (int i = 0; i < N;i++) {
        scanf(" %c", &B[i]);
    }

    /* B + B에서 마지막 1글자 제거 */
    for (int i = 0; i < N; i++) T[i] = B[i];
    for (int i = 0;i < N - 1;i++) T[N + i] = B[i];
    int lenT = 2 * N - 1;

    build_failure(A, N);
    int match = kmp_count(T, lenT, A, N);

    /* 최대공약수로 나누어 기약분수 형태로 만든다. */
    int g = gcd(match, N);
    printf("%d/%d\n", match / g, N / g);
    return 0;
}

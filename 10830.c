#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 5

void MatrixMultiply(long long x[][MAX_SIZE], long long y[][MAX_SIZE], long long int n);

int main() {
	long long int N;
	long long int b;
	long long int a[MAX_SIZE][MAX_SIZE];
	long long int ans[MAX_SIZE][MAX_SIZE] = { 0 };  // 정답 행렬을 모두 0으로 초기화해 준다. 

	scanf("%lld %lld", &N,&b);

	/* 행렬 a의 값들 입력받은 후 저장 */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%lld", &a[i][j]);
		}
		ans[i][i] = 1;  // 정답 행렬을 단위행렬로 만든다.
	}

	while (b > 0) {
		/* b가 홀수이면 정답 행렬에 a행렬을 추가로 한번 곱해준다. */
		if (b % 2 == 1) {
			MatrixMultiply(ans, a, N);
		}
		/* b가 짝수이므로 a행렬을 제곱해준 후, b는 2로 나눠준다. */
		MatrixMultiply(a, a, N);
		b /= 2;
	}

	/* 만들어진 정답 행렬을 출력한다. */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%lld ", ans[i][j]);
		}
		printf("\n");
	}
}

void MatrixMultiply(long long x[][MAX_SIZE], long long y[][MAX_SIZE], long long int n) {
	long long int temp[MAX_SIZE][MAX_SIZE];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			long long sum = 0;
			/* 행렬 곱셈, mod계산 */
			for (int k = 0;k < n;k++) {
				sum += ((x[i][k]) * (y[k][j]))%1000;
			}
			temp[i][j] = (sum %= 1000);
		}
	}

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			x[i][j] = temp[i][j];
		}
	}

}
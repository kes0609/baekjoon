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
	long long int ans[MAX_SIZE][MAX_SIZE] = { 0 };  // ���� ����� ��� 0���� �ʱ�ȭ�� �ش�. 

	scanf("%lld %lld", &N,&b);

	/* ��� a�� ���� �Է¹��� �� ���� */
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%lld", &a[i][j]);
		}
		ans[i][i] = 1;  // ���� ����� ������ķ� �����.
	}

	while (b > 0) {
		/* b�� Ȧ���̸� ���� ��Ŀ� a����� �߰��� �ѹ� �����ش�. */
		if (b % 2 == 1) {
			MatrixMultiply(ans, a, N);
		}
		/* b�� ¦���̹Ƿ� a����� �������� ��, b�� 2�� �����ش�. */
		MatrixMultiply(a, a, N);
		b /= 2;
	}

	/* ������� ���� ����� ����Ѵ�. */
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
			/* ��� ����, mod��� */
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
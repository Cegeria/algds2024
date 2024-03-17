#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "lab_1.h"

int **InitMtx(int n, int m)
{
	int **mtx = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		mtx[i] = (int*)malloc(sizeof(int)*m);
	return mtx;
}

int min_2(int a, int b)
{
	if (a < b) return a;
	else return b;
}

int min_3(int a, int b, int c)
{
	if (a < b && a < c) return a;
	if (b < a && b < c) return b;
	else return c;
}

int Solve(int **A, int n, int m)
{	
	if (A == NULL) return 0;
	//initializing
	int **dp = InitMtx(n, m);
	for (int i = 0; i < m; i++) {
		dp[0][i] = A[0][i];
	}

	// finding minimum
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == 0) {
				dp[i][j] = A[i][j] + min_2(A[i-1][0], A[i-1][1]);
			} else if (j == m-1) {
				dp[i][j] = A[i][j] + min_2(A[i-1][m-2], A[i-1][m-1]);
			} else {
				dp[i][j] = A[i][j] 
					+ min_3(A[i-1][j-1], A[i-1][j], A[i-1][j+1]);
			}
		}
	}

	int min = dp[n-1][0];
	int idx = 0;
	for (int i = 0; i < m; i++) {
		if (dp[n-1][i] < min) {
			min = dp[n-1][i];
			idx = i;
		}		
	}

	return min;
}

int main()
{
	int **A = InitMtx(3, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			A[i][j] = 1;
		}
		A[i][2] = 0;
	}

	Solve(A, 3, 3);

	return 0;
}

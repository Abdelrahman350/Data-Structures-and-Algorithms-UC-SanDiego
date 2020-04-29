/*
 * LCS3.c
 *
 *  Created on: May 18, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LCS3(int ptrS1[], int rows, int ptrS2[], int cols, int ptrS3[], int depth);
int max(int a, int b);

int main(){
	int lcs, n, m, k;

	fflush(stdin);
	scanf("%d", &n);
	int *ptrS1 = (int *) malloc(n * sizeof(int));
	for(int i = 0; i < n; i++){
		fflush(stdin);
		scanf("%d", ptrS1+i);
	}

	fflush(stdin);
	scanf("%d", &m);
	int *ptrS2 = (int *) malloc(m * sizeof(int));
	for(int i = 0; i < m; i++){
		fflush(stdin);
		scanf("%d", ptrS2+i);
	}

	fflush(stdin);
	scanf("%d", &k);
	int *ptrS3 = (int *) malloc(k * sizeof(int));
	for(int i = 0; i < k; i++){
		fflush(stdin);
		scanf("%d", ptrS3+i);
	}

	lcs = LCS3(ptrS1, n, ptrS2, m, ptrS3, k);

	printf("%d", lcs);
	fflush(stdout);

	return 0;
}

int LCS3(int ptrS1[], int depth, int ptrS2[], int rows, int ptrS3[], int cols){
	depth++;
	rows++;
	cols++;
	int *lcs = (int *) malloc(depth * rows * cols * sizeof(int));

	for(int i = 0; i < depth; i++){
		for(int j = 0; j < rows; j++){
			for(int k = 0; k < cols; k++){
				if(i == 0 || j == 0 || k == 0){
					*(lcs + i*(rows*cols) + j * cols + k) = 0;
				}
				else if(ptrS1[i-1] == ptrS2[j-1] && ptrS1[i-1] == ptrS3[k-1]){
					*(lcs + i*(rows*cols) + j * cols + k) = *(lcs + (i-1)*(rows*cols) + (j-1) * cols + (k-1)) + 1;
				}
				else{
					*(lcs + i*(rows*cols) + j * cols + k) = max(max(*(lcs + (i-1)*(rows*cols) + j * cols + k), *(lcs + i*(rows*cols) + (j-1) * cols + k)), *(lcs + i*(rows*cols) + j * cols + (k-1)));
				}
			}
		}
	}
	return *(lcs + (depth-1)*(rows*cols) + (rows-1)*cols + (cols-1));
}

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

/*
 * LCS.c
 *
 *  Created on: May 17, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LCS(int ptrS1[], int rows, int ptrS2[], int cols);
int max(int a, int b);

int main(){
	int lcs, n, m;

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

	lcs = LCS(ptrS1, n, ptrS2, m);

	printf("%d", lcs);
	fflush(stdout);

	return 0;
}

int LCS(int ptrS1[], int rows, int ptrS2[], int cols){
	rows++;
	cols++;
	int *lcs = (int *) malloc(rows * cols * sizeof(int));

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(i == 0 || j == 0){
				*(lcs + i*cols + j) = 0;
			}
			else if(ptrS1[i-1] == ptrS2[j-1]){
				*(lcs + i*cols + j) = *(lcs + (i-1)*cols + (j-1)) + 1;
			}
			else{
				*(lcs + i*cols + j) = max(*(lcs + (i-1)*cols + j), *(lcs + i*cols + (j-1)));
			}
		}
	}
	return *(lcs + (rows-1)*cols + (cols-1));
}

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

/*
 * EditDistance.c
 *
 *  Created on: May 17, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int editDistance(char string1[], int n, char string2[], int m);
int min(int a, int b);

int main(){
	int distance, n, m;
	char string1[100];
	char string2[100];

	fflush(stdin);
	scanf("%[^\n]%*c",string1);
	fflush(stdin);
	scanf("%[^\n]%*c",string2);

	n = (int)strlen(string1);
	m = (int)strlen(string2);

	distance = editDistance(string1, n, string2, m);

	printf("%d", distance);
	fflush(stdout);

	return 0;
}

int editDistance(char string1[], int rows, char string2[], int cols){
	rows++;
	cols++;
	int *distance = (int *) malloc(rows * cols * sizeof(int));
	int insertion, deletion, match, mismatch;

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(i == 0){*(distance + i*cols + j) = j;}
			else if(j == 0){*(distance + i*cols + j) = i;}
			else{
				insertion = *(distance + i*cols + (j-1)) + 1;
				deletion = *(distance + (i-1)*cols + j) + 1;
				match = *(distance + (i-1)*cols + (j-1));
				mismatch = *(distance + (i-1)*cols + (j-1)) + 1;

				if(string1[i-1] == string2[j-1]){
					*(distance + i*cols + j) = min(min(insertion, deletion), match);
				}
				else{
					*(distance + i*cols + j) = min(min(insertion, deletion), mismatch);
				}
			}
		}
	}

	return *(distance + (rows-1)*cols + cols-1);
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

/*
 * maximumDotProduc.c
 *
 *  Created on: Mar 28, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef long int l_int;

void maxDotProduct(l_int *ptrPrice, l_int *ptrClicks, int *n, l_int *product);
void merge(l_int *ptr, int l, int m, int r);
void mergeSort(l_int *ptr, int l, int r);
void printArray(int n, l_int *ptr);

int main(){
	int n = 0;
	l_int *ptrPrice = 0;
	l_int *ptrClicks = 0;
	l_int product = 0;

	fflush(stdin);
	scanf("%d",&n);

	ptrPrice = (l_int *) malloc(n * sizeof(l_int));
	ptrClicks = (l_int *) malloc(n * sizeof(l_int));

	for(int i = 0; i < n; i++){
		fflush(stdin);
		scanf("%ld", (ptrPrice+i));
	}
	for(int i = 0; i < n; i++){
		fflush(stdin);
		scanf("%ld", (ptrClicks+i));
	}

	//printArray(n, ptrPrice);
	//printArray(n, ptrClicks);

	maxDotProduct(ptrPrice, ptrClicks,&n, &product);
	printf("%ld", product);
	fflush(stdout);

	return 0;
}

void merge(l_int *ptr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = ptr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = ptr[m + 1+ j];

    /* Merge the temp arrays back into ptr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ptr[k] = L[i];
            i++;
        }
        else
        {
            ptr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        ptr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        ptr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of ptr to be sorted */
void mergeSort(l_int *ptr, int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(ptr, l, m);
        mergeSort(ptr, m+1, r);

        merge(ptr, l, m, r);
    }
}

void maxDotProduct(l_int *ptrPrice, l_int *ptrClicks, int *n, l_int *product){
	mergeSort(ptrPrice, 0, (*n - 1));
	mergeSort(ptrClicks, 0, (*n - 1));
	//printArray(*n, ptrPrice);
	//printArray(*n, ptrClicks);
	for(l_int i = 0; i < *n; i++){
		*product += *(ptrClicks + i) * *(ptrPrice + i);
	}
}


void printArray(int n, l_int *ptr){
	printf("{");
	for(int i = 0; i < n; i++){
		printf("%ld\t", *(ptr+i));
		fflush(stdout);
	}
	printf("}\n");
	fflush(stdout);
}


/*
 * Pairwise.c
 *
 *  Created on: Feb 27, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

void maxPairwiseProduct(uint64_t *ptr, int *n, uint64_t *product);
void merge(uint64_t *ptr, int l, int m, int r);
void mergeSort(uint64_t *ptr, int l, int r);
//void printArray(int n, uint64_t *ptr);

int main(){
	int n = 0;
	uint64_t *ptr = 0;
	uint64_t product = 0llu;

	fflush(stdin);
	scanf("%d",&n);

	ptr = (uint64_t *) malloc(n * sizeof(uint64_t));
	for(int i = 0; i < n; i++){
		fflush(stdin);
		scanf("%"PRId64"", (ptr+i));
	}

	//printArray(n, ptr);

	maxPairwiseProduct(ptr, &n, &product);
	printf("%"PRId64"", product);
	fflush(stdout);

	return 0;
}

void merge(uint64_t *ptr, int l, int m, int r)
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
void mergeSort(uint64_t *ptr, int l, int r)
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

void maxPairwiseProduct(uint64_t *ptr, int *n, uint64_t *product){
	mergeSort(ptr, 0, (*n - 1));
	*product = *(ptr+(*n - 1)) * *(ptr+(*n - 2));
}


/*void printArray(int n, uint64_t *ptr){
	printf("{");
	for(int i = 0; i < n; i++){
		printf("%"PRId64"\t", *(ptr+i));
		fflush(stdout);
	}
	printf("}\n");
	fflush(stdout);
}
*/

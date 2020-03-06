/*
 * Knapsack.c
 *
 *  Created on: Mar 27, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct{
	unsigned int v;
	unsigned int w;
	double Vw;
}Item;

double knapsack(unsigned int n, unsigned int W, Item *ptrItem);
void merge(Item *ptrItem, unsigned int l, int m, unsigned int r);
void mergeSort(Item *ptrItem, unsigned int l, unsigned int r);

int main(){
	unsigned int n = 0;
	unsigned int W = 0;
	double result = 0;
	Item *ptrItem;

	fflush(stdin);
	scanf("%u  %u",&n,&W);

	ptrItem = (Item *) malloc(n * sizeof(Item));

	for(unsigned int i = 0; i < n; i++){
		fflush(stdin);
		scanf("%u  %u", &(ptrItem+i)->v, &(ptrItem+i)-> w);
		(ptrItem+i)->Vw = (double)(ptrItem+i)->v / (ptrItem+i)->w;
	}

	result = knapsack(n, W, ptrItem);
	printf("%0.6f\n", result);
	fflush(stdout);

	return 0;
}


/******************************************************************/

double knapsack(unsigned int n, unsigned int W, Item *ptrItem){
	mergeSort(ptrItem, 0, n-1);

	/*for(unsigned int i = 0; i < n; i++){
		printf("v = %u  w = %u  Vw = %f\n", (ptrItem+i)->v, (ptrItem+i)-> w , (ptrItem+i)->Vw);
		fflush(stdout);
	}*/
	unsigned int currentWeight = 0;
	double currentValue = 0;
	unsigned int remainingWeight;

	for(unsigned int i = n; i-- > 0;){
		if(currentWeight + ptrItem[i].w <= W){
			currentWeight += ptrItem[i].w;
			currentValue  += ptrItem[i].v;
		}
		else {
			remainingWeight = W - currentWeight;
			fflush(stdout);
			currentWeight += remainingWeight;
			currentValue  += ((double)remainingWeight / ptrItem[i].w) * ptrItem[i].v;
		}
	}

	return currentValue;
}

/* l is for left index and r is right index of the
   sub-array of ptr to be sorted */
void mergeSort(Item *ptrItem, unsigned int l, unsigned int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(ptrItem, l, m);
        mergeSort(ptrItem, m+1, r);

        merge(ptrItem, l, m, r);
    }
}

void merge(Item *ptrItem, unsigned int l, int m, unsigned int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    Item L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++){
        L[i] = ptrItem[l + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = ptrItem[m + 1+ j];
    }

    /* Merge the temp arrays back into ptr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i].Vw <= R[j].Vw)
        {
        	ptrItem[k] = L[i];
            i++;
        }
        else
        {
        	ptrItem[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
    	ptrItem[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
    	ptrItem[k] = R[j];
        j++;
        k++;
    }
}

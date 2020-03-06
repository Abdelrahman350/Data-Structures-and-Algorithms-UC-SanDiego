/*
 * coveringSegmentsByPoints.c
 *
 *  Created on: Mar 28, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>

typedef unsigned int u_int;
typedef struct{
	u_int start;
	u_int end;
}Segment;

void merge(Segment *ptrItem, u_int l, int m, u_int r);
void mergeSort(Segment *ptrItem, u_int l, u_int r);
Segment* pointSegments(Segment *ptrItem, u_int n, u_int *counter, Segment *ptrResult);

int main(){
	u_int n = 0;
	Segment *ptrItem;
	Segment *ptrResult = 0;
	u_int m = 0;
	u_int *counter = &m;
	*counter = 0;

	fflush(stdin);
	scanf("%u",&n);

	ptrItem = (Segment *) malloc(n * sizeof(Segment));

	for(u_int i = 0; i < n; i++){
		fflush(stdin);
		scanf("%u  %u", &(ptrItem+i)->start, &(ptrItem+i)-> end);
	}

	ptrResult = pointSegments(ptrItem, n, counter, ptrResult);

	printf("%u\n",*counter);
	fflush(stdout);

	for(u_int i = 0; i < *counter; i++){
		printf("%u ", ptrResult[i].end);
		fflush(stdout);
	}

	return 0;
}

void mergeSort(Segment *ptrItem, u_int l, u_int r)
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

void merge(Segment *ptrItem, u_int l, int m, u_int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    Segment *ptrL, *ptrR;
    ptrL = (Segment *) malloc(n1 * sizeof(Segment));
    ptrR = (Segment *) malloc(n2 * sizeof(Segment));

    /* Copy data to temp arrays ptrL[] and ptrR[] */
    for (i = 0; i < n1; i++){
        ptrL[i] = ptrItem[l + i];
    }
    for (j = 0; j < n2; j++){
        ptrR[j] = ptrItem[m + 1+ j];
    }

    /* Merge the temp arrays back into ptr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (ptrL[i].end <= ptrR[j].end)
        {
        	ptrItem[k] = ptrL[i];
            i++;
        }
        else
        {
        	ptrItem[k] = ptrR[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of ptrL[], if there
       are any */
    while (i < n1)
    {
    	ptrItem[k] = ptrL[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of ptrR[], if there
       are any */
    while (j < n2)
    {
    	ptrItem[k] = ptrR[j];
        j++;
        k++;
    }
}

Segment* pointSegments(Segment *ptrItem, u_int n, u_int *counter, Segment *ptrResult){

	mergeSort(ptrItem, 0, n-1);
	Segment segments[n];
	Segment currentPoint = *(ptrItem+0);

	segments[(*counter)++] = currentPoint;
	for(u_int i = 1; i < n; i++){
		if(currentPoint.end < (ptrItem+i)->start){
			currentPoint = *(ptrItem+i);
			segments[(*counter)++] = currentPoint;
		}
	}
	free(ptrItem);
	ptrItem = NULL;
	ptrResult = (Segment *) malloc(*counter * sizeof(Segment));
	for(u_int i = 0; i < *counter; i++){
		ptrResult[i] = segments[i];
	}
	return ptrResult;
}

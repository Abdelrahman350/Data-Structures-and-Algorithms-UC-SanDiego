/*
 * largestNumber.cpp
 *
 *  Created on: Mar 31, 2019
 *      Author: Abdelrahman
 */



#include <iostream>
#include <cstdlib>
#include <cstring>

typedef unsigned int uint;

uint* largestNumber(uint n, uint *ptr, uint *ptrResult);
uint IsGreater(uint a, uint b);
void mergeSort(uint *ptr, int l, int r);
void merge(uint *ptr, int l, int m, int r);

using namespace std;

int main(){
	uint n = 0;
	uint m = 0;
	uint r = 0;
	uint *ptr = &m;
	uint *ptrResult = &r;


	cin >> n;

	ptr = (uint *) malloc(n * sizeof(uint));

	for(uint i = 0; i < n; i++){

		scanf("%u", (ptr+i));
	}

	ptrResult = largestNumber(n, ptr, ptrResult);

	printf("%u", *ptrResult);

	return 0;
}

uint* largestNumber(uint n, uint *ptr, uint *ptrResult){
	uint x = 4;
	char* str;
	char temp[x];

	str = (char *) malloc(x*n * sizeof(char));
	mergeSort(ptr, 0, n-1);
	temp = to_string(*(ptr+0));
	strcpy(str, temp);

	for(uint i = 1; i < n; i++){
		temp = to_string(*(ptr+i));
		strcat (str, temp);
	}
	*ptrResult = stol (str);
	return ptrResult;
}

uint IsGreater(uint a, uint b){
	char sa[3];
	char sb[3];
	char sab[6];
	char sba[6];
	uint ab, ba;

	sa = to_string(a);
	sb = to_string(b);

	strcpy (sab, sa);
	strcat (sab, sb);

	strcpy (sba, sb);
	strcat (sba, sa);

	ab = stol (sab);
	ba = stol (sba);

	if(ab >= ba){
		return 1;
	}
	else{
		return 0;
	}
}


/* l is for left index and r is right index of the
   sub-array of ptr to be sorted */
void mergeSort(uint *ptr, int l, int r)
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

void merge(uint *ptr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    uint *ptrL, *ptrR;
    ptrL = (uint *) malloc(n1 * sizeof(uint));
    ptrR = (uint *) malloc(n2 * sizeof(uint));

    /* Copy data to temp arrays ptrL[] and ptrR[] */
    for (i = 0; i < n1; i++){
        ptrL[i] = ptr[l + i];
    }
    for (j = 0; j < n2; j++){
        ptrR[j] = ptr[m + 1+ j];
    }

    /* Merge the temp arrays back into ptr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (IsGreater(ptrL[i] , ptrR[j]))
        {
            ptr[k] = ptrL[i];
            i++;
        }
        else
        {
            ptr[k] = ptrR[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of ptrL[], if there
       are any */
    while (i < n1)
    {
        ptr[k] = ptrL[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of ptrR[], if there
       are any */
    while (j < n2)
    {
        ptr[k] = ptrR[j];
        j++;
        k++;
    }
}


/*
 * largestNumber.c
 *
 *  Created on: Mar 30, 2019
 *      Author: Abdelrahman
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long int uint;

char* largestNumber(uint n, uint *ptr, char *ptrResult);
uint IsGreater(uint a, uint b);
void mergeSort(uint *ptr, int l, int r);
void merge(uint *ptr, int l, int m, int r);
void printArray(int n, uint *ptr);
char* Itoa(long int num, char* str, int base);
long int Atoi(char *str);
void reverse(char str[], int length);
void swap(char *xp, char *yp);

int main(){
	uint n = 0;
	uint m = 0;
	char r = 0;
	uint *ptr = &m;
	char *ptrResult = &r;

	fflush(stdin);
	scanf("%lu",&n);

	ptr = (uint *) malloc(n * sizeof(uint));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%lu", (ptr+i));
	}

	ptrResult = largestNumber(n, ptr, ptrResult);

	printf("%s", ptrResult);
	fflush(stdout);

	return 0;
}

char* largestNumber(uint n, uint *ptr, char *ptrResult){
	uint x = 6;
	char* str;
	char temp[x];

	str = (char *) malloc(x*n * sizeof(char));
	mergeSort(ptr, 0, n-1);

	Itoa(*(ptr+0), temp, 10);
	strcpy (str, temp);

	for(uint i = 1; i < n; i++){
		Itoa(*(ptr+i), temp, 10);
		strcat (str, temp);
	}
	return str;
}

uint IsGreater(uint a, uint b){
	char sa[6];
	char sb[6];
	char sab[12];
	char sba[12];
	uint ab, ba;

	Itoa(a, sa, 10);
	Itoa(b, sb, 10);

	strcpy (sab, sa);
	strcat (sab, sb);

	strcpy (sba, sb);
	strcat (sba, sa);

	ab = Atoi(sab);
	ba = Atoi(sba);

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


void printArray(int n, uint *ptr){
	printf("{");
	for(int i = 0; i < n; i++){
		printf("%lu ", *(ptr+i));
		fflush(stdout);
	}
	printf("}\n");
	fflush(stdout);
}

long int Atoi(char *str)
{
	long int res = 0;  // Initialize result
	long int sign = 1;  // Initialize sign as positive
	long int i = 0;  // Initialize index of first digit

    // If number is negative, then update sign
    if (str[0] == '-')
    {
        sign = -1;
        i++;  // Also update index of first digit
    }

    // Iterate through all digits and update the result
    for (; str[i] != '\0'; ++i)
        res = res*10 + str[i] - '0';

    // Return result with sign
    return sign*res;
}

char* Itoa(long int num, char* str, int base){
    int i = 0;
    int isNegative = 0;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard Itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}

void reverse(char str[], int length){
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap((str+start), (str+end));
        start++;
        end--;
    }
}

void swap(char *xp, char *yp)
{
    char temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*
 * ClosestPointsMIT.c
 *
 *  Created on: May 10, 2019
 *      Author: Abdelrahman
 */


#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <time.h>

typedef unsigned int uint;
typedef struct Points{
	long int x;
	long int y;
}Point;

double closestPoints(Point *ptr, uint end);
double pointsDivide(Point *ptrX, Point *ptrY, uint start, uint end);
double min(double left, double right);
double brutalForceSolution(Point *ptr, uint n);
double divideStrip(Point *ptrStrip, uint size, double minDistance);
void mergeSort(Point *ptr, uint start, uint end, int (*IsLower)(Point*, Point*));
void merge(Point *ptr, uint start, uint middle, uint end, int (*IsLower)(Point*, Point*));
int IsLowerX(Point *ptrLeft, Point *ptrRight);
int IsLowerY(Point *ptrLeft, Point *ptrRight);
void StressTest(void);

int main(){
	uint n = 0;
	Point *ptr = NULL;
	double minimumDistance = 0;

	fflush(stdin);
	scanf("%u",&n);

	ptr = (Point *) malloc(n * sizeof(Point));

	for(uint i = 0; i < n; i++){
		fflush(stdin);
		scanf("%ld  %ld", &(ptr+i)->x, &(ptr+i)->y);
	}

	minimumDistance = closestPoints(ptr, n);

	printf("%0.6lf", minimumDistance);
	fflush(stdout);

	//*/StressTest();
	return 0;
}
/*******************************************************************/
double closestPoints(Point *ptr, uint n){
	uint start = 0;
	int (*IsLower)(Point*, Point*);
	Point *ptrX = NULL;
	Point *ptrY = NULL;

	ptrX = (Point *) malloc(n * sizeof(Point));
	ptrY = (Point *) malloc(n * sizeof(Point));
	//(1)Assigning ptr into ptrX and ptrY
	for(uint i = 0; i < n; i++){
		*(ptrX + i) = *(ptr + i);
		*(ptrY + i) = *(ptr + i);
	}
	free(ptr);
	//(2)Sort Points using x-coordinate in ptrX
	IsLower = &IsLowerX;
	mergeSort(ptrX, start, n-1, IsLower);
	//(3)Sort Points using y-coordinates in ptrY
	IsLower = &IsLowerY;
	mergeSort(ptrY, start, n-1, IsLower);
	//(4) Dividing step recursively
	return pointsDivide(ptrX, ptrY, start, n-1);
}

double pointsDivide(Point *ptrX, Point *ptrY, uint start, uint end){
	uint n = end - start + 1;
	if(n <= 3){
		return brutalForceSolution((ptrX + start), n);
	}
	else{
		//(1)Find the middle point and create middle line
		uint middle = start + (end - start)/2;
		long int middleLineX = (*(ptrX + middle)).x ;
		//(2)Divide ptrY into two arrays: (left <= middleLineX) and (right > middleLineX)
		Point *ptrY_Left = NULL;
		Point *ptrY_Right = NULL;
		Point *ptrStrip = NULL;

		uint leftSize = middle - start + 1;
		uint rightSize = end - middle;

		ptrY_Left = (Point *) malloc(leftSize * sizeof(Point));
		ptrY_Right = (Point *) malloc(rightSize * sizeof(Point));
		ptrStrip = (Point *) malloc(n * sizeof(Point));

		uint i = 0;
		uint j = 0;
		uint k = 0;
		while((i < leftSize) && (j < leftSize)){
			if((*(ptrY + k)).x <= middleLineX){
				*(ptrY_Left + i) = *(ptrY + k);
				i++;
			}
			else{
				*(ptrY_Right + j) = *(ptrY + k);
				j++;
			}
			k++;
		}
		while(i < leftSize){
			*(ptrY_Left + i) = *(ptrY + k);
			i++;
			k++;
		}
		while(j < rightSize){
			*(ptrY_Right + j) = *(ptrY + k);
			j++;
			k++;
		}

		// Minimum distance in the left half
		double minimumLeft = pointsDivide(ptrX, ptrY_Left, start, middle);
		// Minimum distance in the right half
		double minimumRight = pointsDivide(ptrX, ptrY_Right, middle+1, end);
		// Get the absolute minimum from the above 2 distances
		double minimumHalf = min(minimumLeft, minimumRight);

		// Create strip
		uint size = 0;
		for(uint i = 0; i < n; i++){
			if(fabs((*(ptrY+i)).x - middleLineX) < minimumHalf){
				*(ptrStrip + size) = *(ptrY + i);
				size++;
			}
		}
		if(size < 2){
		    return minimumHalf;
		}
		else{
		    return min(minimumHalf, divideStrip(ptrStrip, size, minimumHalf));
		}
	}
}

double calculateDistance(Point *P1, Point *P2){
	return sqrt(((*P1).x - (*P2).x)*((*P1).x - (*P2).x) + ((*P1).y - (*P2).y)*((*P1).y - (*P2).y));
}

double min(double left, double right){
	if(left <= right){
		return left;
	}
	else{
		return right;
	}
}

double brutalForceSolution(Point *ptr, uint n){
	double minimum = FLT_MAX; //Maximum possible number of floats
	for(uint i = 0; i < n-1; i++){
		double distance = calculateDistance((ptr+i), (ptr+i+1));
		if(distance < minimum){
			minimum = distance;
		}
	}
	return minimum;
}

double divideStrip(Point *ptrStrip, uint size, double minDistance){
	double minimum = minDistance;
	for(uint i = 0; i < size; i++){
		for(uint j = i + 1; j < size && ((ptrStrip+i)->y - (*(ptrStrip+j)).y) < minimum; j++){
			double distance = calculateDistance((ptrStrip+i), (ptrStrip+j));
			if(distance < minimum){
				minimum = distance;
			}
		}
	}
	return minimum;
}
/*******************************************************************/


void mergeSort(Point *ptr, uint start, uint end, int (*IsLower)(Point*, Point*)){
	if(start < end){
		uint middle = start + (end - start)/2;

		mergeSort(ptr, start, middle, IsLower);
		mergeSort(ptr, middle+1, end, IsLower);

		merge(ptr, start, middle, end, IsLower);
	}
}

void merge(Point *ptr, uint start, uint middle, uint end, int (*IsLower)(Point*, Point*)){
	uint i, j, k;
	Point *ptrLeft = 0;
	Point *ptrRight = 0;
	uint leftSize = middle - start + 1;
	uint rightSize = end - middle;

	/*Create Temporary Arrays*/
	ptrLeft = (Point *) malloc(leftSize * sizeof(Point));
	ptrRight = (Point *) malloc(rightSize * sizeof(Point));

	/*Copy Data to Temporary Arrays*/
	for(i = 0; i < leftSize; i++){
		*(ptrLeft+i) = *(ptr+start+i);
	}
	for(j = 0; j < rightSize; j++){
		*(ptrRight+j) = *(ptr+middle+j+1);
	}

	/*Merge the temporary arrays*/
	i = 0; j = 0; k = start;
	while((i < leftSize) && (j < rightSize)){
		if(IsLower((ptrLeft+i), (ptrRight+j))){
			*(ptr+k) = *(ptrLeft+i); /*Pick the left element if it's smaller*/
			i++; /*Move the pointer to the next element in the left array*/
		}
		else{
			*(ptr+k) = *(ptrRight+j); /*Pick the right element if it's smaller*/
			j++; /*Move the pointer to the next element in the right array*/
		}
		k++; /*Move the pointer to the next element in the merged array*/
	}

	/*Copy the remaining elements*/
	while(i < leftSize){
		*(ptr+k) = *(ptrLeft+i);
		i++;
		k++;
	}
	while(j < rightSize){
		*(ptr+k) = *(ptrRight+j);
		j++;
		k++;
	}
}

int IsLowerX(Point *ptrLeft, Point *ptrRight){
	if(ptrLeft->x <= (*ptrRight).x){
		return 1;
	}
	else{
		return 0;
	}
}

int IsLowerY(Point *ptrLeft, Point *ptrRight){
	if(ptrLeft->y <= (*ptrRight).y){
		return 1;
	}
	else{
		return 0;
	}
}

void StressTest(void){
	uint n = 0;
	double d1, d2;
	Point *ptr1 = NULL;
	srand(time(0));
	while(1){
		n = rand() % (20-2+1)+2;
		printf("\n\n____________________ [n = %u] ______________________\n", n);
		fflush(stdout);
		ptr1 = (Point *) malloc(n * sizeof(Point));
		for(uint i = 0; i < n; i++){
			(ptr1+i)->x = rand() % (100-(-100)+1)+(-100);
			(ptr1+i)->y = rand() % (100-(-100)+1)+(-100);
		}
		printf("Original Array = {");
		fflush(stdout);
		for(uint i = 0; i < n; i++){
			printf("{%ld, %ld}, ",(*(ptr1+i)).x, (*(ptr1+i)).y);
			fflush(stdout);
		}
		printf("}\n");
		d2 = brutalForceSolution(ptr1, n);
		d1 = closestPoints(ptr1, n);

		if((d1 != d2) && (d1 > d2) ){
			printf("error : distanceEfficient = %lf\tdistanceNaive = %lf",d1,d2);
			fflush(stdout);
			break;
		}

	}
}


/*
 * merge_sort.c
 *
 *  Created on: Oct 30, 2017
 *      Author: wenxuan
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

void splitIntoHalf(int *A, size_t length, int *A1, int *A2) {
	for (int i = 0; i < length; i++) {
		if (i < length / 2)
			A1[i] = A[i];
		else
			A2[i-length/2] = A[i];
	}
	return;
}

void combine(int *A, size_t length, int *A1, int *A2) {
	for (int k = 0, i = 0, j = 0; k < length; k++) {
		if (i == length/2) {
			A[k] = A2[j++];
			continue;
		}
		if (j == (length+1)/2) {
			A[k] = A1[i++];
			continue;
		}
		if (A1[i] < A2[j])
			A[k] = A1[i++];
		else
			A[k] = A2[j++];
	}
}

void mergeSort(int *A, size_t length) {
	if (length == 1)
		return;
	int A1[length/2], A2[(length+1)/2];
	splitIntoHalf(A, length, A1, A2);
	mergeSort(A1, length/2);
	mergeSort(A2, (length+1)/2);
	combine(A, length, A1, A2);
}

void myPrintArray(int *A, size_t length) {
	for (int i = 0; i < length; i++)  {
		if (i == length - 1)
			printf("%d\n", A[i]);
		else {
			printf("%d ", A[i]);
		}
	}
}




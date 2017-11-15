/*
 * merge_sort.c
 *
 *  Created on: Oct 30, 2017
 *      Author: wenxuan
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "inv_merge_sort.h"
#include "merge_sort.h"

void invCombine(int *A, size_t length, int *A1, int *A2) {
	int remainOfA1 = length / 2;
	for (int k = 0, i = 0, j = 0; k < length; k++) {
		// A1 has ran out, there are no more inversions
		if (i == length/2) {
			A[k] = A2[j++];
			continue;
		}

		// A2 has ran out, all inversions have been calculated
		if (j == (length+1)/2) {
			A[k] = A1[i++];
			continue;
		}

		// add one number to A from A1, no need to add inversions
		if (A1[i] < A2[j]) {
			A[k] = A1[i++];
			remainOfA1--;
		}

		// add one number to A from A2, add the number of A1 now to inversions
		else {
			A[k] = A2[j++];
			numberOfInversions += remainOfA1;
		}
	}
}

int invMergeSort(int *A, size_t length) {
	if (length == 1)
		return numberOfInversions;
	int A1[length/2], A2[(length+1)/2];
	splitIntoHalf(A, length, A1, A2);
	invMergeSort(A1, length/2);
	invMergeSort(A2, (length+1)/2);
	invCombine(A, length, A1, A2);
	return numberOfInversions;
}

void readArray(int *A, size_t length) {
	for (int i = 0; i < length; i++) {
		scanf("%d", &A[i]);
	}
}


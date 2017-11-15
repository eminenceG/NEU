/*
 * merge_sort_main.c
 *
 *  Created on: Oct 30, 2017
 *      Author: wenxuan
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "inv_merge_sort.h"

int main(void) {
	size_t length = 5;
	int A[length];
	readArray(A, length);
	myPrintArray(A, length);
	int numberOfInversions = invMergeSort(A, length);
	myPrintArray(A, length);

	printf("Number of Inversions: %d\n", numberOfInversions);
	return EXIT_SUCCESS;
}

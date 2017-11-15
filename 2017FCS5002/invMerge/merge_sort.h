/*
 * merge_sort.h
 *
 *  Created on: Oct 30, 2017
 *      Author: wenxuan
 */

#ifndef MERGE_SORT_H_
#define MERGE_SORT_H_

#include <stdbool.h>
#include <stdlib.h>

/**
 * Split an int array into half
 * @param A original array
 * @param length array length
 * @param A1 first half array
 * @param A2 second half array
 */
void splitIntoHalf(int *A, size_t length, int *A1, int *A2);

void combine(int *A, size_t length, int *A1, int *A2);

void mergeSort(int *A, size_t length);

void myPrintArray(int *A, size_t length);

#endif /* MERGE_SORT_H_ */

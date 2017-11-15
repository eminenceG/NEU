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
#include "merge_sort.h"

void readArray(int *A, size_t length);

static int numberOfInversions = 0;

void invCombine(int *A, size_t length, int *A1, int *A2);

int invMergeSort(int *A, size_t length);

#endif /* MERGE_SORT_H_ */

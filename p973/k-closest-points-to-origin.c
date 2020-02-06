/*
 * k-closest-points-to-origin.c
 *
 *  Created on: Feb 6, 2020
 *      Author: yunfang
 */

#include <assert.h>
#include <stdlib.h>

#include "solution.h"

int main() {
	int pointsSize = 3;
	int pointsColSize = 2;
	int **points = (int**) malloc(pointsSize * sizeof(int*));
	for (int i = 0; i < pointsSize; i++) {
		points[i] = (int*) malloc(pointsColSize * sizeof(int));
	}
	points[0][0] = 3;
	points[0][1] = 3;
	points[1][0] = 5;
	points[1][1] = -1;
	points[2][0] = -2;
	points[2][1] = 4;
	int returnSize;
	int **returnColumnSizes = (int**) malloc(sizeof(int*));
	int **res = kClosest(points, 3, &pointsColSize, 2, &returnSize, returnColumnSizes);
	assert(res[0][0] == 3);
	assert(res[0][1] == 3);
	assert(res[1][0] == -2);
	assert(res[1][1] == 4);
}

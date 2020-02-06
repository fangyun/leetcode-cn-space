#include <stdlib.h>

int comparator(const void *a, const void *b) {
	return *(int*) a - *(int*) b;
}

typedef struct _Point {
	int distance;
	int xy[2];
} Point;

int** kClosest(int **points, int pointsSize, int *pointsColSize, int K, int *returnSize, int **returnColumnSizes) {
	if (pointsSize == K) {
		return points;
	}
	Point *ps = (Point*) malloc(pointsSize * sizeof(Point));
	for (int i = 0; i < pointsSize; i++) {
		int x = points[i][0];
		int y = points[i][1];
		ps[i].distance = x * x + y * y;
		ps[i].xy[0] = points[i][0];
		ps[i].xy[1] = points[i][1];
	}
	qsort(ps, pointsSize, sizeof(Point), comparator);
	*returnSize = K;
	int *colSize = (int*) malloc(K * sizeof(int));
	int **res = (int**) malloc(K * sizeof(int*));
	for (int i = 0; i < K; i++) {
		colSize[i] = 2;
		res[i] = ps[i].xy;
	}
	*returnColumnSizes = colSize;
	return res;
}

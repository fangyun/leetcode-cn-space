#include <stdlib.h>

typedef struct _Node {
	int distance;
	int n[2];
} Node;

int comparator(const void *a, const void *b) {
	return ((Node*) a)->distance - ((Node*) b)->distance;
}

int** allCellsDistOrder(int R, int C, int r0, int c0, int *returnSize, int **returnColumnSizes) {
	Node *nodes = (Node*) malloc(R * C * sizeof(Node));
	int *columSize = (int*) malloc(sizeof(int) * R * C);
	for (int i = 0; i < R * C; i++) {
		columSize[i] = 2;
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			nodes[i * C + j].distance = abs(i - r0) + abs(j - c0);
			nodes[i * C + j].n[0] = i;
			nodes[i * C + j].n[1] = j;
		}
	}
	qsort(nodes, R * C, sizeof(Node), comparator);
	int **mat = (int**) malloc(R * C * sizeof(int*));
	for (int i = 0; i < R * C; i++) {
		mat[i] = nodes[i].n;
	}
	*returnSize = R * C;
	*returnColumnSizes = columSize;
	return mat;
}

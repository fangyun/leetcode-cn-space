#include "solution.h"

struct TreeNode* newNode(int val) {
	struct TreeNode *n = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	n->val = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

int main() {
	struct TreeNode *root1 = newNode(2);
	root1->left = newNode(1);
	root1->right = newNode(4);

	struct TreeNode *root2 = newNode(1);
	root2->left = newNode(0);
	root2->right = newNode(3);

	int r = 0;
	int *a = getAllElements(root1, root2, &r);
	for (int i = 0; i < r; i++) {
		printf("%d ", a[i]);
	}
	return 0;
}

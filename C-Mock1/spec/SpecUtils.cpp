#include "stdafx.h"
#include "SpecUtils.h"

TreeNode *createNode(int value) {
	TreeNode *node;
	node = (TreeNode *)malloc(sizeof(TreeNode));
	node->data = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

// BST
void insertNodeInTree(TreeNode *root, TreeNode *node) {
	if (node->data > root->data) {
		// insert in right sub-tree

		if (root->right != NULL) {
			// right sub-tree exists
			return insertNodeInTree(root->right, node);
		}

		// there is no right sub-tree
		root->right = node;

	}
	else {
		// insert in left sub-tree
		if (root->left != NULL) {
			// left sub-tree exists
			return insertNodeInTree(root->left, node);
		}

		// there is no left sub-tree
		root->left = node;
	}
}


TreeNode *createTree(int numbers[], int size) {

	TreeNode *root;
	TreeNode *node;

	root = createNode(numbers[0]);
	for (int i = 1; i < size; i++) {
		node = createNode(numbers[i]);
		insertNodeInTree(root, node);
	}

	return root;
}

void strcopy(char *s, char *t){
	int i = 0;
	do{
		s[i] = t[i];
		i++;
	} while (t[i] != '\0');
}

struct CityNode * createCityNode(char name[20]) {
	struct CityNode *newNode = (struct CityNode *)calloc(1, sizeof(CityNode));
	strcopy(newNode->city, name);
	newNode->nextCity = NULL;
	return newNode;
}

struct CityNode * createPath(char cities[][20], int len) {
	struct CityNode *head = NULL;

	for (int i = len - 1; i >= 0; i--){
		struct CityNode *newNode = createCityNode(cities[i]);
		newNode->nextCity = head;
		head = newNode;
	}
	return head;
}

struct CityNode *appendPath(CityNode *c1, CityNode *c2){
	CityNode *t = c1;
	while (t->nextCity != NULL)
		t = t->nextCity;
	t->nextCity = c2;
	return c1;
}

int areSameCityNode(CityNode *city1, CityNode *city2){
	if (city1 == city2)
		return 1;
	return 0;
}

int compareSnake(int** output, int expectedOutput[3][100]){
	if (expectedOutput == NULL){
		if (output == NULL)	return 1;
		return 0;
	}
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 100; j++){
			if (output[i][j] != expectedOutput[i][j])	return 0;
		}
	}
	return 1;
}
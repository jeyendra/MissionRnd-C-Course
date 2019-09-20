/*	Maximum Marks: 15
	Problem code: Parent of Leaf Nodes
*/

// Find the numbers of nodes, which have a leaf node.
#include "BinaryTree.h"

/*
  e.g:
  single node => 0
  3 nodes balanced tree => 1
  10 nodes skewed tree => 1
  3 level complete binary tree => 2

*/

int numberOfLeafNodeParents(struct treeNode *rootNode) {
	if (rootNode == NULL)
	{
		return 0;
	}
	if (rootNode->left == NULL&&rootNode->right != NULL)
	{
		if (rootNode->right->left == NULL&&rootNode->right->right == NULL)
		{
			return 1;
		}
	}
	if (rootNode->left != NULL&&rootNode->right == NULL)
	{
		if (rootNode->left->left == NULL&&rootNode->left->right == NULL)
		{
			return 1;
		}
	}
	if (rootNode->left != NULL&&rootNode->right != NULL)
	{
		if (rootNode->right->left == NULL&&rootNode->right->right == NULL&&rootNode->left->left == NULL&&rootNode->left->right == NULL)
		{
			return 1;
		}
	}
	return numberOfLeafNodeParents(rootNode->right) + numberOfLeafNodeParents(rootNode->left);
}



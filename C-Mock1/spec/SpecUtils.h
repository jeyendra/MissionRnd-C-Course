#include "../src/BinaryTree.h"

TreeNode *createTree(int numbers[], int size);
struct CityNode * createPath(char cities[][20], int len);
struct CityNode *appendPath(CityNode *c1, CityNode *c2);
int areSameCityNode(CityNode *city1, CityNode *city2);
int compareSnake(int** output, int expectedOutput[3][100]);
int compareArray(int *a, int *b);

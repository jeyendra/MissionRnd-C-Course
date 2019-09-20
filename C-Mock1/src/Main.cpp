#include <stdlib.h>
#include <stdio.h>

#include "Functions.h"
#include "BinaryTree.h"
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
void disp(struct CityNode *head)
{
	struct CityNode *temp = head;
	int len = 0;
	while (temp != NULL)
	{
		printf("%s->",temp->city);
		temp = temp->nextCity;
	}
}
int main(){
	int len = 17,i,j,k;
	int **actual = initialSnakePosition(len);
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 50; j++)
		{
			printf("%d ",actual[i][j]);
		}
		printf("\n");
	}
	int l1;
	scanf("%d", &l1);
	return 0;
}

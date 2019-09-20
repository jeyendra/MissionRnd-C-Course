/*
ProblemCode : P01FilterTransform
score : 10

Given an ordered collection of integers. Filter the collection first and
then transform it, using the given filter and tranform function pointers.

collection               ==apply-filter=====> collection-after-filter
collection-after-filter  ==apply-transform==> collection-after-transform

Example:

Input:
c[]       : {21, 2, 43, 4, 5, 6}
size      : 6
filter    : is_even  (function pointer)
transform : square   (function pointer)

Where is_even and square are functions with following implementation:
int is_even(int k) {
if (k%2 == 0) {
return 1;  // it's even
}
return 0;
}

int square(int k) {
return k*k;
}

Output:
IntArray {
size: 3,
numbers: {4, 16, 36}
}

Details:
Applying the filter function: is_even
collection-after-filter: {2, 4, 6}, size = 3

Applying the transform function: square
collection-after-transform: {4, 16, 36}, size = 3

Constraints:
1 <= size < 10^4
filter can be NULL. Means absense of filter.
trasform can be NULL. Means absense of transform.

Note:
collection  ==apply-filter=====> collection-after-filter
When filter is NULL, collection-after-filter is same as collection.

collection-after-filter  ==apply-transform==> collection-after-transform
When transform is NULL, collection-after-transform is same as collection-after-filter.

Data-types filter_func, transform_func and IntArray are
defined in Functions.h

like this:

// Returns
//  0 - fail
//  1 - pass
typedef int (*filter_func)(int k);

// Returns after applying the tranformation
typedef int (*transform_func)(int k);

// IntArray data type,
// when size is 0, numbers must be set to NULL.
typedef struct {
int size;
int *numbers;
} IntArray;
*/

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

//
// Filter the collection and then
// Transform the collection
// using the give two function pointers
// filter & transform.
//
// Return the size and resulting collection
// using IntArray data-type.
//
IntArray *filter_and_transform(int c[], int size,
	filter_func filter,
	transform_func transform) {
	int i, j, count = 0, *arr;
	IntArray *ans = (IntArray*)malloc(sizeof(IntArray));
	if ((*filter) == NULL && (*transform) == NULL)
	{
		ans->size = size;
		ans->numbers = c;
		return ans;
	}
	if ((*filter) == NULL)
	{
		for (i = 0; i < size; i++)
		{
			c[i] = (*transform)(c[i]);
		}
		ans->size = size;
		ans->numbers = c;
		return ans;
	}
	for (i = 0; i < size; i++)
	{
		if ((*filter)(c[i]) == 1)
		{
			count++;
		}
	}
	printf("%d\n", count);
	j = 0;
	if (count == 0)
	{
		ans->size = 0;
		ans->numbers = NULL;
		return ans;
	}
	arr = (int*)malloc((count)*sizeof(int));
	if ((*transform) != NULL)
	{
		for (i = 0; i < size; i++)
		{
			if ((*filter)(c[i]) == 1)
			{
				arr[j] = (*transform)(c[i]);
				j++;
			}
		}
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			if ((*filter)(c[i]) == 1)
			{
				arr[j] = c[i];
				j++;
			}
		}
	}
	ans->size = count;
	ans->numbers = arr;
	return ans;
}
/*
 Problem Code: P06MaxGold
 Score: 20

 Ragnar Lothbrok, a famous treasure collector went on an expedition to Paris.
 The Paris king offered him gold but the amount of gold offering depends on this problem.
 
 Ragnar need to start from the root of the 3-ary TREE and should reach any leaf.
 In this tree, each node contains either 0 or 1 or 2. Along the path travelled by
 Ragnar (root to leaf), forms a number with base-3. Ragnar will get the gold in tons
 of decimal value of the number.
 
 A 3-ary tree is similar to any other tree except each node can have a maximum of 3 children.
 
Ragnar asked his intelligent friend Loki (you). How much maximum gold can they get,
 
  Example:               1
                      /  |  \
                     0   1   2
 
  Explanation:     In the above example, root to leaf paths are 10, 11, 12
                   Amoung them, 12 (base-3) forms the highest decimal value which is 5.
                   So, Ragnar Lothbrok gets 5 tons of gold.
                   Return 5.

 
 Constraints:
    When root is NULL, you must return -1
 
  Note:
  The new type Node is defined in Function.h like this:
  typedef struct node {
    int bin;
    struct node* first_node;
    struct node* second_node;
    struct node* third_node;
  } Node;

*/

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

 int max_gold(Node *root) {
     return -1;
 }

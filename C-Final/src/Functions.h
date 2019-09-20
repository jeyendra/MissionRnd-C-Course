//
//  Functions.h


#ifndef Functions_h
#define Functions_h

//
// Q01
//

// Returns
//  0 - fail
//  1 - pass
typedef int (*filter_func)(int k);

// Returns after applying the tranformation
typedef int (*transform_func)(int k);

// Note: when size is 0, numbers must be set to NULL.
typedef struct {
    int size;
    int *numbers;
} IntArray;

IntArray *filter_and_transform(int c[], int size,
                               filter_func f, transform_func t);

//
// Q02
//

int number_of_minutes(int crawl, int slip, int walls, int heights[]);


//
// Q03
//

// structure to store a blob.
typedef struct {
    int length;
    unsigned char *bytes;
} Blob;

Blob *map_and_pack(char *sentence);

//
// Q04
//

char* nth_number(unsigned long long int n);


//
// Q05
//

char *word_repeating_pos_times(char *sentence1, char *sentence2);

//
// 06
//

typedef struct node {
  int bin;
  struct node* first_node;
  struct node* second_node;
  struct node* third_node;
} Node;

int max_gold(Node *root);


#endif /* Functions_h */

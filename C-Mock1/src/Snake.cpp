#include <stdio.h>
#include <stdlib.h>

/*
    Maximum Marks: 15
    
    Problem Code : Snake

    Srinivas is a snake lover. He recently started coding. He came across the snake game in his phone and he
    wanted to simulate it with his own coding knowledge. He divided the task into some modules and he asked
    your help for one of the modules. The module he asked is predicting the initial position of snake.

    The snake moves in the fashion shown below.

        1   ->   2  ->   3       ->      4        -> 5  
                 1       2               3           4 1
                         1               2 1         3 2       
                                                                                                                                            
    Here 1 is the head of the snake.

    So initially the length of the snake is known.
    Now your job is to initialise the 2D matrix of 3x100 size with the position of the snake as shown above
    and leave the other positions as 0.
    
    Movement : Go down till end,Go right 1 step, Go Up till end,Go right 1 step, Repeat.
    
    Input : Length of the snake
    Output : Position of the snake based on its length.
    
    Ex:

    1) Input  = 1        
       Output = 1


    2) Input  = 7
       Output = 17  12  11  6  5
                16  13  10  7  4  1
                15  14   9  8  3  2

    Return NULL for invalid cases.

*/



int** initialSnakePosition(int len)
{
	int i, j, k,temp;
	i = j = k = 0;
	if (len == 0)
	{
		NULL;
	}
	int** a = (int**)malloc(3 * sizeof(int*));
	for (i = 0; i < 3; i++)
	{
		a[i] = (int*)malloc(100 * sizeof(int));
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 100; j++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			temp = len;
		}
		if (i == 1)
		{
			temp = len - 1;
		}
		if (i == 2)
		{
			temp = len - 2;
		}
		for (j = 0; j < 100; j++)
		{
			if (i == 0)
			{
				if (temp > 0)
				{
					if (j % 2 == 0)
					{
						a[i][j] = temp;
						temp = temp - 5;
					}
					else
					{
						a[i][j] = temp;
						temp = temp - 1;
					}
				}
			}
			if (i == 1)
			{
				if (temp > 0)
				{
					a[i][j] = temp;
					temp = temp - 3;
				}
			}
			if (i == 2)
			{
				if (temp > 0)
				{
					if (j % 2 != 0)
					{
						a[i][j] = temp;
						temp = temp - 5;
					}
					else
					{
						a[i][j] = temp;
						temp = temp - 1;
					}
				}

			}
		}
	}
	return a;
}

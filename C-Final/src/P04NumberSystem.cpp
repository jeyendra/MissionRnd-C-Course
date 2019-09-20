/*

 Problem code: P04NumberSystem
 Score: 15
 
 Let us consider we have designed a new number system which consist only 7 and 8
 your task is to find the Nth number in this number system
 
 The first 10 numbers are 7, 8, 77, 78, 87, 88, 777, 778, 787, 788.
 
 Example:
  Input:
  7
 
  Output:
  "777"

 Constraints:
    1 <= N < 10^15
    resulting number is in string format
 
 */

#include <stdio.h>
#include <stdlib.h>
int pow(long int n)
{
	if (n == 1)
	{
		return 0;
	}
	while (n % 2 == 0)
	{
		n = n / 2;
	}
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int upp( long int n)
{
	int c = 0;
	while (n % 2 == 0)
	{
		c++;
		n = n / 2;
	}
	return c;
}
long int nearpow(long int n)
{
	while (pow(n) != 1)
	{
		n = n - 1;
	}
	return n;
}
char *nth_number(unsigned long long int n) {
	char* ans = (char*)malloc(10000 * sizeof(char));
	long int near, i=0, j=0;
	for (i = 0; i < 10000; i++)
	{
		ans[i] = '0';
	}
	near = nearpow(n);
	int power = upp(near);
	near = n - near-1;
	printf("near %d\n", near);
	i = 0;
	printf("power %d\n", power);
	int power1 = power;
	power--;
	if (near % 2 != 0)
	{
		ans[power] = '0';
		power--;
	}
	while (near > 0)
	{
		ans[power] = (near % 2)+'0';
		near = near / 2;
		power = power - 1;
	}
	for (i = 0; i < power1; i++)
	{
		printf("%c", ans[i]);
	}
	for (j = 0; j < power1; j++)
	{
		if (ans[j] == '0')
		{
			ans[j] = '7';
		}
		else
		{
			ans[j] = '8';
		}
	}
	ans[power1] = '\0';
	return ans;
}

#include <stdlib.h>
#include <stdio.h>

#include "Functions.h"
/*int is_even(int k) {
	if (k % 2 == 0) {
		return 1;  // it's even
	}
	return 0;
}

int square(int k) {
	return k*k*k;
}
int upp1(unsigned long long int n)
{
	int c = 0;
	while (n % 2 == 0)
	{
		c++;
		n = n / 2;
	}
	return c;
}
int pow1(unsigned long long int n)
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
unsigned long long int nearpow1(unsigned long long int n)
{
	while (pow1(n)!=1)
	{
		n = n - 1;
	}
	return n;
}*/
int main(){
	printf("\n%s", nth_number(10));
	int k;
	scanf("%d", &k);
	return 0;
}

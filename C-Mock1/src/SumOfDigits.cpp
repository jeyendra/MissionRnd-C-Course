/*

  Maximum Marks: 30
  
  Problem code: Sum of Digits
  
  Problem Statement:
  Find the sum of digits of the given number in base N.
  Repeat this process till the sum of the digits becomes a single digit.
  e.g:
  ("123456", 10) => '3'
 
  sum of all the digits in (123456) is 21,
  since it has more than one digit, we repeat the process.
  sum of all the digits in (21) is 3,
  so return '3'

  ("abc", 16) => a + b + c => 21 => '3'
  ("101", 2) => 1 + 0 + 1 => 10 => '1'
  ("xyz", 36) => x + y + z => 2u => 2 + u => 'w'

  Returns the single digit as character.

  2 <= base <= 36
  1 <= number of digits in 'number' <= 10000
*/
int len(char* s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}
void convert(char* s, int base)
{
	int i, j, k,ans=0;
	i = j = k = 0;
	char temp[1000];
	while (s[i] != '\0')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			ans = ans + (s[i] - '0');
		}
		else
		{
			ans += (s[i] - ('a' - 10));
		}
		i++;
	}
	while (ans > 0)
	{
		if ((ans%base) > 9)
		{
			temp[j] = (ans%base-10) + ('a');
		}
		else
		{
			temp[j] = ans%base+'0';
		}
		ans = ans / base;
		j++;
	}
	temp[j] = '\0';
	i = 0;
	for (i = j - 1; i >= 0; i--)
	{
		s[k] = temp[i];
		k++;
	}
	s[k] = '\0';
}
char sumOfDigits(char number[], int base) {
	int i, j, k;
	i = j = k = 0;
	while (len(number) != 1)
	{
		convert(number, base);
	}
	return number[0];
}

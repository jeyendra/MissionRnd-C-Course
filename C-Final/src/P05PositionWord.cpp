/*
 
 Problem code: P05PositionWord
 Score: 20
 
 Given two sentences, find the word in the first sentence
 which repeat position number of times in second sentence.

 Example#1:
 Input:
 sentence-1: "coding hero",
 sentence-2: "movie hero is hero only"
 
 Output:
 "hero"  // repeats 2 times, position in sentence-1 is also 2.
 
 Example#2:
 Input:
 sentence-1: "we are cool or hot",
 sentence-2: "we might be cool but are we cool are we really cool"
 
 Output:
 "are"
 
 Description:
 Here the repeatitions
 "are"  - 2 times and position in sentence-1 is also 2
 "cool" - 3 times and position in sentence-1 is also 3

 We have more than one, return the first word in the first sentence.
 i.e. "are"
 
 Example#3:
 Input:
 sentence-1: "we are great",
 sentence-2: "you are a great coder"
 
 Output:
 NULL
 
 Description:
 no word in sentence-1 is repeating position number of times in sentence-2.
 
 Constraints:
 - The sentence1 and sentence2 are not NULL and valid C strings,
   contains only 'a-z' small characters and spaces only. Nothing else.
 - When there are more than one word matching the constraints,
   return the first word in the first sentence.
 - Return NULL, when there is no word matching the constraints.
*/

#include <stdio.h>
#include <stdlib.h>
int getfreq(char* s, char* s1)
{
	int i, j, k,ans=0;
	i = j = k = 0;
	char s2[100];
	while (s[i]!='\0')
	{
		while (s[i] != ' ')
		{
			s2[k] = s[i];
			i++;
			k++;
		}
		s2[k] = '\0';
		int flag = 0;
		for (j = 0; s[j] != '\0'; j++)
		{
			if (s2[j] != s1[j])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			ans++;
		}
		i++;
	}
	return ans;
}
char *word_repeating_pos_times(char *sentence1, char *sentence2) {
	int i, j, k,freq=0, count = 1;
	i = j = k = 0;
	char* s = (char*)malloc(100 * sizeof(char));
	char* s1 = (char*)malloc(100 * sizeof(char));
	while( sentence1[i] != '\0')
	{
		while (sentence1[j] != ' ' && sentence1[j]!='\0')
		{
			s[j] = sentence1[i];
			j++;
			i++;
		}
		if (sentence1[i-1] == ' '&&sentence1[i]=='\0')
		{
			s[j] = '\0';
			if (count == getfreq(sentence2, s))
			{
				return s;
			}
		}
		i++;
		count++;
	}
}

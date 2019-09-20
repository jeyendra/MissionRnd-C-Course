/*
 Problem Code: P02Burglary
 Score: 15
 
 As Vizag became the smart city the number of jewelery individuals are increasing
 in order to attract people nearby.
 To stop the fear of burglars, stealing the property from the shops, sensors have
 been arranged to notify (if gold is taken out of the place) when the shop is closed.
 Mr.Jay has been assigned to write an algorithm to catch the burglar before he
 completely escapes.
 Each building is designed in a way such that the burglar should jump W walls
 with varying heights.
 A healthy and stout person can crawl C feet per minute and slips back by S feet.
 How many minutes does it take for a burglar to escape after he loots the gold.
 This output is used to reach the place before he escapes. Your task is to help
 Mr.Jay in writing the algorithm inorder to catch the burglar.


 Input Format:

 Each test case contains four input parameters namely crawl, slip, walls, heights[].
    crawl (C) - number of feet the burglar crawls
    slip (S) - number of feet the burglar slips
    walls (W) - total number of walls
    heights[] - an array containg the heights of the walls.


 Constraints:

 1 <= crawl, slip <= 100000
 1 <= walls <= 100
 1 <= heights[] <= 100000


 Output Format:

 Return the total number of minutes required to escape for the burglar.

 Sample Input 0:

 crawl = 7, slip = 2, walls = 4
 heights = {5, 2, 13, 1}

 Sample Output 0:

 6

 Explanation 0:

 The first wall(1) can be jumped in 1 minute, second wall(2) can be jumped in 1 minute,
 third wall(13) can be jumped in 3 minutes and last wall(1) can be jumped in 1 minute.
 So, total it takes 6 minutes for the burglar to loot the gold.

 Sample Input 1:

 crawl = 10, slip = 1, walls = 7
 heights = {16, 19, 9, 12, 4, 15, 6}

 Sample Output 1:
 
 11

 Explanation 1:

 The height of the wall and minutes taken to jump the each wall are respectively:
 16 - 2, 19 - 2, 9 - 1, 12 - 2, 4 - 1, 15 - 2, 6 - 1

*/

#include <stdio.h>
#include <stdlib.h>

int number_of_minutes(int crawl, int slip, int walls, int heights[])
{
	int i, j, k,ans=0;
	for (i = 0; i < walls; i++)
	{
		if (heights[i] <= crawl)
		{
			ans += 1;
		}
		else
		{
			while (heights[i]>crawl)
			{
				ans++;
				heights[i] = heights[i] - crawl + slip;
			}
			if (heights[i] != 0)
			{
				ans++;
			}
		}
	}
	return ans;
}

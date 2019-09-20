/*
	Maximum Marks: 15
	
	Problem Code: MeetingPoint

	There is a girl called Maya who is a big fan of Deepika .(The heroine).
	Maya always wanted to meet her and go on a tour of cities with her.
	She has been dreaming about this from childhood.

	At last Maya got to know that, Deepika is going to tour india and she stops in several cities.
	Ie KanyaKumari->Kochi->Ooty->Mysore->Bangalore->Hyderabad->Bhopal
	At the same time even Maya is travelling with her family, 
	and her family not being much travelled before, Only knows how to travel from some cities to another.
	So Maya's family planned their trip in a different route from what Deepika is going .
	Ie Tirupati->Bhimvaram->Vijayawada->Vizag->Hyd->Bhopal 


	Maya later came to know that her route will intersect with Deepika's Route and 
	after the intersection point they are going to travel along the same route.

	Ie if Deepika Route is A->B->C->D->E->F->G->H
	Maya Route is Z->Y->E->F->G->H

	Both Maya and Deepika meet at 'E' city.And travel remaining cities F, G, H together.


	But Maya being not that into problem solving, She wants you to help to know in 
	which city she can meet her star, given the 2 routes she and Deepika are going 
	to travel and also how many cities she had to travel to meet Deepika.
	
	Can you write a program which will fulfill her dream ?


	Struct CityNode{
	Char * city[20];
	Sturct node * nextCity;
}

CityNode will have a city name and address of the next city.

Note:
	Two CityNode's can have same name but will have different address (reference).
	Don't create any new nodes.
*/

/**
Return the meeting city node if maya can meet deepika, or else NULL.
*/

#include "BinaryTree.h"
int lenLL(struct CityNode *head)
{
	struct CityNode *temp = head;
	int len = 0;
	while (temp != NULL)
	{
		len++;
		temp = temp->nextCity;
	}
	return len;
}
int strcp(char* s1, char* s2)
{
	int i;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return 0;
		}
	}
	return 1;
}
struct CityNode * meetingPoint(struct CityNode * deepikaStartCity, struct CityNode *mayaStartCity, int *numberOfCitiesMayaShouldTravel) {
	int num=0,i=0, j=0, k=0, lendeepu=0, lenmaya=0;
	lendeepu = lenLL(deepikaStartCity);
	lenmaya = lenLL(mayaStartCity);
	int temp = lendeepu - lenmaya;
	if (temp > 0)
	{
		while (temp > 0)
		{
			deepikaStartCity = deepikaStartCity->nextCity;
			temp--;
		}
	}
	if (temp < 0)
	{
		temp = temp*(-1);
		num = temp;
		while (temp > 0)
		{
			mayaStartCity = mayaStartCity->nextCity;
			temp--;
		}
	}
	while (deepikaStartCity != NULL)
	{
		if (deepikaStartCity->city==mayaStartCity->city)
		{
			if (deepikaStartCity->nextCity->city== mayaStartCity->nextCity->city)
			{
				numberOfCitiesMayaShouldTravel[0] = num;
				return deepikaStartCity;
			}
		}
		deepikaStartCity = deepikaStartCity->nextCity;
		mayaStartCity = mayaStartCity->nextCity;
		num++;
	}
	numberOfCitiesMayaShouldTravel[0] = -1;
	return NULL;
}

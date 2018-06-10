//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass2
//	Class: CS 133C				Assignment #: 2
//	Class Time: 10:00am
//	Date:	1/19/2014
//	Program Name: random.c
//	Program Description: User guesses number with 5 tries
//**********************************************************************

#include <stdio.h>
#include <time.h>   /* for time() */ 
#include <stdlib.h> /* for rand() and srand() */ 

int main(int argc, char const *argv[])
{
	int x, count, guess, temp;
	count = 5, guess = -1;
  	srand(time(NULL)); /* seeds our random number generator using the system clock, IMPORTANT: do this just once */
  	
  	x = rand()%50+1; 
  	
  	printf("\n\nGuess an integer between 1 and 50.\n");
  	while(guess != x && count > 0)
  	{	
  		if (count>1)
  		{
  			printf("\nYou have %d tries. Enter a number:____\b\b\b", count);
  		}
  		else
  			printf("\nYou have %d try left. Enter a number:____\b\b\b", count);
  		
  		scanf("%d", &guess);
  		while(guess>50 || guess<1)
  		{
  			printf("\nContrary to popular belief, %d is not between 1 and 50.\n", guess);
  			printf("\n\nYou still have %d tries left. Try again____\b\b\b", count);
  			scanf("%d", &guess);
  		}
  		if (guess<x&&count>1)
		{
			printf("\nThe integer is greater than %d\n\n", guess);
		}
		else if (guess>x&&count>1)
		{
			printf("\nThe integer is less than %d\n\n", guess);
		}
		else if (guess==x)
		{
			printf("\n\n**********************************************************\n");
			printf("**	Congratulation! %d is the correct number\t**\n", guess);
			printf("**********************************************************\n");
		}
		if (guess!=x&&count==1)
		{
			printf("\n\n\nFail. It was %d", x);
		}
  		count--;
  	}
  	printf("\n\n");

	return 0;
}

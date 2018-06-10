//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass1
//	Class: CS 133C				Assignment #: 1
//	Class Time: 10:00am
//	Date:	1/11/2014
//	Program Name: smile.c
//	Program Description: Prints smile
//**********************************************************************

#include <stdio.h>	// preprocessor directive
void smile(void);

int main(void)
{
	int count, i;
	count = 5;
	for (i = 0; i < 6; ++i)
	{
		smile();
		if(count==3 || count==1)
			printf("\n");
		count--;
	}
	return 0;
}
void smile(void)
{
	printf("Smile!");
}
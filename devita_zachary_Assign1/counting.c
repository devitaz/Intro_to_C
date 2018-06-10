//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass1
//	Class: CS 133C				Assignment #: 1
//	Class Time: 10:00am
//	Date:	1/11/2014
//	Program Name: counting.c
//	Program Description: Prints words one, two, three
//**********************************************************************

#include <stdio.h>	// preprocessor directive
void one_three(void);

int main(void)	//
{
	printf("starting now:\n");
	one_three();
	printf("done!");
	
	return 0;
}
void two(void);
void one_three(void)
{
	printf("one\n");
	two();
	printf("three\n");
}
void two(void)
{
	printf("two\n");
}
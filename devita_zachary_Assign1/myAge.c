//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass1
//	Class: CS 133C				Assignment #: 1
//	Class Time: 10:00am
//	Date:	1/11/2014
//	Program Name: myAge.c
//	Program Description: Prints my age in years and also in days
//**********************************************************************

#include <stdio.h>	// preprocessor directive

int main(void)	//
{
	int years;
	int days;
	int DAYSINYEAR;
	DAYSINYEAR = 365; 
	years = 28;
	days =  DAYSINYEAR * years;
	printf("I am %d years old\nI am %d days old", years, days);
	return 0;
}
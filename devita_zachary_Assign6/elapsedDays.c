//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass6
//	Class: CS 133C				Assignment #: 6
//	Class Time: 10:00am
//	Date:	3/4/2014
//	Program Name: elapsedDays.c
//	Program Description: finds number of days between 2 dates
//**********************************************************************
#include <stdio.h>


struct date
{
	int year, month, day;
};
int dateConvert(struct date);
int f(int, int);
int g(int);

int main(int argc, char const *argv[])
{
	int num1, num2;
	struct date early, later;

	printf("\n\nEnter two dates to find the number of days between them.\n");
	printf("Enter the first date.\n");
	printf("\nEnter the month(Ex: for March enter a '3').____\b\b\b");
	scanf("%d", &early.month);
	printf("\nEnter the day.____\b\b\b");
	scanf("%d", &early.day);
	printf("\nEnter the year(Ex: 2001).______\b\b\b\b\b");
	scanf("%d", &early.year);

	printf("\n\nEnter the second date.\n");
	printf("\nEnter the month(Ex: for March enter a '3').____\b\b\b");
	scanf("%d", &later.month);
	printf("\nEnter the day.____\b\b\b");
	scanf("%d", &later.day);
	printf("\nEnter the year(Ex: 2001).______\b\b\b\b\b");
	scanf("%d", &later.year);

	num1 = dateConvert(early);
	num2 = dateConvert(later);

	if(num1>=num2)
		printf("\n\n%d days have elapsed between the 2 dates\n\n", num1-num2);
	else
		printf("\n\n%d days have elapsed between the 2 dates\n\n", num2-num1);

	return 0;
}
int dateConvert(struct date theDate)
{
	return 1461*f(theDate.year, theDate.month)/4+153*g(theDate.month)/5+theDate.day;
}
int f(int year, int month)
{
	if(month<=2)
		return year-1;
	return year;
}
int g(int month)
{
	if(month<=2)
		return month+13;
	return month+1;
}
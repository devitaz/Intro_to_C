//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass6
//	Class: CS 133C				Assignment #: 6
//	Class Time: 10:00am
//	Date:	3/4/2014
//	Program Name: dayOfWeek.c
//	Program Description: finds the day of the week for given date
//**********************************************************************
#include <stdio.h>
#define SUNDAY "Sunday"
#define MONDAY "Monday"
#define TUESDAY "Tuesday"
#define WEDNESDAY "Wednesday"
#define THURSDAY "Thursday"
#define FRIDAY "Friday"
#define SATURDAY "Saturday"
struct date
{
	int year, month, day;
};
void dateConvert(struct date);
int f(int, int);
int g(int);
void theDay(int);

int main(int argc, char const *argv[])
{
	struct date input;

	printf("\n\nEnter a date to find which day of the week it is.\n");
	printf("\nEnter the month(Ex: for March enter a '3').____\b\b\b");
	scanf("%d", &input.month);
	printf("\nEnter the day.____\b\b\b");
	scanf("%d", &input.day);
	printf("\nEnter the year(Ex: 2001).______\b\b\b\b\b");
	scanf("%d", &input.year);
	printf("\n\n\n %d/%d/%d is a ", input.month, input.day, input.year);

	dateConvert(input);
	printf("\n\n");
	
	return 0;
}
void dateConvert(struct date theDate)
{
	int temp;
	temp = 1461*f(theDate.year, theDate.month)/4+153*g(theDate.month)/5+theDate.day;
	temp = (temp-621049) % 7;
	theDay(temp);
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
void theDay(int someNum)
{
	if(someNum == 0)
		printf("%s\n", SUNDAY);
	else if(someNum == 1)
		printf("%s\n", MONDAY);
	else if(someNum == 2)
		printf("%s\n", TUESDAY);
	else if(someNum == 3)
		printf("%s\n", WEDNESDAY);
	else if(someNum == 4)
		printf("%s\n", THURSDAY);
	else if(someNum == 5)
		printf("%s\n", FRIDAY);
	else if(someNum == 6)
		printf("%s\n", SATURDAY);
}

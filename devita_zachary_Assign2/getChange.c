//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass2
//	Class: CS 133C				Assignment #: 2
//	Class Time: 10:00am
//	Date:	1/19/2014
//	Program Name: yourChange.c
//	Program Description: Breaks user input float into change
//**********************************************************************

#include <stdio.h>
void change(unsigned int);

int main(int argc, char const *argv[])
{
	float userInput;
	unsigned int temp;
	
	printf("\n\nInput dollar amount to get change. $_________\b\b\b\b\b\b\b\b");
	scanf("%f", &userInput);
	while(userInput < 0)
	{
		printf("Invalid Input. Number must be positive.\n");
		printf("Try again. $_________\b\b\b\b\b\b\b\b");
		scanf("%f",&userInput);
	}
	printf("\nYou entered $%.2f\n\n\n", userInput);

	temp = (unsigned int)(userInput*100);
	change(temp);
	printf("\n\n");

	return 0;
}
void change(unsigned int x)
{
	int twenties, tens, fives, ones, quarters, dimes, nickels, pennies;
	unsigned int tempTotal;
	tempTotal = x;

	if(x>2000)
	{
		twenties = x/2000;
		tempTotal = x%2000;
		printf("Twenties: %d  ",twenties);
	}
	if(tempTotal>1000)
	{
		tens = tempTotal/1000;
		tempTotal = tempTotal%1000;
		printf("Tens: %d  ",tens);
	}
	if(tempTotal>500)
	{
		fives = tempTotal/500;
		tempTotal = tempTotal%500;
		printf("Fives: %d  ",fives);
	}
	if(tempTotal>100)
	{
		ones = tempTotal/100;
		tempTotal = tempTotal%100;
		printf("Ones: %d  ",ones);
	}
	if(tempTotal>25)
	{
		quarters = tempTotal/25;
		tempTotal = tempTotal%25;
		printf("Quarters: %d  ",quarters);
	}
	if(tempTotal>10)
	{
		dimes = tempTotal/10;
		tempTotal = tempTotal%10;
		printf("Dimes: %d  ",dimes);
	}
	if(tempTotal>5)
	{
		nickels = tempTotal/5;
		tempTotal = tempTotal%5;
		printf("Nickels: %d  ",nickels);
	}
	if(tempTotal>=1)
	{	
		pennies = tempTotal;
		printf("Pennies: %d",pennies);
	}
}
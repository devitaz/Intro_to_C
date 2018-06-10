//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass4
//	Class: CS 133C				Assignment #: 4
//	Class Time: 10:00am
//	Date:	2/16/2014
//	Program Name: baseConverter.c
//	Program Description: Computes numbers to any base between 2 and 10
//**********************************************************************
#include <stdio.h>
#include <ctype.h>
void to_base_n(unsigned long, int);

int main(int argc, char const *argv[])
{
	unsigned long number = 1, answer; 
	int base_n=10;

	printf("\n\n\nEnter a positive integer (q to quit):_______\b\b\b\b\b\b");
	
	while (scanf("%lu", &number)==0);
	{
		printf("\n\n");
		printf("Enter which base to convert %lu to (between 2 and 10):_____\b\b\b", number);
		scanf("%d", &base_n);
		printf("\n\n");
		;
		printf("%lu converted to base %d is ", number, base_n);
		to_base_n(number, base_n);
	}
	return 0;
}
void to_base_n(unsigned long num, int base)
{
	int r;

	r = num%base;
	if(num>=base)
		to_base_n(num/base, base);
	putchar('0' + r);
	return;
}
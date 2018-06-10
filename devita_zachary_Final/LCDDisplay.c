//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Final
//	Class: CS 133C				Assignment #: Final
//	Class Time: 10:00am
//	Date:	3/6/2014
//	Program Name: LCDDisplay.c
//	Program Description: Prints numbers in LCD Display style
//**********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
int digits = 2;
void convertNum(int, int);
void seperateDigits(int *anArray, int, int);
void printLCD(int *anArray, int);


int main(int argc, char const *argv[])
{
	char charNum[10], charSize[10];
	int size = 5;
	long int number = 10; 
	bool isNum = 0, isSize = 0;
	charNum[0] = '|', charSize[0] = '|';

	while(size != 0)
	{
		printf("\n\nEnter an integer to convert it to LCD Display.\n");
		printf("Enter integer between 1 and 99,999,999 here_________\b\b\b\b\b\b\b\b");
	
		while(isNum==0 || number<1 || number>99999999)
		{
			if(charNum[0]!='|')
			{
				printf("Must enter an integer between 1 and 99,999,999.\n");
				printf("Try Again._________\b\b\b\b\b\b\b\b");
			}			
			fgets(charNum,sizeof(charNum),stdin);
			printf("\n\n");
			for (int z = 0; z < strlen(charNum)-1; ++z)
			{
				if(isdigit(charNum[z]))
					isNum = true;
				else
				{
					isNum = false;
					break;
				}
			}
			if(isNum==1)
				number = strtod(charNum, NULL);
		}
		printf("Now you must enter a font size.\n");
		printf("You may enter a zero to quit.\n\n");
		printf("Enter a size between 1 and 10 here.____\b\b\b");
	
		while(isSize==0 || size<0 || size>10)
		{
			if(charSize[0]!='|')
			{
				printf("Must enter an integer between 1 and 10.\n");
				printf("You may enter a '0' to quit.\n\n");
				printf("Try Again._________\b\b\b\b\b\b\b\b");
			}			
			fgets(charSize,sizeof(charNum),stdin);
			if(charNum[0] = 0)
				exit(0);
			printf("\n\n");
			for (int x = 0; x < strlen(charSize)-1; ++x)
			{
				if(isdigit(charSize[x]))
					isSize = 1;
				else
				{
					isSize = 0;
					break;
				}
			}
			if(isSize==1)
				size = strtod(charSize, NULL);
		}
	isNum = isSize = 0;
	isSize = 0;
	charNum[0] = charSize[0] = '|';
	convertNum(number, size);
	}	
	return 0;
}
void convertNum(int input, int font)
{
	int *numArray;

	if(input<10)
		digits = 1;
	else if(input<100)
		digits = 2;
	else if(input<1000)
		digits = 3;
	else if(input<10000)
		digits = 4;
	else if(input<100000)
		digits = 5;
	else if(input<1000000)
		digits = 6;
	else if(input<10000000)
		digits = 7;
	else if(input<100000000)
		digits = 8;
	
	numArray = (int*)malloc(sizeof(int)*digits);
	seperateDigits(numArray, input, digits);
	printLCD(numArray, font);
	free(numArray);
}
void seperateDigits(int *anArray, int original, int numOfDigits)
{
	if(numOfDigits == 0)
		return;
	*(anArray+(digits-numOfDigits)) = original / (int)pow(10, numOfDigits-1);
	seperateDigits(anArray, (original%(int)pow(10, numOfDigits-1)), numOfDigits-1);
}
void printLCD(int *anArray, int font)
{
	int columns = font+2;
	int rows = 2*font+3;

	for (int i = 0; i < digits; ++i)
	{
		printf(" ");
		if(*(anArray+i)==1||*(anArray+i)==4)
			for(int j = 0; j < columns-2; j++)
				printf(" ");
		else
			for(int j = 0; j < columns-2; j++)
				printf("-");
		printf("  ");
	}
	printf("\n");
	for(int a = 0; a < font; a++)
	{
		for(int k = 0; k < digits; ++k)
		{
			if(*(anArray+k)==1||*(anArray+k)==2||*(anArray+k)==3||*(anArray+k)==7)
			{
				for(int l = 0; l < columns-1; l++)
					printf(" ");
				printf("|");
			}
			else if(*(anArray+k)==5||*(anArray+k)==6)
			{	
				printf("|");
				for(int l = 0; l < columns-1; l++)
					printf(" ");
			}
			else
			{
				printf("|");
				for(int l = 0; l < columns-2; l++)
					printf(" ");
				printf("|");
			}
			printf(" ");
		}
		printf("\n");
	}
	for (int b = 0; b < digits; ++b)
	{
		printf(" ");
		if(*(anArray+b)==1||*(anArray+b)==7||*(anArray+b)==0)
			for(int c = 0; c < columns-2; c++)
				printf(" ");
		else
			for(int c = 0; c < columns-2; c++)
				printf("-");
		printf("  ");
	}
	printf("\n");
	for(int d = 0; d < font; d++)
	{
		for(int f = 0; f < digits; ++f)
		{
			if(*(anArray+f)==2)
			{
				printf("|");
				for(int g = 0; g < columns-1; g++)
					printf(" ");
			}
			else if(*(anArray+f)==6||*(anArray+f)==8||*(anArray+f)==0)
			{	
				printf("|");
				for(int g = 0; g < columns-2; g++)
					printf(" ");
				printf("|");
			}
			else
			{
				for(int g = 0; g < columns-1; g++)
					printf(" ");
				printf("|");
			}
			printf(" ");
		}
		printf("\n");
	}
	for (int h = 0; h < digits; ++h)
	{
		printf(" ");
		if(*(anArray+h)==1||*(anArray+h)==4||*(anArray+h)==7)
			for(int e = 0; e < columns-2; e++)
				printf(" ");
		else
			for(int e = 0; e < columns-2; e++)
				printf("-");
		printf("  ");
	}
	printf("\n");
}

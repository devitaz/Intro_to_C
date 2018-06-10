//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass4
//	Class: CS 133C				Assignment #: 4
//	Class Time: 10:00am
//	Date:	2/13/2014
//	Program Name: charReader.c
//	Program Description: Reads characters and if letters will determines  
//						 their numeric location in the alphabet
//**********************************************************************
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void charInvestigator(char);

int main(int argc, char const *argv[])
{
	char userInput[41]; 

	printf("\n\n\nEnter a string of no more than 40 character.\n\n");
	fgets(userInput,sizeof(userInput),stdin);
	printf("\n\n");

	for (int i = 0; i < strlen(userInput)-1; ++i)
	{
		printf("%c - ", userInput[i]);
		charInvestigator(userInput[i]);
		printf("\n");
	}
	return 0;
}
void charInvestigator(char a)
{
	int index;

	if(isspace(a))
		printf("This is a space: -1");
	if(ispunct(a))
		printf("This is a punctuation character: -1");
	if(isdigit(a))
		printf("This is a number: -1");
	if(isalpha(a))
	{
		index = toupper(a)-64;
		printf("This is the %d letter in the alphabet.", index);
	}
}
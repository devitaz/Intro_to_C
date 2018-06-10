//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Final
//	Class: CS 133C				Assignment #: Final
//	Class Time: 10:00am
//	Date:	3/13/2014
//	Program Name: minesweeper.c
//	Program Description: input minesweeper config and program produces result
//**********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char **field;
void processField(int, int);

int main(int argc, char const *argv[])
{
	int rows, columns;

	printf("\n\nThis is Minesweeper. First you will enter the number of\n");
	printf("rows desired then the number of columns to make your field.\n");
	printf("For each row, only enter '.'s for safe spaces and '*' for mines. \n");
	printf("Any other input will be considered a safe space as well.\n\n\n");

	printf("Enter the number of rows._____\b\b\b\b");
	scanf("%d%*c", &rows);
	printf("\n");
	printf("Enter the number of columns._____\b\b\b\b");
	scanf("%d%*c", &columns);
	printf("\n\n\n");

	field = (char **)malloc(rows * sizeof(char *));
	for (int i = 0; i < rows; ++i)
	{
		field[i] = (char *)malloc(columns+2);
		printf("Enter row %d: ", i+1);
		fflush(stdin);
		fgets(field[i], columns+1, stdin);
		printf("\n");
	}
	processField(rows, columns);
	free(field);

	return 0;
}
void processField(int rows, int columns)
{
	char outputArray[rows+2][columns+2];

	for (int l = 0; l < rows+2; ++l)
		for (int m = 0; m < columns+2; ++m)
			outputArray[l][m] = '0';	

	for (int j = 1; j <= rows; ++j)
		for (int k = 1; k <= columns; ++k)
			if(field[j-1][k-1]=='*')
			{
				outputArray[j-1][k-1]++;
				outputArray[j][k-1]++;
				outputArray[j+1][k-1]++;
				outputArray[j-1][k]++;
				outputArray[j+1][k]++;
				outputArray[j-1][k+1]++;
				outputArray[j][k+1]++;
				outputArray[j+1][k+1]++;
			}

	for (int j = 1; j <= rows; ++j)
		for (int k = 1; k <= columns; ++k)
			if(field[j-1][k-1]=='*')
				outputArray[j][k] = '*';
			
	for (int h = 1; h <= rows; ++h)
	{
		for (int i = 1; i <= columns; ++i)
			printf("%c", outputArray[h][i]);	
		printf("\n");
	}
}
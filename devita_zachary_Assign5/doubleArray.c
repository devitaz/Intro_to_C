//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass5
//	Class: CS 133C				Assignment #: 5
//	Class Time: 10:00am
//	Date:	2/23/2014
//	Program Name: notations.c
//	Program Description: function copies 2-dimensional array
//**********************************************************************
#include <stdio.h>
void *copyArray(double[][9], double[][9], int, int);

int main(int argc, char const *argv[])
{
	double myArray[5][9] =
	{
		{3.7,2.8,9.5,5.9,8.6,6.5,2.8,3.4,5.1},
		{4.7,6.5,1.5,2.9,6.3,5.3,8.7,3.1,6.0},
		{4.4,3.6,7.5,5.8,8.3,1.8,2.3,4.6,3.0},
		{2.2,5.8,6.5,7.2,6.4,7.4,6.4,7.7,1.1},
		{3.1,3.6,5.8,5.2,7.3,7.7,8.4,6.3,3.7}
	};
	double targetArray[5][9];

	copyArray(myArray, targetArray, 5, 9);

	
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			printf("%g\t", targetArray[i][j]);
		}

		printf("\n\n");
	}
	printf("\n\n");

	return 0;
}
void *copyArray(double original[][9], double target[][9], int row, int column)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < column; ++j)
		{
			target[i][j] = original[i][j];
		}
	}
}
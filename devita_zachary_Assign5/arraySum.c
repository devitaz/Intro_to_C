//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass5
//	Class: CS 133C				Assignment #: 5
//	Class Time: 10:00am
//	Date:	2/23/2014
//	Program Name: arraySum.c
//	Program Description: fills array with sum of 2 other arrays
//**********************************************************************
#include <stdio.h>
int *arraySum(int[], int[], int[], int);

int main(int argc, char const *argv[])
{
	int first[5] = {2, 3, 9, 0, 8};
	int second[5] = {2, 0, 8, 1, 6};
	int sum[5];

	arraySum(first, second, sum, 5);
	
	printf("\n\nThe sum of the 2 arrays\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%d\t", sum[i]);
	}
	printf("\n\n");

	return 0;
}
int *arraySum(int one[], int two[], int total[], int elements)
{
	for (int i = 0; i < elements; ++i)
	{
		total[i] = one[i] + two[i];
	}
	return total;
}
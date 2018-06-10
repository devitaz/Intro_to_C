//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass5
//	Class: CS 133C				Assignment #: 5
//	Class Time: 10:00am
//	Date:	2/23/2014
//	Program Name: notations.c
//	Program Description: Uses pointer notation and array notation functions
//**********************************************************************
#include <stdio.h>
double *arrayNotation(double[], double[], int);
double *pointerNotation(double*, double*, int);

int main(int argc, char const *argv[])
{
	double myArray[5] = {1.7, 2.4, 3.1, 4.9, 5.6};
	double noteArray[5]; 
	double notePointer[5]; 

	arrayNotation(myArray, noteArray, 5);
	pointerNotation(myArray, notePointer, 5);
	
	printf("Array Notation function:\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%g\t", noteArray[i]);
	}
	printf("\n\n");
	
	printf("Pointer Notation function:\n");
	for (int i = 0; i < 5; ++i)
	{
		printf("%g\t", *(notePointer+i));
	}
	printf("\n\n");

	return 0;
}
double *arrayNotation(double original[], double target[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		target[i] = original[i];
	}
	return target;
}
double *pointerNotation(double* original, double* target, int count)
{
	for (int i = 0; i < count; ++i)
	{
		*(target+i) = *(original+i);
	}
	return target;
}
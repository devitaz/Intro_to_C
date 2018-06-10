//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass6
//	Class: CS 133C				Assignment #: 6
//	Class Time: 10:00am
//	Date:	3/4/2014
//	Program Name: sortArray.c
//	Program Description: dynamically allocate strings & sort user input
//**********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LENGTH 41
void strSort(char *myArray[], char *target[], int number, int strlength);
int stricmp (const char *s1, const char *s2);

int main(int argc, char const *argv[])
{
	int num;
	char **ptr, **sortedArray;
	char toNum[5];
	
	printf("\n\nEnter desired number of strings._____\b\b\b\b");
	fgets(toNum, sizeof(toNum), stdin);
	num = strtod(toNum, NULL);
	printf("\n\n");
	while(num<1 || num>10)
	{
		printf("Number must be between 1 and 10. Try again._____\b\b\b\b");
		fgets(toNum, sizeof(toNum), stdin);
		num = strtod(toNum, NULL);
		printf("\n");
	}
	ptr = (char **) malloc(num * sizeof(char *));
	for (int i = 0; i < num; ++i)
	{
		ptr[i] = (char *)malloc(LENGTH+1);
		printf("\nEnter string %d: ", i+1);
		fgets(ptr[i], LENGTH, stdin);
	}
	strSort(ptr, sortedArray, num, LENGTH);
	for (int j = 0; j < num; ++j)
	{
			printf("%s\n", ptr[j]);
	}
	
	free(ptr);

	return 0;
}
void strSort(char *myArray[], char *target[], int number, int strlength)
{
	char *temp;
	int top, seek;

	for (top = 0; top < number-1; top++)
	{
		for(seek = top+1; seek<number; seek++)
		{
			if(stricmp(myArray[top], myArray[seek]) > 0)
			{
				temp = myArray[top];
				myArray[top] = myArray[seek];
				myArray[seek] = temp;
			}
		}
	}
}
int stricmp (const char *one, const char *two)
{
   char c1, c2;

   if (one == NULL) return two == NULL ? 0 : -(*two);
   if (two == NULL) return *one;

   while ((c1 = tolower (*one)) == (c2 = tolower (*two)))
   {
     if (*one == '\0') break;
     ++one; ++two;
   }
   return c1 - c2;
}

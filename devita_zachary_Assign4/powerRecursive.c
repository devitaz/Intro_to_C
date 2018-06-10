//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass4
//	Class: CS 133C				Assignment #: 4
//	Class Time: 10:00am
//	Date:	2/16/2014
//	Program Name: powerRecursive.c
//	Program Description: Calculates exponents both positive and negative
//**********************************************************************
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
double power(double, int);

int main(int argc, char const *argv[])
{
	char num[10], exponent[5];
	long double final;
	float convNum;
	int convExponent;
	bool isDouble = 0, isInt = 0;
	num[1] = '|';
	exponent[1]='|';

	printf("\n\nEnter an integer or double between -20 and 20._____\b\b\b\b");
	
	while(convNum<-20 || convNum>20 || isDouble==0)
	{
		if(num[1]!='|')
			printf("Must enter an integer or double between -20 and 20. Try again._____\b\b\b\b");
		fgets(num,sizeof(num),stdin); 
		printf("\n\n");
		for (int i = 0; i < strlen(num)-1; ++i)
		{
			if(isdigit(num[i]) || num[i] == '.' || num[i] == '-')
				isDouble = 1;
			else
			{
				isDouble = 0;
				break;
			}	
		}
		if(isDouble==1)
			convNum = strtod(num, NULL);
	}
	
	printf("To what power would you like to raise %g._____\b\b\b\b", convNum);
	
	while(convExponent<-5 || convExponent>5 || isInt==0)
	{
		if(exponent[1]!='|')
			printf("Exponent needs to be between -5 and 5. Try again._____\b\b\b\b", num);
		fgets(exponent,sizeof(exponent),stdin);
		printf("\n\n");
		for (int i = 0; i < strlen(exponent)-1; ++i)
		{
			if(isdigit(exponent[i]) || exponent[i] =='-')
				isInt = 1;
			else
			{
				isInt = 0;
				break;
			}
		}
		if(isInt==1)
			sscanf(exponent, "%d", &convExponent);
	}
	if(convNum==0&&convExponent==0)
		printf("0 to the power 0 is undefined\n");
	else
	{
		final = power(convNum, convExponent);
		printf("%.4g to the power %d is %Lf\n",convNum, convExponent, final);
	}
	return 0;
}
double power(double n, int p)
{
	if(p==0&&n!=0)
		return 1;
	else if(p!=0&&n==0)
		return 0;
	else if(p>0)
		return n*=power(n, p-1);
	else if(p<0)
		return 1/power(n, -p);
	return n;
}
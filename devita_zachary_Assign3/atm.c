//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Ass3
//	Class: CS 133C				Assignment #: 3
//	Class Time: 10:00am
//	Date:	1/27/2014
//	Program Name: atm.c
//	Program Description: Program that simulates menu-driven ATM
//**********************************************************************

#include <stdio.h>
#include <ctype.h>
void userInput(char);
float deposit(float);
float withdrawal(float);
float getBalance(void);
void setBalance(float);
float balance = 1000.00;
float dep, wit = 0;

int main(int argc, char const *argv[])
{
	char option;
	option = '*';
	printf("\n\nCurrent Balance:\t$%.2f\n\n", balance);
	
	while(option != 'F')
	{	
		if(option!='*')
			printf("\n\n_________________________________________________________\n");
		printf("** Choose from the following options. **\n\n");
		printf("Display (B)alance\nMake (D)eposit\n");
		printf("Make (W)ithdrawal\n(F)inished, Return Card\n\n");
		printf("Enter a 'B', 'D', 'W' or 'F'.___\b\b");
		scanf(" %c", &option);
		option = toupper(option);
		while(option!='B' && option!='D' && option!='W' && option!='F')
		{
			printf("\nMust enter a B, D, W or F\n\nTry Again.___\b\b");
			scanf("%c", &option);
			option = toupper(option);
		}	
		userInput(option);
	}
	for (int i = 0; i < 200000000; ++i);
	printf("\n\n\n\7\7**:) <=8 You May Now Remove Your Card. 8=> (:**\7\7\7\7\n\n");
	return 0;
}
void userInput(char c)
{
	switch(c)
	{
		case 'B': 
			printf("\n\nCurrent Balance is:  $%.2f\n", balance);
			for (int i = 0; i < 200000000; ++i);
			break;
		case 'D': 
		{	printf("\n\nHow much would you like to deposit?  $_______\b\b\b\b\b\b");
			scanf("%f", &dep);
			deposit(dep);
			printf("\n\nCurrent Balance is:  $%.2f\n", balance);
			for (int i = 0; i < 200000000; ++i);
			break;
		}	
		case 'W':
		{	printf("\n\nHow much would you like to withdrawal?  $_______\b\b\b\b\b\b");
			scanf("%f", &wit);
			while((getBalance()-wit) < 0)
			{	
				printf("\nYour balance is ** $%.2f **.", balance);
				printf("\nYou cannot withdrawal more than your balance\n");
				printf("\n\nHow much would you like to withdrawal?  $_______\b\b\b\b\b\b");
				scanf("%f", &wit);
			}
			withdrawal(wit);
			printf("\n\nCurrent Balance is:  $%.2f\n", balance);
			for (int i = 0; i < 200000000; ++i);
		}
	}
}
float deposit(float add)
{
	setBalance(getBalance()+add);
}
float withdrawal(float subtract)
{
	setBalance(getBalance()-subtract);
}
float getBalance(void)
{
	return balance;
}
void setBalance(float x)
{
	balance = x;
}


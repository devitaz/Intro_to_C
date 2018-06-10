#include <stdio.h>
#include <ctype.h>
#include "defs.h"
#define LOW 0
#define HIGH 5
#define CHANGE 2
//void workover(int);
//int reset(int);
int reset(void);
int next(int);
int last(int);
int new(int);

int i = 1;

int main(int argc, char const *argv[])
{
	char c;
	int OTHER=0, DIGIT=2,ALPHA=3, EOL=4;

	//for (int i = 0; c=getchar())!='\n'&&c!=EOF; s[i++]=c)
	/*int i=0;
	while(c=getchar())!=EOF)
	{
		if(c=='\t') c=' ';
		i++;
	}*/

	
	//printf("%d\n", !OTHER);
	/*
	while((c=getchar())!='\n')
	{
		if(c==' ') continue;
		if(c=='\t') continue;
		if(c<'0') printf("%d", OTHER);
		if(c<='9') printf("%d", DIGIT);
		if(c<'a')printf("%d", OTHER);
		if(c<'z')printf("%d", ALPHA);
		printf("%d", OTHER);
	}
	printf("%d", EOL);*/
	
	/*
	while((c=getchar())!='\n')
	{
		if(isgraph(c))
		{
			if(c<'0')printf("%d", OTHER);
			if(c<='9')printf("%d", DIGIT);
			if(c<'a')printf("%d", OTHER);
			if(c<='z')printf("%d", ALPHA);
			printf("%d", OTHER);
		}
	}
	printf("%d", EOL);*/
	
	/*auto int i =1;
	PRINT1(d,i);
	{
		int i=2;
		PRINT1(d,i);
		{
			i+=1;
			PRINT1(d,i);
		}
		PRINT1(d,i);
	}
	PRINT1(d,i);*/
	/*
	auto int i=HIGH;
	reset(i/2);PRINT1(d,i);
	reset(i=i/2);PRINT1(d,i);
	i=reset(i/2);PRINT1(d,i);

	workover(i);PRINT1(d,i);*/

	auto int i,j;
	i=reset();
	for (j=1; j<= 3; j++)
	{
		PRINT2(d,i,j);
		PRINT1(d,next(i));
		PRINT1(d,last(i));
		PRINT1(d,new(i+j));
	}

	return 0;
}
/*void workover(int i)
{
	i=(i%i)*((i*i)/(2*i)+4);
	PRINT1(d,i);
}
int reset(int i)
{
	i=i<= CHANGE ? HIGH : LOW;
	return (i);
}*/
int reset()
{
	return(i);
}
int next(int j)
{
	return(j=j++);
}
int last(int j)
{
	static int i=10;
	return(j=i--);
}
int new(int i)
{
	auto int j=10;
	return(i=j+=i);
}
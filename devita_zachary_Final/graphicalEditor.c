//**********************************************************************
//	Name: Zachary DeVita		Folder Name: devita_zachary_Final
//	Class: CS 133C				Assignment #: Final
//	Class Time: 10:00am
//	Date:	3/8/2014
//	Program Name: graphicalEditor.c
//	Program Description: text "graphical editor" for command prompt
//**********************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char **window;
void newImage(int, int);
void clear(int, int);
void dot(int, int, char, int);
void vertLine(int, int, int, char, int);
void horLine(int, int, int, char, int);
void filRect(int, int, int, int, char, int);
void bucketFil(int, int, char, int, int);
void fill(int, int, char, char);
void save(char name[]);
void terminate(void);
void printWindow(int, int);
void boundsCheck(int *row, int *column);

int main(int argc, char const *argv[])
{
	char fileName[41];
	char initial, color, original;
	int x1, x2, y1, y2, rows, columns = -1;

	printf("\n\n\nThis program is a graphical editor for text.\n");
	printf("You must enter commands according to the instructions to get desired\n");
	printf("results. Be sure to seperate each part of a command with spaces.\n\n");
	printf("Create a new image to start.____________\b\b\b\b\b\b\b\b\b\b\b");

	while((initial = toupper(getchar()))!='X')
	{
		switch(initial)
		{
			case 'I':
				scanf("%d", &columns);
				scanf("%d", &rows);
				boundsCheck(&rows, &columns);
				newImage(rows, columns);
				break;
			case 'C':
				clear(rows, columns);
				printWindow(rows, columns);
				break;
			case 'L':
				scanf("%d", &x1);
				scanf("%d", &y1);
				scanf("%*c%c", &color);
				dot(x1, y1, color, rows);
				printWindow(rows, columns);
				break;
			case 'V':
				scanf("%d", &x1);
				scanf("%d", &y1);
				scanf("%d", &y2);
				scanf("%*c%c", &color);
				vertLine(x1, y1, y2, color, rows);
				printWindow(rows, columns);
				break;
			case 'H':
				scanf("%d", &x1);
				scanf("%d", &x2);
				scanf("%d", &y1);
				scanf("%*c%c", &color);
				horLine(x1, x2, y1, color, rows);
				printWindow(rows, columns);
				break;
			case 'K':
				scanf("%d", &x1);
				scanf("%d", &y1);
				scanf("%d", &x2);
				scanf("%d", &y2);
				scanf("%*c%c", &color);
				filRect(x1, x2, y1, y2, color, rows);
				printWindow(rows, columns);
				break;
			case 'F':
				scanf("%d", &x1);
				scanf("%d", &y1);
				scanf("%*c%c", &color);
				x1 = x1 - 1;
				y1 = y1 - 1;
				bucketFil(x1, y1, color, rows, columns);
				printWindow(rows, columns);
				break;
			case 'S':
				scanf("%*c%s", &fileName);
				save(fileName);
				break;
			case 'X':
				free(window);
				terminate();
				break;
			default:
				break;
		}
	}
	return 0;
}
void newImage(int rows, int columns)
{
	free(window);
	window = (char **) malloc(rows * sizeof(char *));
	for (int i = 0; i < rows; ++i)
	{
		window[i] = (char *)malloc(columns+1);
		for (int j = 0; j < columns; ++j)
			window[i][j] = '0';
	}
	printWindow(rows, columns);
}
void clear(int rows, int columns)
{
	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < columns; ++j)
			window[i][j] = '0';
}
void dot(int xCoord, int yCoord, char color, int row)
{
	window[yCoord-1][xCoord-1] = color;
}
void vertLine(int xCoord, int yCoord1, int yCoord2, char color, int row)
{
	int lower, higher;

	if (yCoord2>yCoord1)
	{
		higher = yCoord2;
		lower = yCoord1;
	}	
	else
	{
		higher = yCoord1;
		lower = yCoord2;
	}	
	for (int i = lower; i <= higher; ++i)
		window[i-1][xCoord-1] = color;
}
void horLine(int xCoord1, int xCoord2, int yCoord, char color, int row)
{
	int lower, higher;

	if (xCoord2>xCoord1)
	{
		higher = xCoord2;
		lower = xCoord1;
	}	
	else
	{
		higher = xCoord1;
		lower = xCoord2;
	}	
	for (int i = lower; i <= higher; ++i)
		window[yCoord-1][i-1] = color;
}
void filRect(int xCoord1, int xCoord2, int yCoord1, int yCoord2, char color, int row)
{
	int xlow, ylow, xhigh, yhigh;

	if (xCoord2>xCoord1)
	{
		xhigh = xCoord2;
		xlow = xCoord1;
	}	
	else
	{
		xhigh = xCoord1;
		xlow = xCoord2;
	}	

	if (yCoord2>yCoord1)
	{
		yhigh = yCoord2;
		ylow = yCoord1;
	}
	else
	{
		yhigh = yCoord1;
		ylow = yCoord2;
	}
	for (int i = ylow; i <= yhigh; ++i)
		for (int j = xlow; j <= xhigh; ++j)
			window[i-1][j-1] = color;
}
void bucketFil(int xCoord, int yCoord, char color, int rows, int columns)
{
	char original = window[xCoord][yCoord];
	window[xCoord][yCoord] = color;

	if( (xCoord<(rows-1)) && window[xCoord+1][yCoord] == original)
		bucketFil(xCoord+1,yCoord,color,rows,columns);	

	if((xCoord>0) && window[xCoord-1][yCoord] == original)
		bucketFil(xCoord-1,yCoord,color,rows,columns);	

	if( (yCoord<(columns-1)) && window[xCoord][yCoord+1] == original)
		bucketFil(xCoord,yCoord+1,color,rows,columns);	

	if( (yCoord>0) && window[xCoord][yCoord-1] == original)
		bucketFil(xCoord,yCoord-1,color,rows,columns);	
}
void save(char name[])
{
	printf("file saved.\n\n\t%s.bmp\n", name);
	printf("\n\nEnter command.____________\b\b\b\b\b\b\b\b\b\b\b");
}
void terminate(void)
{
	exit(0);
}
void printWindow(int rows, int columns)
{
	printf("\n\n");
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++j)
			printf("%c", window[i][j]);
		printf("\n");
	}
	printf("\n\nEnter command.____________\b\b\b\b\b\b\b\b\b\b\b");
}
void boundsCheck(int *row, int *column)
{
	while(*row<1||*row>50||*column<1||*column>100)
	{
		printf("\n\nError: Rows must be between 1 and 50.\n");
		printf("Columns must be integers between 1 and 100\n");
		printf("Enter image dimensions again (Ex: \"8 14\").______\b\b\b\b\b");
		scanf("%d%d", column, row);
	}
	return;
}

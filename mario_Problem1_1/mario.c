//TASK
/*Toward the beginning of World 1 - 1 in Nintendo’s Super Mario Brothers, Mario must hop over adjacent pyramids of blocks. Let’s recreate those pyramids in C, 
albeit in text, using hashes (#) for bricks. Each hash is a bit taller than it is wide, so the pyramids themselves will also be taller than they 
are wide.

allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.*/

#define _CRT_SECURE_NO_WARNINGS
//INCLUDES
#include <stdio.h>

//BREADCRUMBS
int GetHeight();
void BuildLine(int numHashesLeft, char line[]);
void PrintInitialSpaces(int numSpaces);
void PrintLine(char line[]);



//MAIN
int main(void)
{
	int height = GetHeight();
    for (int i = 1; i <= height; i++)
    {
        //initialise variables
        char line[19] = {'z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z','z', 'z'};
        int numSpaces = height - i;

        //call functions
        BuildLine(i, line);
        PrintInitialSpaces(numSpaces);
        PrintLine(line);
        printf("\n");
    }
}















//HELPER FUNCTIONS
int GetHeight()
{
    int h;
    do
    {
        printf("Enter positive integer between, 1 and 8 (inclusive): \n");
        scanf("%i", &h);
    } 
    while (h < 1 || h > 8);
    return h;
}

void BuildLine(int numHashesLeft, char line[])
{
    int lineSize = (numHashesLeft * 2) + 2;
    int lineMiddle = lineSize / 2;
    for (int i = 1; i <= lineSize; i++)
    {
        if (i == lineMiddle || i == lineMiddle + 1)
        {
            line[i-1] = ' ';
        }
        else
        {
            line[i-1] = '#';
        }
    }
}

void PrintInitialSpaces(int numSpaces)
{
    for (int i = 0; i < numSpaces; i++)
    {
        printf(" ");
    }   
}

void PrintLine(char line[])
{
    int i = 0;
    while (line[i] != 'z')
    {
        printf("%c", line[i]);
        i++;
    }
}

//BACKGROUND
/*Notice that we’ve stored the point values of each letter of the alphabet in an integer array named POINTS.
For example, A or a is worth 1 point (represented by POINTS[0]), B or b is worth 3 points (represented by POINTS[1]), etc.
Notice that we’ve created a prototype for a helper function called compute_score() that takes a string as input and returns an int. Whenever we would like to 
assign point values to a particular word, we can call this function. Note that this prototype is required for C to know that compute_score() exists later in the
program. In main(), the program prompts the two players for their words using the get_string() function. These values are stored inside variables named word1 and 
word2. In compute_score(), your program should compute, using the POINTS array, and return the score for the string argument. Characters that are not letters 
should be given zero points, and uppercase and lowercase letters should be given the same point values. For example, ! is worth 0 points while A and a are both 
worth 1 point. Though Scrabble rules normally require that a word be in the dictionary, no need to check for that in this problem! In main(), your program should
print, depending on the players’ scores, Player 1 wins!, Player 2 wins!, or Tie!.*/


#define _CRT_SECURE_NO_WARNINGS
//INCLUDES
#include <stdio.h>

//BREADCRUMBS
int ComputeScore(char word[]);
void CovertToUppercase(char word[]);
void PrintWinner(int score1, int score2);


//GLOBAL VARIABLES
// Points assigned to each letter of the alphabet
int pointsArray[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
char alphabetArray[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', };





//MAIN
int main(void)
{
    // Get input words from both players
    char word1[100];
    char word2[100];
    printf("Player 1: ");
    scanf("%s", &word1);
    printf("Player 2: ");
    scanf("%s", &word2);

    //Convert words to uppercase
    CovertToUppercase(word1);
    CovertToUppercase(word2);

    // Score both words
    int score1 = ComputeScore(word1);
    int score2 = ComputeScore(word2);

    //Print the winner
    PrintWinner(score1, score2);
}









//HELPER FUNCTIONS
void CovertToUppercase(char word[])
{
    int i = 0;
    while (word[i] != '\0') 
    {
        if (word[i] >= 'a' && word[i] <= 'z') 
        {
            word[i] = word[i] - 32;
        }
        i++;
    }
}

int ComputeScore(char word[])
{
    //Compute and return the score for the word
    int i = 0;
    int score = 0;
    while (word[i] != '\0')
    {
        for (int j = 0; j < 26; j++)
        {
            if (word[i] == alphabetArray[j])
            {
                score += pointsArray[j];
                break;
            }
        }
        i++;
    }
    return score;
}

void PrintWinner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!");
        return;
    }
    if (score2 > score1)
    {
        printf("Player 2 wins!");
        return;
    }
    printf("Tie!");
}
//BACKGROUND
/*Say we have a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
For example, if we were to start with n = 1200 llamas, then in the first year, 1200 / 3 = 400 new llamas would be born and 1200 / 4 = 300 llamas would pass away.
At the end of that year, we would have 1200 + 400 - 300 = 1300 llamas.

To try another example, if we were to start with n = 1000 llamas, at the end of the year, we would have 1000 / 3 = 333.33 new llamas.
We can’t have a decimal portion of a llama, though, so we’ll truncate the decimal to get 333 new llamas born.
1000 / 4 = 250 llamas will pass away, so we’ll end up with a total of 1000 + 333 - 250 = 1083 llamas at the end of the year.*/

//TASK
/*Your program should first prompt the user for a starting population size.
If the user enters a number less than 9 (the minimum allowed population size), the user should be re-prompted to enter a starting population size until they enter a number that is
greater than or equal to 9. (If we start with fewer than 9 llamas, the population of llamas will quickly become stagnant!)
Your program should then prompt the user for an ending population size.
If the user enters a number less than the starting population size, the user should be re-prompted to enter an ending population size until they enter a number that is greater than
or equal to the starting population size. (After all, we want the population of llamas to grow!)
Your program should then calculate the (integer) number of years required for the population to reach at least the size of the end value.
Finally, your program should print the number of years required for the llama population to reach that end size, as by printing to the terminal Years: n, where n is the number of years.*/


#define _CRT_SECURE_NO_WARNINGS
//INCLUDES
#include <stdio.h>

//BREADCRUMBS
float GetInitialPopulation();
float GetEndPopulation(float n);
int CalculateYears(float initialPop, float endPop);



//MAIN
int main(void)
{
    // Gets the initial population size from the user (startPop)
    float initialPop = GetInitialPopulation();
    // Gets the ending population size from the user (endPop)
    float endPop = GetEndPopulation(initialPop);
    // Calculates number of years until we reach threshold
    int years = CalculateYears(initialPop, endPop);

    printf("Years: %i", years);
}















//HELPER FUNCTIONS
float GetInitialPopulation()
{
    float n = 0;
    do
    {
        printf("Enter initial population: \n");
        scanf("%f", &n);
    } while (n < 9);
    return n;
}

float GetEndPopulation(float n)
{
    float e = 0;
    do
    {
        printf("Enter end populaton: \n");
        scanf("%f", &e);
    } while (e < n);
    return e;
}

int CalculateYears(float initialPop, float endPop)
{
    //Initialise variables
    int llamasBorn = initialPop / 3;
    int llamasDying = initialPop / 4;
    int popGrowth = 0;
    int years = 0;
    int currentPop = initialPop;

    while (currentPop + popGrowth < endPop)
    {
        currentPop = currentPop + popGrowth;
        llamasBorn = currentPop / 3;
        llamasDying = currentPop / 4;
        popGrowth = llamasBorn - llamasDying;
        years++;
    }
    return years;
}
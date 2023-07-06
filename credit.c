//BACKGROUND
/*Most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) 
valid as follows:
Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.
For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:
4003600000000014
Okay, let’s multiply each of the underlined digits by 2:
1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2
That gives us:
2 + 0 + 0 + 0 + 0 + 12 + 0 + 8
Now let’s add those products’ digits (i.e., not the products themselves) together:
2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13
Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):
13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20
Yup, the last digit in that sum (20) is a 0, so David’s card is legit!
So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.*/

//TASK
/*In the file called credit.c in the credit directory, write a program that prompts the user for a credit card number and then reports (via printf) whether it is 
a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. So that we can automate some tests of your code, we ask 
that your program’s last line of output be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n, nothing more, nothing less. For simplicity, you may assume that the 
user’s input will be entirely numeric (i.e., devoid of hyphens, as might be printed on an actual card) and that it won’t have leading zeroes. But do not assume 
that the user’s input will fit in an int! Best to use get_long from CS50’s library to get users’ input. (Why?)*/

#define _CRT_SECURE_NO_WARNINGS
//INCLUDES
#include <stdio.h>
#include <stdlib.h>

//BREADCRUMBS
long long int GetCardNum();
int CountDigits(long long int cardNum);
int CalculateFirstDigits(long long int cardNum);
int CheckCardType(long long int cardNum, int numDigits, int firstTwoDigits);
void DetermineValidity(long long int cardNum, int numDigits);
void PrintCardType(int cardType);



//MAIN
int main(void)
{
    long long int cardNum = GetCardNum();
    int numDigits = CountDigits(cardNum);
    int firstTwoDigits = CalculateFirstDigits(cardNum);
    //cardType = 1 = MasterCard, cardType = 2 = Visa, cardType = 3 = American Express
    int cardType = CheckCardType(cardNum, numDigits, firstTwoDigits);
    DetermineValidity(cardNum, numDigits);
    PrintCardType(cardType);
}















//HELPER FUNCTIONS
long long int GetCardNum()
{
    long long int cardNum;
    printf("Enter credit card number: ");
    scanf("%lld", &cardNum);
    return cardNum;
}

int CountDigits(long long int cardNum)
{
    //loop until cardNum becomes 0, removing the last digit of cardNum with each iteration.
    int count = 0;
    do
    {
        cardNum /= 10;
        count++;
    } while (cardNum != 0);
    return count;
}

int CalculateFirstDigits(long long int cardNum)
{
    //loop until cardNum becomes 0, removing the last digit of cardNum with each iteration.
    do
    {
        cardNum /= 10;
        if (cardNum / 100 == 0)
        {
            return cardNum;
        }
    } while (cardNum != 0);

    //if the number does not have 2 front digits (non-zero), the card is INVALID and we can exit the program 
    printf("INVALID\n");
    _Exit(0);
}

int CheckCardType(long long int cardNum, int numDigits, int firstTwoDigits)
{
    int firstDigit = firstTwoDigits / 10;
    //MasterCard uses 16-digit numbers
    if (numDigits == 16)
    {
        //All MasterCard numbers start with 51, 52, 53, 54, or 55
        for (int i = 51; i <= 55; i++)
        {
            if (firstTwoDigits == i)
            {
                return 1;
            }
        }
    }
    //Visa uses 13 and 16-digit numbers
    if (numDigits == 13 || numDigits == 16)
    {
        //All Visa numbers start with 4
        if (firstDigit == 4)
        {
            return 2;
        }
    }
    //American Express uses 15-digit numbers
    else if (numDigits == 15)
    {
        //All American Express numbers start with 34 or 37  
        if (firstTwoDigits == 34 || firstTwoDigits == 37)
        {
            return 3;
        }
    }
   
    //if the number did not fit those conditions the card is INVALID and we can exit the program
    printf("INVALID\n");
    _Exit(0);
}

void DetermineValidity(long long int cardNum, int numDigits)
{
    //Multiply every other digit by 2, starting with the number’s second-to-last digit
    long long int cardNumEdit = cardNum / 10;
    int firstDigitsArray[10];
    firstDigitsArray[0] = cardNum % 10;
    int secondDigitsArray[10];
    int i = 0;
    while(cardNumEdit > 0)
    {
        int lastDigit = cardNumEdit % 10;
        secondDigitsArray[i] = lastDigit * 2;
        cardNumEdit /= 10;
        firstDigitsArray[i + 1] = cardNumEdit % 10;
        cardNumEdit /= 10;
        i++;
    }
    
    //Add those products’ digits together
    int sum = 0;
    for (int j = 0; j < i; j++)
    {
        //split the number into its digits befor adding to the sum if required
        if (secondDigitsArray[j] > 9)
        {
            sum = sum + secondDigitsArray[j] % 10 + 1;
        }
        else
        {
            sum = sum + secondDigitsArray[j];
        }
    }

    //add that sum to the sum of the digits that weren’t multiplied by 2 (starting from the end)
    //sum firstDigitsArray
    int sum2 = 0;
    for (int j = 0; j < i; j++)
    {
        sum2 = sum2 + firstDigitsArray[j];
    }
    int sumTotal = sum + sum2;

    //if the last digit of the sum total is 0 then the card is ligit
    if (sumTotal % 10 != 0)
    {
        //if the number did not fit this condition the card is INVALID and we can exit the program
        printf("INVALID\n");
        _Exit(0);
    }
    return;
}

void PrintCardType(int cardType)
{
    if (cardType == 1)
    {
        printf("MASTERCARD\n");
    }
    else if (cardType == 2)
    {
        printf("VISA\n");
    }
    else if (cardType == 3)
    {
        printf("AMEX\n");
    }
}

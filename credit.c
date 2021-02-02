#include <cs50.h>
#include <stdio.h>

long get_positive_long(void);

int main(void)
{
    // get positive long from user
    long CC = get_positive_long();

    int cksum = 0;

    //Luhn's Algorithm:

    // segment digits, add sum of EVEN digits * 2 to cksum
    for (long mod = 100; mod < (CC * 10); mod *= 100)
    {
        long a = CC % mod;

        a = ((a / (mod / 10)) * 2);

        if (a > 9)
        {
            a = 1 + (a % 10);
        }

        cksum += a;
    }

    // segment digits, add sum of ODD digits to cksum
    for (long mod = 10; mod < (CC * 10); mod *= 100)
    {
        long a = CC % mod;

        a = (a / (mod / 10));

        if (a > 9)
        {
            a = 1 + (a % 10);
        }

        cksum += a;
    }

    // Validate card number and determine card type
    // Pull's and checks the cards first digit
    int cardtype;
    for (long mod = 10; mod < (CC * 10); mod *= 10)
    {
        long a = CC % mod;
        a = a / (mod / 10);
        cardtype = a;
    }

    if (cardtype == 3 && (cksum % 10 == 0))
    {
        printf("AMEX\n");
    }
    else if (cardtype == 4 && (cksum % 10 == 0))
    {
        printf("VISA\n");
    }
    else if (cardtype == 5 && (cksum % 10 == 0))
    {
        printf("MASTERCARD\n");
    }

    else
    {
        printf("INVALID\n");
    }
}

// Get positive card number from user
long get_positive_long(void)
{
    long CC;
    do
    {
        CC = get_long("Enter card number: ");
    }
    while (CC <= 0);
    return CC;
}
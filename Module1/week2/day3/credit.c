#include <stdio.h>
#include <cs50.h>
int digitsSum(int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main()
{
    long cardNumber;
    cardNumber = get_long("Card number: ");
    int digits[18];
    for (int i = 0; i < 18; ++i)
    {
        digits[i] = -1;
    }
    int i = 0;
    do
    {
        if (i >= 18)
        {
            printf("INVALID\n");
            return 0;
        }
        int digit = cardNumber % 10;
        digits[i] = digit;
        ++i;
        cardNumber = cardNumber / 10;
    } while (cardNumber != 0);

    int checksum = 0;
    int k = 0;
    for (int j = 0; j < i; ++j)
    {

        if (k % 2 != 0)
            checksum += digitsSum(digits[j] * 2);
        else
            checksum += digits[j];
        k++;
    }

    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    i--;

    if (digits[i] == 4 && (i == 12 || i == 15))
    {
        printf("VISA\n");
        return 0;
    }
    if (i == 14 && (digits[i] == 3 && (digits[i - 1] == 4 || digits[i - 1] == 7)))
    {
        printf("AMEX\n");
        return 0;
    }
    if (i == 15 && (digits[i] == 5 && (digits[i - 1] == 1 || digits[i - 1] == 2 || digits[i - 1] == 3 || digits[i - 1] == 4 || digits[i - 1] == 5)))
    {
        printf("MASTERCARD\n");
        return 0;
    }
    printf("INVALID\n");
    return 0;
}
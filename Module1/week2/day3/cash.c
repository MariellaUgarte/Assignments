#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int quarters, dimes, nickles, pennies;
    float money;
    do
    {
        money = get_float("Money: ");
    } while (money < 0);
    int total = round(money * 100);
    int coins = 0;
    quarters = total / 25;
    total = total - (quarters * 25);
    dimes = total / 10;
    total = total - (dimes * 10);
    nickles = total / 5;
    total = total - (nickles * 5);
    pennies = total;
    total = total - pennies;
    coins = quarters + dimes + nickles + pennies;
    printf("%d\n", coins);
}

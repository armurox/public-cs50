#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // TODO
    int given;
    do
    {
        given = get_int("Change owed: ");
    }
    while (given < 0);
    return given;
}

int calculate_quarters(int cents)
{
    // TODO
    int quarter_num = 0;
    int value_in_q = 0;
    while (value_in_q <= cents)
    {
        value_in_q += 25;
        quarter_num++;

    }
    return quarter_num - 1;
}

int calculate_dimes(int cents)
{
    // TODO
    int dime_num = 0;
    int value_in_dim = 0;
    while (value_in_dim <= cents)
    {
        value_in_dim += 10;
        dime_num++;

    }
    return dime_num - 1;
}


int calculate_nickels(int cents)
{
    // TODO
    int nickel_num = 0;
    int value_in_nick = 0;
    while (value_in_nick <= cents)
    {
        value_in_nick += 5;
        nickel_num++;

    }
    return nickel_num - 1;
}

int calculate_pennies(int cents)
{
    // TODO
    int penny_num = 0;
    int value_in_pen = 0;
    while (value_in_pen <= cents)
    {
        value_in_pen ++;
        penny_num++;

    }
    return penny_num - 1;
}

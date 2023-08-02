#include <stdio.h>
#include <cs50.h>
#include <math.h>

float each_owed(float bill,float tax,float tip, int people);

int main(void)
{
    // Ask for how may people the bill is being split up between
    int people_number = get_int("How many people? ");

    // Ask for bill before tax and tip
    float bill_amount = get_float("Bill before tax and tip ");

    // Ask for tax percentage
    double tax_percent = get_float("Sale tax percent: ");


    //Ask for tip percentage
    float tip_percent = get_float("Tip percent: ");

    // Add tax and tip percentage to bill
    float owed = each_owed(bill_amount, tax_percent, tip_percent, people_number);

    // print amount owed per person
    printf("You will owe %0.2f each!\n", owed);
}


float each_owed(float bill, float tax, float tip, int people)
{
    float billtax = bill * (1 + (tax/100));
    float owe = (billtax * (1+ (tip/100)))/people;
    return owe;
}
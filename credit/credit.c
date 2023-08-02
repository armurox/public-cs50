#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

bool is_credit(long num);
void print_credit_type(long credit, bool valid_credit);

int main(void)
{
    // Get credit card number from user
    long credit_num = get_long("Number: ");

    // Check if the input is a credit card number
    bool credit_valid = is_credit(credit_num);

    // Print credit type
    print_credit_type(credit_num, credit_valid);
}



bool is_credit(long num)

{
    long digit;
    long product_sum1 = 0;
    long digit_times_two;
    long product_sum2 = 0;
    long num2 = num;
    long num1 = num;
    // Sum of digits not multiplied by 2
    while (num1 > 0)
    {
        digit = num1 % 10;
        num1 /= 100;
        product_sum1 += digit;
    }

    // Sum of digits multiplied by 2
    while (num2 > 0)
    {
        digit_times_two = ((num2 / 10) % 10) * 2;
        if (digit_times_two > 9)
        {
            digit_times_two = ((digit_times_two % 10) + (digit_times_two / 10));
        }
        product_sum2 += digit_times_two;
        num2 /= 100;
    }
    // Total sum of digits
    long product_sum = product_sum1 + product_sum2;

    // Checksum for mod 10
    if (product_sum % 10 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }

}

void print_credit_type(long credit, bool valid_credit)
{
    // Check for first two digits if American or Mastercard
    long first_two_digits = credit;
    while (first_two_digits >= 100)
    {
        first_two_digits /= 10;
    }

    // Check for first digit (for Visa case)
    long first_digit = credit;
    int count = 0;
    while (first_digit >= 10)
    {
        first_digit /= 10;
        count++;
    }

    // Print the appropriate thing
    if (valid_credit == true && (first_two_digits == 34 || first_two_digits == 37) && count == 14)
    {
        printf("AMEX\n");
    }
    else if (valid_credit == true && (first_two_digits > 50 && first_two_digits < 56) && count == 15)
    {
        printf("MASTERCARD\n");
    }
    else if (valid_credit == true && first_digit == 4 && (count == 12 || count == 15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

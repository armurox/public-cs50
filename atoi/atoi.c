#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int convert(string input);

int main(void)
{
    // Get string input from user
    string user_input = get_string("Enter an integer ");



    // Convert and print it out as an integer
    int output = convert(user_input);

    printf("%i", output);
}

int convert(string input)
{
    for(int i = 0, n = strlen(input); i < n; i++)
    {
        if ((int) input[i] >= 48 && (int) input[i] <= 57)
        {
            input[i] = (int) input[i] - 48;
        }
    }
    
}
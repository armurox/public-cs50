#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    char c = get_char("Do you agree? Please type y/n for yes or no. ");

    if (c == 'y')
    {
        printf("Great, thx!\n");
    }
    else if (c == 'n')
    {
        printf("Aw, that's a shame, maybe next time!\n");
    }
}
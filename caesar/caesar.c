#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

string c_encrypt(string pt, int key);

int main(int argc, string argv[])
{
    // Get valid caesar cipher key from from user
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Get plaintext from user and shift by key provided
    string plaintext = get_string("plaintext: ");

    // Encrypts into ciphertext
    string ciphertext = c_encrypt(plaintext, atoi(argv[1]));

    printf("ciphertext: %s\n", ciphertext);
}


string c_encrypt(string pt, int key)
{
// Shift upper and lowercase values by the key, depending on ASCII values
#define LOWERCASESHIFT (((pt[i] - 97) + key) % 26) + 97
#define UPPERCASESHIFT  (((pt[i] - 65) + key) % 26) + 65

    string ct;

    for (int i = 0, n = strlen(pt); i < n; i++)
    {
        // Ignore non alphabetical values
        if (isalpha(pt[i]) == 0)
        {
            continue;
        }

        // Preserve upper and lower case
        else if (islower(pt[i]) != 0)
        {
            pt[i] = (char) LOWERCASESHIFT;
        }

        else
        {
            pt[i] = (char) UPPERCASESHIFT;
        }
    }

    ct = pt;

    return ct;
}
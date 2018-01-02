#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

int ALPHA_SIZE = 26;
void encrypt(string s, int key);
void shift_char(char c, int key, int ascii);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Missing the encryption key as second argument!\n");
        return -1;
    }
    printf("plaintext: ");
    string s = get_string();
    printf("cyphertext: ");
    encrypt(s, atoi(argv[1])); // encode string and cmd line argument as key
}

void encrypt(string s, int key)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (isalpha(s[i]))
        {
            if(isupper(s[i]))
            {
                shift_char(s[i], key, 65);
            }
            else
            {
                shift_char(s[i], key, 97);
            }
        }
        else // if not alpha, print it
        {
            printf("%c", s[i]);
        }

    }
    // after encoding print new line
    printf("\n");
}

void shift_char(char c, int key, int ascii)
{
    // subtract ascii # to create 0-25 range
    int alpha_index = c - ascii;
    // shift by key (% is net..1, 27, 54 all shift by 2)
    char cypher_char = (alpha_index + key) % ALPHA_SIZE + ascii;
    // add the ascii amount back to retain proper case
    printf("%c", cypher_char);
}
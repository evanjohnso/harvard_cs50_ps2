#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void encrypt(string s, string key);
void shift_char(char c, int key, int ascii);
bool valid_cmd_args(int argc, string argv[]);
int ALPHA_NUM = 26;

int main(int argc, string argv[])
{
    if (!valid_cmd_args(argc, argv))
    {
        return -1;
    }

    printf("plaintext: ");
    string s = get_string();
    printf("cyphertext: ");
    encrypt(s, argv[1]); // encode string and cmd line argument as key
}

void encrypt(string s, string word)
{
    // keep track of where in the encryption word we are
    int word_len = strlen(word) - 1;
    int key_counter = 0;

    for (int i = 0; i < strlen(s); i++)
    {
    // for each iteration, grab the int value to be shifted
    int key = toupper(word[key_counter]) - 65;
    // force upper (or lower) in case word is mixed case
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
            // if looped through word, reset for next round, else continue ++
            if (key_counter == word_len)
            {
                key_counter = 0;
            }
            else
            {
                key_counter ++;
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
    char cypher_char = (alpha_index + key) % ALPHA_NUM + ascii;
    // add the ascii amount back to retain proper case
    printf("%c", cypher_char);
}

bool valid_cmd_args(int argc, string argv[])
{
    // if not exactly 2 arguments, throw error
    if (argc < 2 || argc > 2)
    {
        printf("Invalid command line arguments.\nPlease enter an encryption string as only argument.\n");
        return false;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // if any non-alpha characters in second arg, throw error
        if (!isalpha(argv[1][i]))
        {
            printf("Please enter a valid encryption key\n");
            return false;
        }
    }
    return true;
}
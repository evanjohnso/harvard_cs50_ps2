#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void parse_string(string s);
void print_uppr_char(char c);

int main(void)
{
    printf("Hello friend, what is your name?\n");
    string name = get_string();
    parse_string(name);
}

void parse_string(string s)
{
    // if first char in string is a letter, print it
    if (isalpha(s[0]) > 0)
    {
      print_uppr_char(s[0]);
    }
    // first element checked, start at second
    for (int i = 1, n = strlen(s); i < n; i++)
    {
        //if letter & space before it
        bool new_word = isalpha(s[i]) > 0 && s[i-1] == 32;
        if (new_word)
        {
          print_uppr_char(s[i]);
        }

    }
    printf("\n");
}

void print_uppr_char(char c)
{
    printf("%c", toupper(c));
}
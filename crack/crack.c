#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void crack(string s);

int main(int argc, string argv[]){
    if (argc < 2)
    {
        printf("Usage: ./crack hashed-password\n");
        return -1;
    }
    crack(argv[1]);
}

void crack(string hash)
{
    if (strlen(hash) < 2)
    {
        printf("Invalid hash\n");
    }
    char salt[3] = { hash[0], hash[1], '\0'};
    crypt("rofl", salt);
    printf("%s", salt);
}
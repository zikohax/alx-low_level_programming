#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

int main(void)
{
    char password[PASSWORD_LENGTH + 1];  // +1 for null terminator

    srand(time(NULL));  // Seed the random number generator with current time

    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        // Generate a random character between '!' and '~'
        password[i] = '!' + (rand() % 94);
    }

    password[PASSWORD_LENGTH] = '\0';  // Null terminate the password string

    printf("%s", password);

    return 0;
}


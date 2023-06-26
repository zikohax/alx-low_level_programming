#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

int main(void)
{
    char password[PASSWORD_LENGTH + 1];
    srand(time(NULL));

    for (int i = 0; i < PASSWORD_LENGTH; i++)
    {
        password[i] = '!' + (rand() % 94);
    }

    password[PASSWORD_LENGTH] = '\0';

    printf("%s", password);

    return 0;
}


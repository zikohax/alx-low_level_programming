#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int n;
    
    srand(time(NULL));
    
    n = rand() % 201 - 100;
    
    printf("The number is %d\n", n);
    
    if (n > 0)
    {
        printf("is positive\n");
    }
    else if (n < 0)
    {
        printf("is negative\n");
    }
    else
    {
        printf("is zero\n");
    }
    
    return 0;
}


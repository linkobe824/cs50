#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size;
    do
    {
        size = get_int("Height? ");
    }
    while (size <= 0 || size >= 9);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if ((size - 1 - i - j) > 0)
                printf(" ");
            else
                printf("#");
        }
        printf("  ");
        for (int j = 0; j < size; j++)
        {
            if (j <= i)
                printf("#");
        }
        printf("\n");
    }
}

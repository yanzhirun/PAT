#include "stdio.h"
#include "stdlib.h"

int main()
{
    int N, i, j;
    char C;
    scanf("%d", &N);
    getchar();
    scanf("%c", &C);

    for (i = 0; i < N; i++)
    {
        printf("%c", C);
    }
    printf("\n");
    for (i = 0; i < (int)(N+1)/2 - 2; i++)
    {
        printf ("%c", C);
        for (j = 0; j < N - 2; j++)
        {
            printf(" ");
        }
        printf ("%c\n", C);
    }
    for (i = 0; i < N; i++)
    {
        printf("%c", C);
    }
    //printf("%d %c", N, C);

    return 0;
}

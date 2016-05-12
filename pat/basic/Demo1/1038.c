#include "stdlib.h"
#include "stdio.h"

int main()
{
    int N, K, i, j, k, tmp = 0;
    int score[100000], find[100000];
    scanf ("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf ("%d", score+i);
    }
    scanf ("%d", &K);
    for (i = 0; i < K; i++)
    {
        scanf ("%d", find+i);
    }
    for (i = 0; i < K; i++)
    {
        tmp = 0;
        for (j = 0; j < N; j++)
        {
            if (find[i] == score[j])
                tmp++;
        }
        printf("%d", tmp);
        if (i < K-1)
            printf(" ");
    }
//    printf("\noutput----\n");
//    for (i = 0; i < N; i++)
//    {
//        printf("%d  ", score[i]);
//    }
//    printf("\n----\n");
//    for (i = 0; i < K; i++)
//    {
//        printf("%d  ", find[i]);
//    }

    return 0;
}

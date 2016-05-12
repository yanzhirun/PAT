#include "stdlib.h"
#include "stdio.h"

int main()
{
    int N, K, i, j, k, tmp = 0;
    int score[100000], find[100000];
    int result[101] = {0};
    scanf ("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf ("%d", score+i);
        result[score[i]]++;
    }
    scanf ("%d", &K);
    for (i = 0; i < K; i++)
    {
        scanf ("%d", find+i);
    }
    for (i = 0; i < K - 1; i++)
    {
        printf("%d ",result[find[i]]);
    }
        printf("%d",result[find[K-1]]);

    return 0;
}

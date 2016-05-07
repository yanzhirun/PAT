#include "stdlib.h"
#include "stdio.h"

int merge_sort_test (int* input, int* sort_first, int N)
{

    int ret = 0, i, j, k, tmp, cmp_same = 0;
    int insert[101];
    if (NULL == input || NULL == sort_first)
    {
        ret = 1;
        return ret;
    }
    for (i = 0; i < N; i++)
    {
        insert[i] = input[i];
    }




    return ret;
}

int insert_sort_test (int* input, int* sort_first, int N)
{
    int ret = 0, i, j, k, tmp, cmp_same = 0;
    int insert[101];
    if (NULL == input || NULL == sort_first)
    {
        ret = 1;
        return ret;
    }
    for (i = 0; i < N; i++)
    {
        insert[i] = input[i];
    }

    for (i = 1; i < N; i++)
    {
        tmp = insert[i];
        for (j = i-1; j >= 0 && tmp < insert[j]; j--)
            insert[j+1] = insert[j];
        insert[j+1]= tmp;
        if (cmp_same)
        {
            printf("insert sort\n");
            for (i = 0; i < N; i++)
            {
                printf("%d ", insert[i]);
            }
        }
        for (k = 0; k < N; k++)
        {
            cmp_same = 1;
             if (insert[k] != sort_first[k])
             {
                 cmp_same = 0;
                 break;
             }
        }
    }

    return 0;
}
int main()
{
    int N, i;
    int input[101], sort_first[101];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", input+i);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", sort_first+i);
    }
    insert_sort_test (input, sort_first, N);

    merge_sort_test (input, sort_first, N);
    return 0;
}

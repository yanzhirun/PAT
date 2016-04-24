#include "stdlib.h"
#include "stdio.h"

int cmp(const void *p, const void *q)
{
    int** left = (int**)p;
    int** right = (int**)q;
    return (*left)[0] - (*right)[0];
}

int main()
{
    int N, i, num_school = 1,totle_out = 0, totle_tmp = 0, j = 0, num;
    int **arr_info = NULL;
    scanf ("%d", &N);
    arr_info = (int**)malloc(sizeof(int*)*N);
    if (NULL == arr_info)
    {
        return 0;
    }
    for (i = 0; i < N; i++)
    {
        arr_info[i] = (int*)malloc(sizeof(int)*2);
    }
    for (i = 0; i < N; i++)
    {
        scanf ("%d%d", *(arr_info+i), *(arr_info+i)+1);
    }

    qsort (arr_info, N, sizeof(*arr_info), cmp);

//    printf("arr_infoN: %d\n",arr_info[N-1][0]);
    for (i = 1; i <= arr_info[N-1][0]; i++)
    {
        totle_tmp = 0;
        while (j < N && arr_info[j][0] == i)
        {
            totle_tmp += arr_info[j++][1];
        }
        totle_out = totle_out > totle_tmp?totle_out:totle_tmp;
        num = totle_out > totle_tmp?num:i;
    }
    printf("%d %d", num, totle_out);
//    for (i = 0; i < N; i++)
//    {
//        printf ("%d  %d\n", arr_info[i][0], arr_info[i][1]);
//    }
    for (i = 0; i < N; i++)
    {
        if (NULL != arr_info[i])
        {
            free (arr_info[i]);
            arr_info[i] = NULL;
        }
    }
    if (NULL != arr_info)
    {
        free (arr_info);
        arr_info = NULL;
    }

    return 0;
}

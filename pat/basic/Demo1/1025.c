#include "stdlib.h"
#include "stdio.h"

int **creat_arr(int N)
{
    int i, Address, Data, Next;
    int** p_arr = NULL;
    p_arr = (int**)malloc(sizeof(int*)*N);
    for (i = 0; i < N; i++)
    {
        p_arr[i] = (int*)malloc(sizeof(int)*3);
    }
    //输入就按顺序排好？！OK!
    for (i = 0; i < N; i++)
    {
        scanf ("%d%d%d", &Address, &Data, &Next);
        p_arr[Data-1][0] = Address;
        p_arr[Data-1][1] = Data;
        p_arr[Data-1][2] = Next;
    }

    return p_arr;
}

int free_arr(int ** p_arr, int N)
{
    int i, ret = 1;
    if (NULL == p_arr)
    {
        ret = -1;
        printf("free err");
        return ret;
    }
    for (i = 0; i < N; i++)
    {
        if (NULL != p_arr[i])
        {
            free (p_arr[i]);
            p_arr[i] = NULL;
        }
    }
    if (NULL != p_arr)
    {
        free (p_arr);
    }

    return ret;
}

int convers_arr (int** p_link_arr, int N, int K)
{
    int ret = 1;
    K -= 1;

    return ret;
}

int print_arr(int** p_link_arr, int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        //            printf ("out\n %05d %d %05d\n", p_link_arr[i][0], p_link_arr[i][1], p_link_arr[i][2]);
        printf ("%05d %d ", p_link_arr[i][0], p_link_arr[i][1]);
        if (-1 == p_link_arr[i][2])
        {
            printf("%d\n", p_link_arr[i][2]);
        }
        else if (-1 != p_link_arr[i][2])
        {
            printf("%05d\n", p_link_arr[i][2]);
        }
    }

    return 0;
}

int main ()
{
    int first_add, N, K,i;
    scanf ("%d%d%d", &first_add, &N, &K);
    //    printf ("first_add:%d N:%d K:%d\n", first_add, N, K);
    int** p_link_arr = NULL;

    p_link_arr = creat_arr(N);
    convers_arr (p_link_arr, N, K);
    printf ("out:\n");
    print_arr(p_link_arr, N);
    if (NULL != p_link_arr)
    {
        free_arr(p_link_arr, N);
        p_link_arr = NULL;
    }
    return 0;
}

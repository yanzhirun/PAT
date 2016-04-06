#include "stdlib.h"
#include "stdio.h"

int **input_info (int N)
{
    int **p_stu = NULL;
    int i = 0;
    p_stu = (int**)malloc(N*sizeof(int*));
    if (NULL == p_stu)
    {
        printf("malloc err!\n");
        return NULL;
    }
    for (i = 0; i < N; i++)
    {
        p_stu[i] = (int*)malloc(3*sizeof(int));
        //*(p_stu+i) = (in*)malloc(3*sizeof(int));
        printf("malloc arr success!\n");
    }

    return p_stu;
}

int arr_free(int **p_stu, int row)
{
    int i;

    if (NULL == p_stu)
    {
        return 0;
    }
    for (i = 0; i < row; i++)
    {
        if (NULL != p_stu[i])
        {
            free(p_stu[i]);
            p_stu[i] = NULL;
        }
    }
    if (NULL != p_stu)
        free (p_stu);

    return 0;
}

int main()
{

    int N, L, H;
    int i, j, k;
    int **p_stu = NULL;

    scanf("%d%d%d", &N, &L, &H);
    printf("N:%d  L:%d  H:%d\n", N, L, H);

    p_stu = input_info(N);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d",&p_stu[i][j]);
        }
    }

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ",p_stu[i][j]);
        }
        printf("\n");
    }
    if (NULL != p_stu)
    {
        arr_free(p_stu,3);
        p_stu = NULL;
    }

    return 0;
}

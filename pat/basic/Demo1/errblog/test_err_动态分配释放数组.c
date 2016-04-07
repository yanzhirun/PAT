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
        //p_stu[i] = (int*)malloc(3*sizeof(int));//分配N行* 3列数组
        p_stu[i] = (int*)malloc(4*sizeof(int));//分配N行 *4列 第四列用来存放状态信息，注意释放也要改为4；
        //*(p_stu+i) = (int*)malloc(3*sizeof(int));
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

int classify_stu(int ** p_stu, int N, int H, int L)
{
    int ret = 1, i = 0;
    if (NULL == p_stu)
    {
        ret = 0;
        printf("p_stu err!\n");
        return ret;
    }

    for (i = 0; i < N; i++)
    {
        if (p_stu[i][1] >= H && p_stu[i][2] >= H)
        {
            p_stu[i][3] = 1;
        }
        else if (p_stu[i][1] >= H && p_stu[i][2] >=L && p_stu[i][2] < H)
        {
            p_stu[i][3] = 2;
        }
        else if (p_stu[i][1] >= L && p_stu[i][1] < H && p_stu[i][2] >=L && p_stu[i][2] < H)
        {
            p_stu[i][3] = 3;
        }
    }


    return ret;
}
int main()
{

    int N, L, H;
    int i, j, k;
    int **p_stu = NULL;

    int total_score;
    scanf("%d%d%d", &N, &L, &H);
    printf("N:%d  L:%d  H:%d\n", N, L, H);

    p_stu = input_info(N);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d",&p_stu[i][j]);
        }
      //  p_stu[i][3] = 0;
    }

    //    classify_stu(p_stu, N, H, L);
    //total_score = p_stu[i][1] + p_stu[i][2];
    printf ("%d   ", p_stu[1][3]);
    printf ("\n\n======\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ",*(p_stu + i) + j);
        }
        printf("\n");
    }

    if (NULL != p_stu)
    {
        arr_free(p_stu, N);
        p_stu = NULL;
    }

    return 0;
}

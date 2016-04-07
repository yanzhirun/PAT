#include "stdlib.h"
#include "stdio.h"
#include "string.h"

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
        //        printf("malloc arr success!\n");
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
    int ret = 1, i = 0, j = 0, p = 0, q = 0, y = 0;
    int great[100][4], mid[100][4],last[100][4],nor[100][4];
    if (NULL == p_stu)
    {
        ret = 0;
        printf("p_stu err!\n");
        return ret;
    }

    for (i = 0; i < N; i++)
    {
        p_stu[i][3] = p_stu[i][1] + p_stu[i][2];
        if (p_stu[i][1] >= H && p_stu[i][2] >= H)
        {
            memcpy(*(great+j), *(p_stu+i), sizeof(int)*4);
            //printf("great:%d\n", great[j][3]);
            j++;
        }
        else if (p_stu[i][1] >= H && p_stu[i][2] >= L && p_stu[i][2] < H)
        {
            memcpy(*(mid+p), *(p_stu+i), sizeof(int)*4);
            //printf("mid:%d\n", mid[p][3]);
            p++;
        }
        else if (p_stu[i][1] >= L && p_stu[i][1] < H && p_stu[i][2] >=L && p_stu[i][2] < H && p_stu[i][1] >= p_stu[i][2])
        {
            memcpy(*(last+q), *(p_stu+i), sizeof(int)*4);
            //printf("last:%d\n", last[q][3]);
            q++;
        }
        else if (p_stu[i][1] >= L && p_stu[i][1] < H && p_stu[i][2] >=L && p_stu[i][2] < H)
        {
            memcpy(*(nor+q), *(p_stu+i), sizeof(int)*4);
            //printf("nor:%d\n", nor[y][3]);
            y++;
        }
    }

    //printf("做标记ok,j:%d\n",j);
    printf ("%d", j + p + q + y);
        sort_socre(great, 1, j);
        sort_socre(mid, 2, p);
        sort_socre(last, 3, q);
        sort_socre(nor, 4, y);

    return ret;
}

int sort_socre(int (*sort_arr)[4], int status, int ac_num)
{
    int i = 0, j = ac_num, k = 0, q = 0;
    //printf("打印sort_arr:%d\n", sort_arr[0][3]);
    if (NULL == sort_arr)
    {
        printf("sort_score err");
        return 0;
    }
    //int **new_sort_arr = input_info(ac_num);
//    int sort_arr[10][4] = {0} ;
    int tmp[1][4] = {0};

    //printf("打印排序 j:%d\n",j);
    //比总分
    for (k = 0; k < j ; k++)
    {

    //printf("打印crcle k:%d\n", k);
    //printf("打印sort_arr:%d\n", sort_arr[k][3]);
        for (q = k+1; q < j-1; q++)
        {
            if (sort_arr[k][3] <= sort_arr[q][3])
            {
    //printf("打印crcle k:%d\n", sort_arr[k][3]);
                memcpy (*tmp, *(sort_arr + k), sizeof(int)*4);
                //printf("\n====\ntmp:%d  %d  %d\n", tmp[0][1], tmp[0][2], tmp[0][3]);
                //printf("dayin:sort 1 :%d  ", sort_arr[k][1]);
                memcpy (*(sort_arr + k), *(sort_arr + q), sizeof(int)*4);
                memcpy (*(sort_arr + q), *tmp, sizeof(int)*4);
                /*
                   tmp = sort_arr[k];
                   sort_arr[k] = sort_arr[q];
                   sort_arr[q] = tmp;
                   */
            }
        }
    }
    //比单项分
    for (k = 0; k < j; k++)
    {
        for (q = k+1; q < j-1; q++)
        {
            if (sort_arr[k][3] == sort_arr[q][3] && sort_arr[k][1] != sort_arr[q][1])
            {
                if ( sort_arr[k][1] <= sort_arr[q][1] )
                {
                    memcpy (*tmp, *(sort_arr + k), sizeof(int)*4);
                    memcpy (*(sort_arr + k), *(sort_arr + q), sizeof(int)*4);
                    memcpy (*(sort_arr + q), *tmp, sizeof(int)*4);
                }
            }
        }
    }
    //比序号
    for (k = 0; k < j; k++)
    {
        for (q = k+1; q < j-1; q++)
        {
            if (sort_arr[k][3] == sort_arr[q][3] && sort_arr[k][1] == sort_arr[q][1] )
            {
                if (sort_arr[k][0] > sort_arr[q][0])
                {
                    memcpy (*tmp, *(sort_arr + k), sizeof(int)*4);
                    memcpy (*(sort_arr + k), *(sort_arr + q), sizeof(int)*4);
                    memcpy (*(sort_arr + q), *tmp, sizeof(int)*4);
                }
            }
        }
    }
    for (k = 0; k < j; k++)
    {
        printf("%d %d %d\n", sort_arr[k][0], sort_arr[k][1], sort_arr[k][2]);
    }
}

int main()
{

    int N, L, H;
    int i, j, k;
    int **p_stu = NULL;

    int total_score;
    scanf("%d%d%d", &N, &L, &H);
    //    printf("N:%d  L:%d  H:%d\n", N, L, H);

    p_stu = input_info(N);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d",&p_stu[i][j]);
        }
        p_stu[i][3] = 0;
    }

    classify_stu(p_stu, N, H, L);
    //total_score = p_stu[i][1] + p_stu[i][2];
    /*    for (i = 0; i < N; i++)
          {
          for (j = 0; j < 4; j++)
          {
          printf("%d ",*(*(p_stu + i) + j));
          }
          printf("\n");
          }
          */
    if (NULL != p_stu)
    {
        arr_free(p_stu, N);
        p_stu = NULL;
    }

    return 0;
}

#include "stdlib.h"
#include "stdio.h"

int ** inputABC(int line_num, int row_num)
{
    int i;
    int **input = NULL;
    input = (int **)malloc(line_num*sizeof(int*));
    if (NULL == input)
    {
        printf("malloc err");
        return NULL;
    }
    for (i = 0; i < line_num; i++)
    {
        input[i] = (int *)malloc(row_num*sizeof(int));
    }

    return input;
}

int input_free(int ** input,int line_num)
{
    int i;

    if (NULL == input)
    {
         return 0;
    }
    for (i = 0; i < line_num; i++)
    {
        if (NULL != input[i])
        {
            free(input[i]);
            input[i] = NULL;
        }
    }
    if (NULL != input)
        free(input);

    return 0;
}

int main()
{
    int line_num=3, row_num=3, i, j;
    int **input = NULL;

    input = inputABC(line_num, 3);

    for (i = 0; i < line_num; i++)
    {
        for (j = 0; j < row_num; j++)
        {
            scanf("%d", &input[i][j]);
        }
    }
    printf("打印保存的数组input:\n");
    for (i = 0; i < line_num; i++)
    {
        for (j = 0; j < row_num; j++)
        {
            printf("%d ", input[i][j]);
        }
        printf("\n");
    }
    printf("=====\n");

//复制 n*3 二维数组
    int coparr[1][3];
    for (i = 0; i < 3; i++)
    {
        //*coparr[i] = *input[i];
        memcpy(*coparr, *(input+i), sizeof(int)*3);
       // memcpy(coparr[0], input[i], sizeof(int)*3);
        for (j = 0; j < 3; j++)
        {
            printf("copy:%d ", coparr[0][j]);
        }
        printf("\n");
    }

    if (NULL != input)
    {
        input_free(input, row_num);
        input = NULL;
    }

//        printf("input[i]:%d\n", input[0]);
    return 0;
}

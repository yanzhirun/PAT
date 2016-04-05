#include "stdlib.h"
#include "stdio.h"

long int ** inputABC(int line_num, int row_num)
{
    int i;
    long int **input = NULL;
    input = (long int **)malloc(line_num*sizeof(long int*));
    if (NULL == input)
    {
        printf("malloc err");
        return NULL;
    }
    for (i = 0; i < line_num; i++)
    {
        input[i] = (long int *)malloc(row_num*sizeof(long int));
    }

    return input;
}

int input_free(long int ** input)
{
    int i;

    if (NULL == input)
    {
         return 0;
    }
    for (i = 0; i < 3; i++)
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
    int line_num, i, j;
    scanf("%d", &line_num);
    long int **input = NULL;

    input = inputABC(line_num, 3);

    for (i = 0; i < line_num; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%ld", &input[i][j]);
        }
    }
    for (i = 0; i < line_num; i++)
    {
        if ((input[i][0] + input[i][1]) > input[i][2])
            printf("Case #%d: true\n", i+1);
        else
            printf("Case #%d: false\n", i+1);
    }
/*
    for (i = 0; i < line_num; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%ld ", input[i][j]);
        }
        printf("\n");
    }
*/

    if (NULL != input)
    {
        input_free(input);
        input = NULL;
    }

//        printf("input[i]:%d\n", input[0]);
    return 0;
}

#include "stdlib.h"
#include "stdio.h"

float **create_arr (int N)
{
    int i;
    float ** p_f_array = NULL;
    p_f_array = (float **)malloc(sizeof(float*)*N);
    for (i = 0; i < N; i++)
    {
        p_f_array[i] = (float*)malloc(sizeof(float)*3);
    }

    return p_f_array;
}

int free_array (float ** array, int N)
{
    int i;

    if (NULL == array)
    {
        printf ("free_array  err\n");
        return 0;
    }
    for (i = 0; i < N; i++)
    {
         free (array[i]);
         array[i] = NULL;
    }
    free (array);

    return 0;
}

int cmp (const void *a, const void *b)
{
    float **left = (float **)a;
    float **right = (float **)b;

    return (*left)[2] < (*right)[2];
}

int calculate (int i_kind, int i_need, float **p_commodity)
{
    int ret = 1, i = 0;
    if (NULL == p_commodity)
    {
        ret = 0;
        printf ("calculate err\n");
        return ret;
    }

    for (i = 0; i < i_kind; i++)
    {
        p_commodity[i][2] = p_commodity[i][1]/p_commodity[i][0];
    }
    qsort (p_commodity, i_kind, sizeof(float), cmp);

    for (i = 0; i < i_kind; i++)
    {
        printf ("danjia :%.2f   \n", p_commodity[i][2]);
    }

    return ret;
}

int main()
{
    int i_kind, i_need, i;
    int *p_store = NULL;
    int *p_total_price = NULL;
    float **p_commodity = NULL;

    scanf ("%d%d", &i_kind, &i_need);

    p_commodity = create_arr(i_kind);
    for (i = 0; i < i_kind; i++)
    {
    //    scanf ("%f", &p_commodity[i][0]);
    //    scanf ("%f", (p_commodity+i)[0]);
        scanf ("%f", *(p_commodity+i));
    }
    for (i = 0; i < i_kind; i++)
    {
        //scanf ("%f", (p_commodity+i)[1]);//wrong!!!按列输入！取地址，数组内容在内存中连续存储
        scanf ("%f", *(p_commodity+i)+1);
    }

    calculate(i_kind, i_need, p_commodity);

    for (i = 0; i < i_kind; i++)
    {
        printf("%f   %f    ", p_commodity[i][0], p_commodity[i][1]);
        printf ("danjia :%.2f   \n", p_commodity[i][2]);
    }

    return 0;
}

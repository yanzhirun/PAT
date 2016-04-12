#include "stdlib.h"
#include "stdio.h"

float **create_arr (int N)
{
    int i;
    float ** p_f_array = NULL;
    p_f_array = (float **)malloc(sizeof(float*)*N);
    if (NULL == p_f_array)
    {
        printf ("malloc err");
        return NULL;
    }
    for (i = 0; i < N; i++)
    {
        p_f_array[i] = (float*)malloc(sizeof(float)*3);
    //    memset (p_f_array+i, 0, sizeof(float)*3);
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
        if (NULL != array[i])
        {
            free (array[i]);
            array[i] = NULL;
        }
    }
    if (NULL != array)
    {
        free (array);
    }

    return 0;
}

int cmp (const void *a, const void *b)
{
    float **left = (float **)a;
    float **right = (float **)b;

    return (*left)[2] <= (*right)[2] ? 1: -1;
}

int total_price (int i_kind, int i_need, float **p_commodity)
{
    int i = 0;
    float total = 0;
    float price = 0;
    while(p_commodity[i][0] <= i_need - total)
    {
        total += p_commodity[i][0];
        price += p_commodity[i][1];
        //        printf("price all:%.2f", price);
        i++;
        if (i_kind <= i)
            break;
    }
    if (i < i_kind)
    {
        price += p_commodity[i][2] * (i_need - total);
    }
    printf("%.2f", price);
    return 0;
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
//    for (i = 0; i < i_kind; i++)
//    {
//        printf("%f",p_commodity[i][0]);
//        printf("%f",p_commodity[i][1]);
//        printf("%f",p_commodity[i][2]);
//    }
    for (i = 0; i < i_kind; i++)
    {
        p_commodity[i][2] = p_commodity[i][1]/p_commodity[i][0];
    }
    qsort (p_commodity, i_kind, sizeof(*p_commodity), cmp);
    total_price(i_kind, i_need, p_commodity);

//       for (i = 0; i < i_kind; i++)
//        {
//            printf ("danjia :%.2f   \n", p_commodity[i][2]);
//        }

    return ret;
}

int main()
{
    int i_kind, i_need, i;
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
        //*(*(p_commodity+i)+2) = 0;
//        p_commodity[i][2] = 0;
    }

    calculate(i_kind, i_need, p_commodity);

    //   for (i = 0; i < i_kind; i++)
    //    {
    //       printf("%f   %f    ", p_commodity[i][0], p_commodity[i][1]);
    //        printf ("danjia :%.2f   \n", p_commodity[i][2]);
    //    }
    if (NULL != p_commodity)
    {
        free_array (p_commodity, i_kind);
        p_commodity == NULL;
    }

    return 0;
}

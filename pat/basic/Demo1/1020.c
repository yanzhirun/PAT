#include "stdlib.h"
#include "stdio.h"

int cmp (const void *a, const void *b)
{
    return (float*)b - (float*)a;
}
int calculate (int i_kind, int i_need, int * p_store, int * p_total_price)
{
    int ret = 1, i = 0;
    float *p_price_single = NULL;
    if (NULL == p_store || NULL == p_total_price)
    {
        ret = 0;
        printf ("calculate err\n");
        return ret;
    }

    p_price_single = (float*)malloc(sizeof(float)*i_kind);

    for (i = 0; i < i_kind; i++)
    {
        p_price_single[i] = (float)p_total_price[i]/(float)p_store[i];
    }
    printf ("%d",p_total_price[0]);
//    qsort (p_total_price, i_kind, sizeof(float), cmp);

    for (i = 0; i < i_kind; i++)
    {
        printf ("danjia:%f ", p_price_single[i]);
    }
    if (NULL != p_price_single)
    {
        free (p_price_single);
        p_price_single = NULL;
    }

    return ret;
}

int main()
{
    int i_kind, i_need, i;
    int *p_store = NULL;
    int *p_total_price = NULL;

    scanf ("%d%d", &i_kind, &i_need);

    p_store = (int*)malloc(sizeof(int)*i_kind);
    p_total_price = (int*)malloc(sizeof(int)*i_kind);
    for (i = 0; i < i_kind; i++)
    {
        scanf ("%d", p_store+i);
    }
    for (i = 0; i < i_kind; i++)
    {
        scanf ("%d", p_total_price+i);
    }

    calculate(i_kind, i_need, p_store, p_total_price);

//    for (i = 0; i < i_kind; i++)
//    {
//        printf ("%d ", p_store[i]);
//        printf ("%d ", p_total_price[i]);
//    }

    if (NULL != p_store)
    {
         free (p_store);
         p_store = NULL;
    }
    if (NULL != p_total_price)
    {
         free (p_total_price);
         p_total_price = NULL;
    }
    return 0;
}

#include "stdlib.h"
#include "stdio.h"

int cmp (const void* p, const void* q)
{

    return (*(long int*)p)- *(long int*)q;
}

int perfect_arr (long int* p_arr_input, int N, double p)
{
    int i = 0, ret = 1, j = 0, out = 0;
    double tmp_min;
    if (NULL == p_arr_input)
    {
        ret = -1;
        printf("perfect_arr err\n");
        return ret;
    }

    qsort (p_arr_input, N, sizeof(long int), cmp);

    for (i = 0; i < N; i++)
    {
        if (N - i <= out)
            break;
        for (j = i + out; j < N; j++)
        {
            if(p_arr_input[j] > p_arr_input[i]*p)
            {
                break;
            }
            out = out >= j - i+1 ?out:j-i+1;
        }
    }
    printf ("%d",out);

    return ret;
}

int old_perfect_arr (long int* p_arr_input, int N, double p)
{
    int i = 0, ret = 1, j = 0, out = 0;
    double tmp_min;
    if (NULL == p_arr_input)
    {
        ret = -1;
        printf("perfect_arr err\n");
        return ret;
    }

    qsort (p_arr_input, N, sizeof(long int), cmp);

    for (i = 0; i < N; i++)
    {
        if (N - i <= out)
            break;
        if(p_arr_input[i+out-1] > p_arr_input[i]*p)
            continue;
        tmp_min = p_arr_input[i]*p;
        for (j = N - 1; j > i; j--)
        {
            if (j-i+1 <= out)
                break;
            //printf ("i:%d j:%d\n", i, j);
            //printf ("min %d max %d\n", p_arr_input[i], p_arr_input[j]);
            if (tmp_min< p_arr_input[j])
            {
                continue;
            }
            else if (tmp_min >= p_arr_input[j])
            {
                out = out >= j-i+1 ? out:j-i+1;
                break;
            }
        }
    }
    printf ("%d",out);

    return ret;
}

int main()
{
    int N, i;
    double p;
    long int* p_arr_input = NULL;
    scanf ("%d%lf", &N, &p);
    p_arr_input = (long int*)malloc(sizeof(long int)*N);
    for (i = 0; i < N; i++)
    {
        scanf ("%ld", p_arr_input+i);
    }

    perfect_arr (p_arr_input, N, p);

    //    for (i = 0; i < N; i++)
    //    {
    //        printf("%d  ", p_arr_input[i]);
    //    }

    if (NULL != p_arr_input)
    {
        free(p_arr_input);
        p_arr_input = NULL;
    }

    return 0;
}

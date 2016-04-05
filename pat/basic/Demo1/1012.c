#include "stdlib.h"
#include "stdio.h"

int sortA (int * input, int N)
{
    int ret = 0, i = 0, j = 0, k = 0;
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    float A4 = 0;
    int *output = NULL;
    output = (int*)malloc(N*sizeof(int));
    if (NULL == input)
    {
        ret = 1;
        return ret;
    }

    for (i = 0; i < N; i++)
    {
        if (input[i] % 5 == 0 && input[i] % 2 == 0)
            A1 += input[i];
        if (input[i] % 5 == 1)
        {
            output[j] = input[i];
            j++;
        }
        if (input[i] % 5 == 2)
        {
            A3++;
        }
        if (input[i] % 5 == 3)
        {
            k++;
            A4 += input[i];
        }
        if (input[i] % 5 == 4)
        {
            A5 = (A5 > input[i] ? A5 : input[i]);
        }
    }
    //A2
    if (j % 2 == 1)
    {
        j++;
        output[j] = 0;
    }
    for (i = 0; i < j; i++,i++)
    {
        A2 += output[i] - output[i+1];
    }

    if (0 == A1)
        printf("N ");
    else{
        printf("%d ", A1);
    }

    if (0 == j)
    {
        printf ("N ");
    }
    else{
        printf("%d ", A2);
    }

    if (0 == A3)
        printf("N ");
    else{
        printf("%d ", A3);
    }

    if (0 == k)
        printf("N ");
    else{
        A4 = A4/k;
        printf("%.1f ", A4);
    }

    if (0 == A5)
        printf("N");
    else{
        printf("%d", A5);
    }

    if (NULL != output)
    {
        free(output);
        output = NULL;
    }

    return ret;
}

int main()
{
    int N = 0, i = 0;
    int *input = NULL;
    scanf("%d", &N);
    input = (int *)malloc(N*sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", input+i);
    }

    //    for (i = 0; i < N; i++) { printf("%d ",*(input+i)); }

    sortA(input, N);
    if (NULL != input)
    {
        free(input);
        input = NULL;
    }

    return 0;
}

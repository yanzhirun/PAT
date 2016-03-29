#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int callatz(int N, int i, int * output)
{
    int err = 0;
    int n = N;
    output[n] = n;
    while(n != 1)
    {
        if (n%2 == 0)
        {
            n = n/2;
            output[n] = n;
            i++;
            return callatz(n, i, output);
        }
        else
        {
            n = (n * 3 + 1)/2;
            output[n] = n;
            i++;
            return callatz(n, i, output);
        }
        //return err;
    }
    //printf("%d\n", i);
}

int sortinput2(int num, int * input)
{
    int err = 0;
    int temp, i, j;
    if (NULL == input)
    {
        err = 1;
        printf("input err:%d", err);
        return err;
    }
    for (i = 0; i < num; i++)
    {
        for (j = i; j < num; j++)
        {
            if (input[i] <= input[j])
            {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
    return err;
}
int sortinput(int num, int * input)
{
    int err = 0;
    int temp, i, j;
    if (NULL == input)
    {
        err = 1;
        printf("input err:%d", err);
        return err;
    }
    for (i = 0; i < num; i++)
    {
        for (j = i; j < num; j++)
        {
            if (input[i] >= input[j])
            {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }
    return err;
}

int findkey(int n, int * input, int *output)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        if (input[i] == 0)
            continue;
        printf("input[%d]:%d ", i, input[i]);
        callatz(input[i], 0, output);
        for (j = 0; j < 300; j++)
        {
            if (output[j] != 0)
                printf("output[%d]:%d",j,output[j]);
        }
        printf("\n--------------\n");
        for (j = i+1; j < 300; j++)
        {
                    if (input[j] == output[input[j]])
                    {
                        input[j] = 0;
                    }
        }
    }

    return 0;

}


int main()
{
    int num, i, input[100] = {0};
    int output[300] = {0};
    for (i = 0; i < 300; i++)
    {
        output[i] = 0;
        input[i] = 0;
    }
    scanf("%d", &num);
    for(i = 0; i < num; i++)
    {
        scanf("%d", input+i);
    }

    sortinput (num, input);

    findkey(num, input, output);
    sortinput2 (num, input);
    findkey(num, input, output);

    int k = 0, key[100] = {0};
    for (i = 0; i < num; i++)
    {
        if (0 != input[i])
        {
            if (1 != input[i])
                if (input[i] != output[input[i]])
                {
                    key[k]=input[i];
                    k++;
                    printf("%d", input[i]);
                }
        }
    }
    printf("----------\n");
    for (i = 0; i < k - 1; i++)
    {
        printf("%d ", key[i]);
    }
    printf("%d",key[k-1]);
    return 0;
}



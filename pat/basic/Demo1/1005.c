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

    for (i = 0; i < num; i++)
    {
        if (0 != input[i])
        {
            printf("thekey:%d ", input[i]);
        }
    }

    return 0;
}



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int callatz(int N, int i)
{
    int err = 0;
    int n = N;
    while(n != 1)
    {
        if (n%2 == 0)
        {
            n = n/2;
            i++;
            return callatz(n, i);
        }
        else
        {
            n = (n * 3 + 1)/2;
            i++;
            return callatz(n, i);
        }
        //	return err;
    }
    printf("%d\n", i);
}

void main()
{
    int N;
    int ret;
    //printf("Please input the number:");
    scanf("%d",&N);
    ret = callatz(N, 0);

    return ;
}


#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int prime(int n)
{
    int i, ret =1;
    for (i = 2; i <= sqrt (n); i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return ret;
}

int get_prime(int Pm, int Pn, int *output)
{
    int i = 3, j = 1, k = 0;
    if (NULL == output)
    {
        printf("output create err");
        return 0;
    }
    output[0] = 2;
    //    printf("%d", output[0]);
    do{
        if (prime(i))
        {
            output[j] = i;
            //printf("%d ", output[j]);
            j++;
        }
        i++;
    }while(j <= Pn);
    if (Pm == Pn)
    {
        goto last;
    }
    for (i = 1,k = Pm; k < Pn; i++, k++)
    {
        printf ("%d", output[k-1]);
        if (i % 10 == 0)
            printf("\n");
        else{
            printf (" ");
        }
    }
last:
    printf ("%d", output[Pn-1]);

    return 0;
}

int main()
{
    int Pm, Pn;
    int* output = NULL;

    scanf("%d", &Pm);
    scanf("%d", &Pn);
    output = (int *)malloc(Pm * sizeof(int));
    get_prime (Pm, Pn, output);
    if (NULL == output)
        free(output);

    return 0;
}

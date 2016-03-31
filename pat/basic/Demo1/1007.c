#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int primetest(int input)
{
    int err = 0;
    int i;
    for (i = 2; i < input; i++)
    {
        if ( input%i == 0 )
        {
            err = 1;
            return err;
        }
    }

    return err;
}

int main()
{
    int i, j = 0, n = 0, k = 0, num;
    int prime[1000] = {0};
    scanf("%d", &num);

    printf("num:%d is %d(0 yes ,1 no) \n",num , primetest(num));

    for ( i = 3; i < num; i++ )
    {
         if (primetest(i) == 0)
         {
            prime[j] = i;
            printf("prime%d\n", prime[j]);
            j++;
         }
         else{
             continue;
         }
    }
    do
    {
         k++;
         if(prime[k] - prime[k-1] == 2)
         {
           n++;
         }
    }while(prime[k] = 0);
    printf("%d", n);
    return 0;
}

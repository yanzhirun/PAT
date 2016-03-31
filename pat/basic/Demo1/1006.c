#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    int i;
    int num[3] = {0};
    int n;

    scanf("%d", &n);
    if (n >= 1000 || n < 0)
        return 0;
    if (n<1000 && n>99)
    {
        num[0] = n/100;
        goto shiwei;

    }
    if (n >= 10 && n <= 99)
    {
shiwei:
        num[1] = (n - num[0]*100)/10;
        goto gewei;

    }
    if (n >0 && n <10)
    {
gewei:
        num[2] = (n - num[0]*100 - num[1]*10);

    }
    /*
     *     printf ("num:%d\n", num[0]);
     *         printf ("num:%d\n", num[1]);
     *             printf ("num:%d\n", num[2]);
     *                 */
    for (i = 0; i < num[0]; i++)
        printf("B");
    for (i = 0; i < num[1]; i++)
        printf("S");
    for (i = 1; i <= num[2]; i++)
        printf("%d",i);

    return 0;

}



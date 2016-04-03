#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define N 100

int derivation(int *polynomial, int *output, int length)
{
    int ret = 0, i = 0;

    if (NULL == polynomial)
    {
        ret = -1;
        printf("err polynomial\n");
        return ret;
    }
for (i = 0; i < length ;i++, i++)
{

    output[i] = polynomial[i]*polynomial[i+1];
    output[i+1] = polynomial[i+1] - 1;
 }
    return ret;
}
int main()
{
    int i = 0, length = 0;
    int polynomial[N] ,output[N];
/*    for (i = 0; getchar() != '\n'; i++)
    {
        scanf("%d", &polynomial[i]);
    }
*/
    while(1)
    {
        scanf("%d", &polynomial[i++]);
        if (getchar() == '\n')
            break;
    }
// char polynomial[N];   fgets(polynomial,sizeof(polynomial),stdin);
    length = i;
    derivation(polynomial,output,length);
//    printf("length:%d\n", length);
    for (i = 0; i < length; i++)
    {
        printf("%d ", polynomial[i]);
    }
        printf("------------\n");
    for (i = 0; i < length; i++)
    {
        printf("%d ", output[i]);
    }

    return 0;
}

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int dived_bignum(char *c_bignum, int i_divnum, int length)
{
    int ret = 1;
    int i, remain = 0, result = 0;
    int i_one_divnum;
    if (NULL == c_bignum)
    {
        ret = 0;
        printf("c_bignum err");
        return ret;
    }

    if (length <= 1)
    {
        result = (int)(c_bignum[0] - '0');
        if (result == 0)
        {
            printf("0 0");
            return ret;
        }
        remain = result%i_divnum;
        result = (result < i_divnum) ? 0:result/i_divnum;
        printf("%d %d", result, remain);
        return ret;
    }
 //   printf("i_divnum:%s\n",c_bignum);
    for (i = 0; i < length; i++)
    {
        i_one_divnum=(int)(c_bignum[i] - '0');
  //      printf ("%d\n", i_one_divnum);
        i_one_divnum += remain*10;
        remain = i_one_divnum%i_divnum;
        result = i_one_divnum/i_divnum;
    //    printf("result:%d  remain: %d", result, remain);
        if (i == 0 && result == 0)
            continue;
        printf ("%d", result);
    }
    printf(" %d", remain);


    return ret;
}
int main()
{
    char c_num[1000];
    int i_divnum, N;
    scanf("%s%d", c_num, &i_divnum);

//    printf("%s  %d",c_num,i_divnum);
    N = strlen(c_num);
//    printf("N = %d\n",N);
    dived_bignum(c_num, i_divnum, N);


    return 0;
}

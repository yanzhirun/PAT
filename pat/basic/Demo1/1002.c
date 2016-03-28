#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

int print_num(char num[101])
{
    int err = 0;
    int i;
    int result = 0;
    char *pinyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    if (num == NULL)
    {
        err = 1;
        printf("wrong num :%d \n", err);
        return err;
    }

    for (i = 0; i <= 100; i++)
    {
        if(num[i] != 0)
        {
            result += (int)(num[i] - '0');
            //printf("numi%d",(int)(num[i] ));
        }
    }
    //printf("result%d\n", result);

    //打印piny
    int j , s, a[3]={0},k;
    s = result;
    for ( j = 0; j < 3; j++)
    {
        a[j] = s%10;
        //printf("---==");
        //printf("a[%d]=%d \n", j, a[j]);
        s /= 10;
    }
    //printf("\npinyin====\n");
    if (a[2] != 0)
    {
        printf("%s %s %s",pinyin[a[2]],pinyin[a[1]],pinyin[a[0]]);
    }
    else if (a[1] != 0)
    {
        printf("%s %s",pinyin[a[1]], pinyin[a[0]]);
    }
    else
    {
        printf("%s",pinyin[a[0]]);
    }

    return err;
}

int main()
{
    char num[101] = {'0'};

    scanf("%100s", num);
    print_num(num);

    return 0;
}

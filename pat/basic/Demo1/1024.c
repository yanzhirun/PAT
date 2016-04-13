#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int convert_num (char * num_A)
{
    int ret = 1, i = 0 , j = 0, i_tmp, tmp, k;
    char *p_tmp = NULL;
    if (NULL == num_A)
    {
        ret = 0;
        printf ("convert_num err\n");
        return ret;
    }
    //输出符号
    if ('-' == num_A[0])
    {
        printf ("-");
    }
    //tmp 表示 E前面有多少位   i_tmp 是指数的绝对值
    p_tmp =strchr(num_A, 'E');
    i_tmp = atoi (p_tmp+2);
    tmp = (int)(p_tmp - num_A);
//    printf ("E: %d  i_tmp:%d\n", tmp, i_tmp);
    if (i_tmp == 0)
    {
        for (i = 1; i < tmp ; i++)
        {
            printf ("%c", num_A[i]);
        }
        return 0;
    }
    //指数为负数
    if ('-' == p_tmp[1])
    {
        printf ("0.");
        for (j = 1; j < i_tmp; j++)
        {
            printf ("0");
        }
        for (i = 1; i < tmp; i++)
        {
            if (num_A[i] == '.')
            {
                continue;
            }
            printf ("%c", num_A[i]);
        }
    }
    //printf ("E: %d\n",i_tmp);
    //printf("\np_tmp:%s\n", p_tmp);
    else if ('+' == p_tmp[1])
    {
        //需要补零
        j = 0;
        for (i = 1; i < tmp; i++)
        {
            j++;
            if (num_A[i] == '.')
            {
                continue;
            }
            printf ("%c", num_A[i]);
            //printf ("\n tmp %d i_tmp %d j: %d ", tmp, i_tmp, j);
            if (j == i_tmp + 2 && j < tmp - 1)
                printf (".");
        }
        //补零
        //           printf ("tmp %d   i_tmp %d", tmp ,i_tmp);
        if (i_tmp > tmp - 3)
        {
            for (i = 0; i < i_tmp - tmp + 3; i++)
                printf ("0");
        }
    }

    return ret;
}

main()
{
    char num_A[9999] = {0};

    scanf ("%s", num_A);
    convert_num(num_A);
    //    printf ("%s", num_A);

    return 0;
}

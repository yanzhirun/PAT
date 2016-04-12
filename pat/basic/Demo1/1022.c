#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int conversion_num(int i_A, int i_B, int i_D, int *c_num_output)
{
    int i = 0, j, ret = 1, num = 0, tmp = 0;
    if (NULL == c_num_output)
    {
        ret = 0;
        printf("conversion_num err\n");
        return ret;
    }

    num = i_A + i_B;
    if (2 == i_D)
    {
        tmp = num;
        do{
            c_num_output[i]= tmp % 2;
            printf ("cnum i :%d\n", c_num_output[i]);
            tmp = tmp/2;
            printf ("tmp:%d\n", tmp);
            i++;
        }while(tmp != 0);
        for (j = i-1; j >= 0; j--)
        {
    //        printf ("%d",c_num_output[j]);
            //printf ("output:%d",c_num_output[j]);
        }
    }
    if (i_D == 10)
    {
        printf("%d", num);
        return ret;
    }


    return ret;
}

int main()
{
    int c_num_output[30];
    int i_A, i_B, i_D, i = 0, j = 0;
    int length_A = 0, length_B = 0;
    scanf ("%d%d%d", &i_A, &i_B, &i_D);

    conversion_num(i_A, i_B, i_D, c_num_output);

    printf ("A:%d B:%d\n", i_A, i_B);

    return 0;
}

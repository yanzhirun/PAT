#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int Get_every(int new_num,int *arr_num)
{
    int i;
    for (i = 3; i >= 0; i--)
    {
        arr_num[3-i] = new_num/(int)pow(10,i);
        new_num = new_num%(int)pow(10,i);
    }

    return 0;
}

int cmp(const void * a, const void * b)
{
    return *(int *)a - *(int *)b;
}

int Kaprekar(int *arr_num, int new_num)
{
    int ret = 1, i = 0, num_1, num_2;
    if (NULL == arr_num)
    {
        ret =0;
        printf ("Kaprekar err\n");
        return ret;
    }
//    if (new_num == 6174)
//    {
//        printf ("7641 - 1467 = 6174");
//        return ret;
/* //    } */
    //    if ( new_num == 0 )
    //    {
    //        return 0;
    //    }
    if (arr_num[0] == arr_num[1] && arr_num[0] == arr_num[2] && arr_num[0] == arr_num[3])
    {
        //        printf ("%d - %d = 0000", new_num, new_num);
        for (i = 0; i < 4; i++)
        {
            printf ("%d",arr_num[0]);
        }
        printf (" - ");
        for (i = 0; i < 4; i++)
        {
            printf ("%d",arr_num[0]);
        }
        printf (" = 0000\n");
        return ret;
    }

    while (new_num != 6174)
    {
        qsort(arr_num, 4, sizeof(int), cmp);
        num_1 = arr_num[3]*1000 + arr_num[2]*100 + arr_num[1]*10 +arr_num[0];
        num_2 = arr_num[0]*1000 + arr_num[1]*100 + arr_num[2]*10 +arr_num[3];
        //        printf("num1%d  num2%d", num_1, num_2);
        new_num = num_1 - num_2;
        for (i = 0; i < 4; i++)
        {
            printf ("%d",arr_num[3-i]);
        }
        printf (" - ");
        for (i = 0; i < 4; i++)
        {
            printf ("%d",arr_num[i]);
        }

        printf (" = ");
        Get_every(new_num, arr_num);
        for (i = 0; i < 4; i++)
        {
            printf ("%d",arr_num[i]);
        }
        printf ("\n");
        //        printf ("%d - %d = %d\n", num_1, num_2, num_1 - num_2);
        return Kaprekar(arr_num, new_num);
    }

    //  printf ("%d - %d = %d");
    //    for (i = 0; i < 4; i++)
    //    printf ("arr_num: %d  ",arr_num[i]);

    //    return ret;
}

int main()
{
    int num1, num2;
    int new_num, i = 0;
    int arr_num[4] = {0};
    scanf ("%d", &new_num);
    Get_every(new_num, arr_num);

    if (new_num == 6174)
    {
        printf ("7641 - 1467 = 6174");
        return 0;
    }
    Kaprekar(arr_num,new_num);

    return 0;
}

#include "stdlib.h"
#include "stdio.h"

int output_min (int *arr_input)
{
    int ret = 1, i = 0, j = 0;
    if (NULL == arr_input)
    {
        ret = 0;
        printf("output_min err\n");
        return ret;
    }

    if (0 == arr_input[0])
    {
        for (i = 1; i < 10; i++)
        {
            while(0 < arr_input[i])
            {
                printf("%d", i);
                arr_input[i]--;
            }
        }
    }
    else if (arr_input[0] > 0)
    {
        i = 1;
        while (arr_input[i] <= 0)
        {
            i++;
        }
        printf ("%d", i);

        for (j = 0; j < arr_input[0]; j++)
        {
             printf ("0");
        }
        arr_input[i] -= 1;
        //printf ("input i %d\n", arr_input[i]);
        for (j = i; j < 10; j++)
        {
            while(0 < arr_input[j])
            {
                printf("%d", j);
                arr_input[j]--;
            }
        }
   }

        return ret;
}
int main()
{
    int i;
    int arr_input[10] = {0};
    for (i = 0; i < 10; i++)
    {
        scanf ("%d", arr_input+i);
    }

    output_min (arr_input);

//    for (i = 0; i < 10; i++)
//    {
//        printf ("%d ", arr_input[i]);
//    }
    return 0;
}

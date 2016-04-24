#include "stdlib.h"
#include "stdio.h"

int main()
{
    char c_num[100][19];
    int j, i, sum = 0, N, i_Z = 0, err = 0;
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char M[12] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
//    char M[12] = {1, 0, 'X', 9, 8, 7, 6, 5, 4, 3, 2};
    scanf ("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s", c_num[i]);
    }

//    for (i = 0; i < 17; i++)
//        printf ("%d",weight[i]);
//    printf("-----\n");
    for (i = 0; i < N; i++)
    {
        sum = 0;
        for (j = 0; j < 17; j++)
        {
            sum +=( (int)(c_num[i][j] -'0')*weight[j]);
        }
        i_Z = sum%11;
        if (M[i_Z] != c_num[i][17])
        {
            err++;
            printf("%s\n",c_num[i]);
        }
        //printf ("sum:%d  i_Z:%d", sum, i_Z);
    }
    if (!err)
    {
        printf("All passed");
    }
    //i_Z = mod(sum,11);
    return 0;
}

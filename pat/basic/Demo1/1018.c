#include "stdlib.h"
#include "stdio.h"

int judge(char c_A, char c_B, int *p_A, int *p_win)
{
    int ret = 0;
    if (NULL == p_A || NULL == p_win)
    {
        ret = 1;
        printf("judge err");
        return ret;
    }
    if (c_A == c_B)
    {
        if (c_A == 'C')
        {
            p_win[6]++;
        }
        else if (c_A == 'J')
        {
            p_win[7]++;
        }
        else if (c_A == 'B')
        {
            p_win[8]++;
        }
        p_A[1]++;
        return ret;
    }

    switch(c_A)
    {
        case 'B':
            if (c_B == 'C')
            {
                p_A[0]++;
                p_win[0]++;
            }
            else
            {
                p_A[2]++;
            p_win[5]++;
            }
            break;
        case 'C':
            if (c_B == 'J')
            {
                p_A[0]++;
                p_win[1]++;
            }
            else
            {
            p_A[2]++;
            p_win[3]++;
            }
            break;
        case 'J':
            if (c_B == 'B')
            {
                p_A[0]++;
                p_win[2]++;
            }
            else{
                p_A[2]++;
            p_win[4]++;
            }
            break;
        default:
            break;
    }

    return ret;
}

int main()
{
    int N, i = 0, tmp = 0;
    char c_A, c_B;
//p_A 胜负平 p_win B C J 赢得次数
    int p_A[3] = {0};
    int p_win[9] = {0};
    scanf("%d", &N);
    getchar();
    for (i = 0; i < N; i++)
    {

        scanf("%c", &c_A);
        getchar();
        scanf("%c", &c_B);
        getchar();

        judge(c_A, c_B, p_A, p_win);
    }

//    if (N == 0)
//    {
//        printf("0 0 0\n");
//        return 0;
//    }
    //    printf ("N = %d  p_A1 %d\n",N, p_A[1]);
//    if (p_A[1] == N)
//    {
//        printf("0 %d 0\n", N);
//        //        tmp = 0;
//        //        i = 6;
//        //        tmp = ((p_win[i] >= p_win[tmp = (p_win[i+1] >= p_win[i+2] ? (i+1) : (i+2))]) ? i : tmp )- i;
//        //
//        //        if (tmp == 0)
//        //            printf ("B B\n");
//        //        else if (tmp == 1)
//        //            printf ("C C\n");
//        //        else if (tmp == 2)
//        //            printf ("J J\n");
//        return 0;
//    }
//
    printf("%d %d %d\n", p_A[0], p_A[1], p_A[2]);
    printf("%d %d %d\n", p_A[2], p_A[1], p_A[0]);

    for (i = 0; i <= 3; i++, i++, i++)
{
    tmp = 0;
 //   printf("%d %d %d\n", p_win[0], p_win[1], p_win[2]);
    tmp = ((p_win[i] >= p_win[tmp = (p_win[i+1] >= p_win[i+2] ? (i+1) : (i+2))]) ? i : tmp )- i;
//    printf("%d %d %d\n", p_win[3], p_win[4], p_win[5]);
   // printf ("tmp = %d", tmp);
    if (tmp == 0)
        printf ("B");
    else if (tmp == 1)
        printf ("C");
    else if (tmp == 2)
        printf ("J");
    if (i == 0)
        printf (" ");
}
//    printf("output OK:%d", p_A[2]);

//   printf("%d %c", N, c_A);
    return 0;
}

#include "stdlib.h"
#include "stdio.h"

typedef struct {
    char stu_num[14];
    int test_seat_num;
    int real_seat_num;
}Info_stu;

int main()
{
    int N, M, i, j;
    Info_stu info_stu_num[1001];
    char num_14[14];
    int test_seat_num, real_seat_num;
    int find_num[1001];
    scanf ("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf ("%s", info_stu_num[i].stu_num);
//        scanf ("%s", info_stu_num[i]->stu_num);
        scanf ("%d", &info_stu_num[i].test_seat_num);
//        scanf ("%d", &real_seat_num); info_stu_num[i]->real_seat_num = real_seat_num;
        scanf ("%d", &info_stu_num[i].real_seat_num);
    }
    scanf ("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf ("%d", find_num+i);
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (info_stu_num[j].test_seat_num == find_num[i])
            {
                printf("%s", info_stu_num[j].stu_num);
                printf(" %d\n", info_stu_num[j].real_seat_num);
            break;
            }
        }
    }

    return 0;
}

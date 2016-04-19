#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct{
    char name[6];
    int year, month, day;
}People;

People* creat_birth_arr(int N)
{
    int i ,ret = 1;
    People * birth = NULL;
    birth = (People*)malloc(sizeof(People)*N);
    for (i = 0; i < N; i++)
    {
        scanf ("%s %d/%d/%d", birth[i].name, &birth[i].year, &birth[i].month, &birth[i].day);
    }
    return birth;
}

int print_info (People* birth, int N)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        printf("%s %d/%d/%d\n", birth[i].name, birth[i].year, birth[i].month, birth[i].day);
    }
    return 0;
}

int cmp (const void* p, const void* q)
{
    People *left = (People*)p;
    People *right = (People*)q;
    if (left->year == right->year)
    {
        if (left->month == right->month)
        {
            return (left->day > right->day)?1:-1;
        }
        return (left->month > right->month)?1:-1;
    }
    return (left->year > right->year)?1:-1;
}

int judge_info (People* birth, int N)
{
    int num = 0, i = 0, left = N;
    if (NULL == birth)
    {
        printf("judge_info err");
        return 0;
    }

    for (i = 0; i < N; i++)
    {
        if (1814 > birth[i].year || (1814 == birth[i].year && 9 > birth[i].month) || (1814 == birth[i].year && 9 == birth[i].month && 6 > birth[i].day))
        {
            left--;
            memset(birth+i, 0, sizeof(People));
        }
        else if (2014 < birth[i].year || (2014 == birth[i].year && 9 < birth[i].month) || (2014 == birth[i].year && 9 == birth[i].month && 6 < birth[i].day))
        {
            left--;
            memset(birth+i, 0, sizeof(People));
        }
    }

    qsort(birth, N, sizeof(People), cmp);

    for (i = 0; i < N; i++)
    {
        if (birth[i].year != 0)
        {
            break;
        }
    }
    if (left == 0)
    {
        printf ("0");
        return 0;
    }
    printf("%d %s %s", left, birth[i].name, birth[N-1].name);

    return 0;
}

int main()
{
    int N;
    People* s_people_info = NULL;
    scanf ("%d", &N);
    s_people_info = creat_birth_arr(N);
//    print_info (s_people_info, N);
    judge_info (s_people_info, N);
//    print_info (s_people_info, N);

    return 0;
}

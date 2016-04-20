#include "stdlib.h"
#include "stdio.h"

typedef struct{
    char name[6];
    int year, month, day;
}People;
//int creat_birth_arr(int** birth, int N)
//{
//    int i = 0, ret = 1;
//    if (NULL == birth)
//    {
//        ret = -1;
//        printf ("creat_birth_arr err\n");
//        return ret;
//    }
//    birth = (int**)malloc(sizeof(int*)*N);
//    if (NULL == birth)
//    {
//        ret = -2;
//        printf ("creat_birth_arr 1 err\n");
//        return ret;
//    }
//    for (i = 0; i < N; i++)
//    {
//        birth[i] = (int*)malloc(sizeof(int)*2);
//    }
//
//    return ret;
//}

People* creat_birth_arr(int N)
//int creat_birth_arr(People* birth, int N)
{
    int i ,ret = 1;
//    if (NULL == birth)
//    {
//        ret = -1;
//        printf("creat_birth_arr err\n");
//        return ret;
//    }
    People * birth = NULL;
    birth = (People*)malloc(sizeof(People)*N);
    for (i = 0; i < N; i++)
    {
        scanf ("%s %d/%d/%d", birth[i].name, &birth[i].year, &birth[i].month, &birth[i].day);
    }
    //printf ("%d", birth[0].year);

    printf ("malloc ok\n");
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
int main()
{
    int N;
    People* s_people_info = NULL;
    scanf ("%d", &N);
    s_people_info = creat_birth_arr(N);
    //creat_birth_arr(s_people_info, N);

    print_info (s_people_info, N);
    return 0;
}

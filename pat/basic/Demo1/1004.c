#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct _Student
{
    char name[16];
    char stunum[16];
    int score;

};

struct _Student* creat_stu(int num)
{
    int i;
    struct _Student* student = (struct _Student*)malloc(num*sizeof(struct _Student));
    if (NULL == student)
    {
        return NULL;
    }
    for (i = 0; i < num; i++)
    {
        memset(student+i, 0, sizeof(struct _Student));
    }

    return student;
}

void free_struct_stu(int num, struct _Student* student)
{
    int i;
    if (NULL == student)
    {
        return;
    }
    if (NULL != student)
    {
        free(student);
    }
}

void findstu(int n, struct _Student* stu)
{
    int i, min_stu = 0, max_stu = 0;

    for (i = 0; i < n; i++)
    {
        if (stu[min_stu].score > stu[i].score)
            min_stu = i;
        if (stu[max_stu].score < stu[i].score)
            max_stu = i;
    }
    printf("%s %s\n", stu[max_stu].name, stu[max_stu].stunum);
    printf("%s %s\n", stu[min_stu].name, stu[min_stu].stunum);
}

int main()
{
    int n;
    scanf("%d", &n);
    struct _Student * stu = creat_stu(n);
    //scanf_stu(n, stu);
    if (NULL == stu)
    {
        printf("stu created err\n");
        return 0;
    }
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%s", stu[i].name);
        scanf("%s", stu[i].stunum);
        scanf("%d", &(stu[i].score));
    }
    findstu(n, stu);
    free_struct_stu(n, stu);
    //system("pause");

    return 0;
}

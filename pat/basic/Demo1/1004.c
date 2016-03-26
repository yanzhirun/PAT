#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct _Student
{
    char name[10];
    char stunum[10];
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

    /*
    for (i = 0; i < num; i++)
    {
        char * pname = student[i].name;
        if (NULL != pname)
        {
            free(pname);
        }
        char * pstunum = student[i].stunum;
        if(NULL != pstunum)
        {
            free(pstunum);
        }
        if (NULL != student)
        {
            free(student);
        }
    }
*/
    if (NULL != student)
    {
        free(student);
    }
}

struct _Student* scanf_stu(int num, struct _Student* student)
{
    int i;
    for (i = 0; i < num; i++)
    {
         scanf("%s", student[i].name);
         scanf("%s", student[i].stunum);
         scanf("%d", &(student[i].score));
    }
/*    for (i = 0; i < num; i++)
    {
        printf("name:%s  number:%s  score:%d\n", student[i].name, student[i].stunum, student[i].score);
    }
*/
}


void findstu(int n, struct _Student* stu)
{
    int i, min_stu = 0, max_stu = 0;

    for (i = 0; i < n; i++)
    {
        if (stu[min_stu].score >= stu[i].score)
            min_stu = i;
        if (stu[max_stu].score <= stu[i].score)
            max_stu = i;
    }
    printf("%s %s\n", stu[max_stu].name, stu[max_stu].stunum);
    printf("%s %s\n", stu[min_stu].name, stu[min_stu].stunum);
}

int main()
{
    int i;
    struct _Student *stu;
    if (NULL == stu)
    {
        printf("stu created err\n");
        return ;
    }
    int n;
    scanf("%d", &n);

    stu = creat_stu(n);
    scanf_stu(n, stu);
    findstu(n, stu);

    free_struct_stu(n, stu);
    return 0;
}




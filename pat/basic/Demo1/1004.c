#include "stdlib.h"
#include "stdio.h"
#include "string.h"

struct _Student
{
    char name[10];
    char stunum[10];
    int score;
};

int test (struct _Student *Student, int n)
{
    int i, err = 0;
    if (NULL == Student)
    {
         printf("Student err:%d", err);
         err = 1;
         return err;
    }

    //if(i = 0; i < n; i++)
    {

        ;
    }
    return err;
}

struct _Student* creat_stu(int num)
{
    int i;
    struct _Student* student = (struct _Student*)malloc(num*sizeof(struct _Student));
    if (NULL == student)
    {
        return NULL;
    }

    return student;
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
    for (i = 0; i < num; i++)
    {
        printf("name:%s  number:%s  score:%d\n", student[i].name, student[i].stunum, student[i].score);
    }
}
int main()
{
    int i;
    struct _Student *stu;
    int n;
    scanf("%d", &n);
    stu = creat_stu(n);
    scanf_stu(n,stu);

//    test(stu, n);
    return 0;
}




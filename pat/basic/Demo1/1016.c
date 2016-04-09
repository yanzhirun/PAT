#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

int main()
{
    int i = 0, sum_A = 0, sum_B = 0, A = 0, B = 0;
    char c_A[10], c_B[10];
    char c_DA, c_DB;
    int i_DA, i_DB;
    char * p_A = NULL;
    char * p_B = NULL;

    scanf("%s", c_A);
    getchar();
    scanf("%c", &c_DA);
    //scanf("%s%s", c_A, &c_DA);
//    scanf("%s%s", c_B, &c_DB);
    scanf("%s", c_B);
    getchar();
    scanf("%c", &c_DB);

    i_DA = (int)(c_DA - '0');
    i_DB = (int)(c_DB - '0');
    //    printf("convert to char B:%d\n", i_DB);
    p_A = c_A;
    p_B = c_B;
    while (p_A = strchr(p_A, c_DA))
    {
        p_A++;
        sum_A++;
    }
    while (p_B = strchr(p_B, c_DB))
    {
        p_B++;
        sum_B++;
    }
    //    printf ("%d",sum_B);
    for(i= 0; i < sum_A; i++)
    {
        A += pow(10, i) * i_DA;
    }
    for(i= 0; i < sum_B; i++)
    {
        B += pow(10, i) * i_DB;
    }
    //    printf("A:%d\n", A);
    //    printf("B:%d\n", B);
    printf("%d", A+B);

    //    printf("%c", c_DA);
    //    printf ("%c\n", c_DA);
    //    printf("sum:%d\n",sum_A);
    //    printf ("c_A = %s  c_DA = %c\n", p_A, c_DA);

    return 0;
}

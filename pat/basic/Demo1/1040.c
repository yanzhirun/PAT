#include "stdlib.h"
#include "stdio.h"
#include "string.h"


int main ()
{
    char arr_input[100000];
    char* p_input_P = NULL;
    char* p_input_A = NULL;
    char* p_input_T = NULL;
    int i, num = 0, length = 0;
    int num_T = 0, num_AT = 0;

    scanf ("%s", arr_input);
    p_input_P = arr_input;
    length = strlen (arr_input);
    for (i = length - 1; i >= 0; i--)
    {
        if (arr_input[i] == 'T')
        {
            num_T++;
        }
        else if (arr_input[i] == 'A')
        {
            num_AT += num_T;
            num_AT = num_AT%1000000007;
        }
        else
        {
            num += num_AT;
        }
    }

//    while ((p_input_P = strchr(p_input_P+1,'P')) != NULL)
//    {
//        p_input_A = p_input_P;
//        while ((p_input_A = strchr(p_input_A+1, 'A')) != NULL)
//        {
//            p_input_T = p_input_A;
//            while ((p_input_T = strchr(p_input_T+1, 'T')) != NULL)
//            {
//                num++;
//            }
//        }
//    }

    printf("%d", num%1000000007);

    return 0;
}

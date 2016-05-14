#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main ()
{
    char arr_input[100000];
    int i, num = 0, length = 0;
    int num_T = 0, num_AT = 0;

    scanf ("%s", arr_input);
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
            num = num%1000000007;
        }
    }
    printf("%d", num);

    return 0;
}

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
int main()
{
    int i, j = 0, length_dest = 0, length_input;
    char c_dest[80], c_input[80];
    int err[80];
    scanf ("%s%s", c_dest, c_input);
    length_dest = strlen(c_dest);
    length_input = strlen(c_input);
    //printf ("length = %d \n", length_dest);
    for (i = 0; i < length_dest; i++)
    {
        if (NULL == strchr(c_input, c_dest[i]))
        {
            err[j++] = i;
     //       printf ("err[%d] = %d\n", j-1, err[j-1]);
        }
    }
    //printf ("err char\n");
    for (i = 0; i < j; i++)
    {
         printf("%c", c_dest[err[i]]);
    }
    //printf ("err char\n");

    //printf ("%s  %s\n", c_dest, c_input);

    return 0;
}

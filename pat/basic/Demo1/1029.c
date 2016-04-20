#include "stdlib.h"
#include "stdio.h"
#include "string.h"
int main()
{
    int i, j = 0, k = 0, length_dest = 0, length_input;
    char c_dest[80], c_input[80], c_out[80];
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

        c_out[i] = c_dest[err[i]];
//         printf("%c", c_dest[err[i]]);
    }

//        *(strchr(c_out, c_out[1])) = '_';
    for (i = 0; i < j; i++)
    {
           if (c_out[i] >= 'a' && c_out[i] <= 'z')
           {
               c_out[i] +='A'-'a';
           }
    }
    for (i = 0; i < j; i++)
    {
        for (k = i+1; k < j; k++)
        {
           if (c_out[i] == c_out[k])
           {
               c_out[k] = '*';
           }
        }
        //    *(strchr(c_out, c_out[i])) = '_';
    }
    for (i = 0; i < j; i++)
    {
        if ('*' != c_out[i])
            printf("%c", c_out[i]);
    }

    //printf ("%s  %s\n", c_dest, c_input);

    return 0;
}

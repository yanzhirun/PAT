#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int main()
{
    int i = 0, j = 0, length_wrong_key = 0, length_dest_key = 0, shift_err = 0, errnum = 0;
    char c_wrong_key[60];
    char c_dest[100000];
//    scanf ("%s",c_wrong_key);
    fgets(c_wrong_key, 60, stdin);
    scanf ("%s",c_dest);
    //fgets(c_dest, 100000, stdin);
    length_wrong_key = strlen(c_wrong_key);
    length_dest_key = strlen(c_dest);
    if (strchr(c_wrong_key, '+'))
    {
        shift_err = 1;
    }
    // printf("shift_err:%d\n",shift_err);
    for (i = 0; i < length_dest_key; i++)
    {
        if (shift_err == 1 && c_dest[i] >= 'A' && c_dest[i] <= 'Z')
        {
            goto next;
        }
        for (j = 0; j < length_wrong_key; j++)
        {
            if (c_dest[i] == c_wrong_key[j])
                goto next;
            else if ((c_dest[i] >= 'a' && c_dest[i] <= 'z' ) && c_dest[i] == c_wrong_key[j] - 'A' +'a')
            {
                goto next;
            }
        }
        errnum++;
        printf ("%c", c_dest[i]);
next:
        continue;
    }
    if (0 == errnum)
        printf("\n");
    //    printf("%s   %s\n", c_wrong_key, c_dest);

    //    printf ("_:%d  T:%d", '_', 'T');
    //    printf("A:%d Z:%d a:%d z:%d +:%d .:%d ,:%d -:%d",'A','Z','a','z','+','.', ',','-');

    return 0;
}

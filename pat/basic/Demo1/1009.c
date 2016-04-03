#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int change_str(char * input_str)
{
    int ret = 0;
    int length = 0;
    char * output_str;

    if (NULL == input_str)
    {
        printf("err!");
        ret = -1;
    }
    length = strlen(input_str);
//    printf("%d", length);
    *(input_str + length - 1) = '\0';
find:
    if (strrchr(input_str, ' ') != NULL)
    {
        output_str = strrchr(input_str, ' ');
        printf("%s ", output_str + 1);
        *output_str = '\0';
        goto find;
    }
    /*    do
          {
          output_str = strrchr(input_str, ' ');
          printf ("output_str:%s", output_str);
     *output_str = '\0';
     }while(NULL != output_str);
     */

    return ret;

}

int main()
{
    char input_str[84];
    //    gets(input_str);
    fgets(input_str, sizeof(input_str), stdin);
    //puts(input_str);
    //ungets(input_str);
    change_str(input_str);
    printf("%s", input_str);

    return 0;
}


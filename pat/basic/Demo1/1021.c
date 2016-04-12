#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int count (char *p_num, int *out)
{
    int ret = 1, i = 0, length = 0, tmp = 0;
    if (NULL == p_num || NULL == out)
    {
        ret = 0;
        printf ("count err\n");
        return ret;
    }

    length = strlen(p_num);
    //printf ("length%d",length);
    for (i = 0; i < length; i++)
    {
        tmp = p_num[i];
        switch (tmp)
        {
            case '0':
                out[0]++;
                break;
            case '1':
                out[1]++;
                break;
            case '2':
                out[2]++;
                break;
            case '3':
                out[3]++;
                break;
            case '4':
                out[4]++;
                break;
            case '5':
                out[5]++;
                break;
            case '6':
                out[6]++;
                break;
            case '7':
                out[7]++;
                break;
            case '8':
                out[8]++;
                break;
            case '9':
                out[9]++;
                break;
            default:
                break;
        }
    }
    for (i = 0; i <= 9; i++)
    {
        if (out[i] != 0)
        {
            printf("%d:%d\n", i, out[i]);
        }
    }

    return ret;
}
int main()
{
    int i = 0, length = 0;
    char p_num[1000];
    int out[10] = {0};
    scanf ("%s",p_num);
    count (p_num, out);
//    printf ("%s length: %d", p_num, length);

    return 0;
}

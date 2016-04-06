#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int Week_out (char chr)
{
    switch (chr){
        case 'A':
            printf("MON ");
            break;
        case 'B':
            printf("TUE ");
            break;
        case 'C':
            printf("WED ");
            break;
        case 'D':
            printf("THU ");
            break;
        case 'E':
            printf("FRI ");
            break;
        case 'F':
            printf("SAT ");
            break;
        case 'G':
            printf("SUN ");
            break;
        default:
            break;
    }

    return 0;
}
int F_data (char *s_one, char *s_two, char *s_three, char *s_four)
{
    int ret = 1, i, j = 0;
    char out[2];
    char day, hour, min;
    int length1 = 0, length2 = 0;

    if (NULL == s_one || NULL == s_two ||NULL == s_three || NULL == s_four)
    {
        ret = 0;
        return ret;
    }
    length1 = strlen(s_one) > strlen(s_two) ? strlen(s_two):strlen(s_one);
   // printf ("length1:%d", length1);
    length2 = strlen(s_three) > strlen(s_four) ? strlen(s_four):strlen(s_three);
   // printf ("length2:%d", length2);

    for (i = 0; i < length1; i++)
    {
        if (j > 1)
            break;
        if (s_one[i] == s_two[i] && (s_one[i] <= 'G' && s_one[i] >= 'A') && j == 0)
        {
            out[j] =s_one[i];
            j++;
            continue;
        }
        if (s_one[i] == s_two[i] && ((s_one[i] <= 'N' && s_one[i] >= 'A') ||(s_one[i] >= '0' && s_one[i] <= '9')) && j == 1)
        {
            out[j] = s_one[i];
            //    printf("i:%d j:%d ", i, j);
            j++;
            break;
        }
        //printf("s_one:%c", s_one[i]);
    }

    //printf ("%c  %c \n\n\n", out[0], out[1]);
    for (i = 0; i < length2; i++)
    {
        if ((s_three[i] == s_four[i])&&((s_three[i] >= 'a' && s_three[i] <= 'z') || (s_three[i] >= 'A' && s_three[i] <= 'Z')))
        //if (s_three[i] == s_four[i] && s_three[i] == 's')
        {
            min = i;
            break;
            //printf ("min:%d", min);
        }
    }
    Week_out(out[0]);
    if ('0' <= out[1] && '9' >= out[1])
        printf("0%c:", out[1]);
    else if ('A' <= out[1] && 'N' >= out[1])
    {
         printf("%d:", (int)out[1] - 'A' + 10 );
    }
    if (min < 10)
    {
        printf("0");
    }
    printf("%d", min);

    return ret;
}

int main()
{

    char s_one[60] = {0};
    char s_two[60] = {0};
    char s_three[60] = {0};
    char s_four[60] = {0};

    scanf("%s", s_one);
    scanf("%s", s_two);
    scanf("%s", s_three);
    scanf("%s", s_four);

//    printf("A:%d",'A');

    F_data(s_one, s_two, s_three, s_four);

    return 0;
}

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int* perl_count(char *perl, int* output, int length)
{
//    static int perl_count[62] = {0};
    int i;
    for (i = 0; i < length; i++)
    {
        if (perl[i] >= '0' && perl[i] <= '9')
        {
            output[perl[i]-'0']++;
        }
        else if (perl[i] >= 'a' && perl[i] <= 'z')
        {
            output[perl[i]-'a'+10]++;
        }
        else if (perl[i] >= 'A' && perl[i] <= 'Z')
        {
            output[perl[i]-'A'+36]++;
        }
    }

    return output;
}

int perl_judge(int* perl_sale, int* perl_want)
{
    int i, j, over_perl = 0, need_perl = 0;

    for (i = 0; i < 62; i++)
    {
        if (perl_sale[i] < perl_want[i])
        {
            need_perl += perl_want[i] - perl_sale[i];
            continue;
        }
        if (need_perl && perl_sale[i] < perl_want[i])
        {
            continue;
        }
        if (need_perl== 0 && perl_sale[i] > perl_want[i])
        {
             over_perl += perl_sale[i] - perl_want[i];
        }
    }
    if (need_perl)
    {
        printf("No %d", need_perl);
        return 0;
    }
    else if (need_perl == 0)
    {
        printf("Yes %d", over_perl);
        return 0;
    }
}

int main()
{
    char sale[1000], want[1000];
//    int perl_sale[62], perl_want[62];
    int* perl_sale = NULL;
    int* perl_want = NULL;
    int length_sale, length_want;
    int i, j, k;

    int arr_perl_sale[62] = {0};
    int arr_perl_want[62] = {0};
    perl_want = arr_perl_want;
    perl_sale = arr_perl_sale;
    scanf ("%s", sale);
    scanf ("%s", want);
    length_sale = strlen (sale);
    length_want = strlen (want);
    //perl_sale = perl_count(sale, perl_sale, length_sale);
    //perl_want = perl_count(want, perl_want, length_want);
    perl_count(sale, perl_sale, length_sale);
    perl_count(want, perl_want, length_want);
    //    for (i = 0; i < length_want; i++ )
    perl_judge(perl_sale, perl_want);
//    printf("\n\n----\n"); for (i = 0; i < 62; i++ ) printf("%d", *(perl_sale+i)); printf("\n\n----\n"); for (i = 0; i < 62; i++ ) printf("%d", *(perl_want+i));

    return 0;
}

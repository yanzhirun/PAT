#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "math.h"

/*
int test_PAT (int num, char pat[10][101])
{
    int ret = 0;
    int i, j;
    int preA = 0, midA = 0, lastA = 0;

    for (i = 0; i < num; i++)
    {
        int errA = 0, errT = 0;
        int length = strlen (pat[i]);
//        printf("length of arr:%d\n",length);
//        printf("the %d line\n-----------\n",i);
//        printf("pat i %s",pat[i]);
        if (strcmp(pat[i],"PAT") == 0)
        {
            printf("YES\n");
            continue;
        }
        for (j = 0 ; j < length; j++)
        {
            if ('A' != pat[i][j] &&'P' != pat[i][j] && 'T' != pat[i][j] )
            {
                printf("NO\n");
                break;
            }
             if ('P' == pat[i][j])
             {
                preA = j + 1;
  //              printf("preAnumber:%d\n", preA);
                errA++;
  //              printf("errA:%d\n", errA);
                if(errA > 1)
                {
                    printf("P NO\n");
                    break;
                }
                //break;
              //  continue;
             }
             if ('T' == pat[i][j])
             {
                 errT++;
                 midA = j + 1;
                if(errT > 1)
                {
                     printf("T NO\n");
                     break;
                }
                continue;
                // break;
             }
             printf("midA:%d     preA:%d\n", midA, preA);
             //if('P' != pat[i][0] && ((length - midA ) != 2*preA) && midA != 0 && (midA - preA - 1)  1)
             if (midA != 0)
             {
             if (((length - midA) != 2*preA) || (midA-preA-1) <1 || (length - midA) != (midA -preA -1 )*(preA -1))
             {
                 printf("midA:%d     preA:%d\n", midA, preA);
                 printf("pptt NO\n");
                 break;
             }
             else if ('A' != pat[i][j] && 'P' != pat[i][j] && 'T' != pat[i][j])
             {
                  printf("other NO");
                  break;
             }
             else
             {
                 printf("YES\n");
                 break;
             }
        }
    }
    }
        return 0;
}
*/

int testtest(int num, char pat[10][101])
{
    int i,j,out;
    char *ptr;
    int preA = 0, midA = 0, lastA = 0;
    int length = 0;

    for (i = 0; i < num; i++)
    {
        out = 0;
        length = strlen (pat[i]);
        //printf("length:%d", length);
        if(NULL ==  strchr(pat[i], 'P') || NULL == strchr(pat[i], 'T'))
        {
            printf("NO\n");
            continue;
        }
        if (length < 3 || NULL != strchr(strchr(pat[i], 'P')+1, 'P') || NULL != strrchr(strchr(pat[i], 'T')+1, 'T'))
        {
            printf("NO\n");
            continue;
        }
        preA = fabs(pat[i] - strchr(pat[i], 'P'));
        midA = fabs(pat[i] - strrchr(pat[i], 'T')) - preA -1;
        //printf("preA:%d  ,midA:%d  ", preA, midA);
        for (j = 0; j < length; j++)
        {
            if ('A' != pat[i][j] &&'P' != pat[i][j] && 'T' != pat[i][j] )
            {
                printf("NO\n");
                out = 1;
                break;
                //continue;
            }
        }
        if(out)
            continue;
        lastA = length - midA - preA -2;
        //printf("lastA:%d\n", lastA);
        if(lastA == midA * preA)
        {
             printf("YES\n");
             continue;
        }
        else
        {
            printf("NO\n");
            continue;
        }
    }
}

int main()
{
	int num, i;
	char test[10][101] = {0};
	scanf("%d",&num);
	for (i = 0; i < num; i++)
	{
		scanf("%s",test[i]);
	}
//	test_PAT(num, test);

    testtest(num, test);
	return 0;
}



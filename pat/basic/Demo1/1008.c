#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int * creat_arr(int n)
{
    int* arr = (int *)malloc(n*sizeof(int));
    if (NULL == arr)
    {
        printf("malloc err!\n");
        return NULL;
    }
    return arr;
}

int main()
{
    int n, m, i;
    int *arr = NULL;
    scanf("%d %d", &n, &m);
    //printf("%d  %d", n, m);
    arr = creat_arr(n);
    if (NULL ==arr)
    {
        printf ("arr created err!\n");
        return 0;
    }
    //printf("size:%d", sizeof(arr));
    //printf("before m:%d",m);
    //m=n-m%n;
    if (m > n)
    {
        int i = 1;
        do
        {
            m = m - n*i;
            i++;
        }while(m > n);
    }
    //printf("after m%d",m);
    for (i = 0; i < n; i++)
    {
        scanf("%d",arr+i);
    }
    for (i = n-m; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    for (i = 0; i < n-m-1; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("%d",arr[n-m-1]);

    return 0;
}

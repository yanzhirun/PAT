#include <stdio.h>

int main()
{
    int a[100], i, j;
    int tmp, n;
    scanf("%d", &n);
    for (i=0; i<n; ++i)
    {
        scanf("%d", &a[i]);
        printf("a[%d] = %d\n", i, a[i]);
    }

    for(i=0;i<n;++i)
    {
        for(j=0;j<n-i;++j)
        {
            if(a[j]<a[j+1])
            {
                tmp = a[j+1];
                a[j+1] = a[j];
                a[j] = tmp;
            }
        }
    }

    for(i=0;i<n;++i)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

#include <stdio.h>

int a[100], n;

void quicksort(int left, int right)
{
    int i, j, t, temp;
    if (left>right)
        return;

    temp = a[left];
    i = left;
    j = right;

    while(i!=j)
    {
        while(a[j]>=temp && i<j)
            --j;
        while(a[i]<=temp && i<j)
            ++i;

        if(i<j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = temp;

    quicksort(left, i-1);
    quicksort(i+1, right);
}

int main()
{
    int i, j, t;
    scanf("%d", &n);
    for(i = 0; i<n;++i)
        scanf("%d", &a[i]);

    quicksort(0, n - 1);

    for(i=0;i<n;++i)
        printf("%d ", a[i]);

    return 0;
}



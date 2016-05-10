#include "stdlib.h"
#include "stdio.h"

int min_num (int x, int y)
{
    return x < y ? x : y;
}
int merge_sort_test (int* input, int* sort_first, int N)
{
    int ret = 0, i, j, k, cmp_same = 0;
    int* a = input;
    int* b = (int*)malloc(N * sizeof(int));
    int seg, start, low, mid, high, start1, end1, start2, end2;
    if (NULL == input || NULL == sort_first)
    {
        ret = 1;
        return ret;
    }

    for (seg = 1; seg < N; seg += seg)
    {
        for (start = 0; start < N; start += seg + seg)
        {
            low = start;
            mid = min_num (start + seg, N);
            high = min_num (start + seg + seg, N);
            k = low;
            start1 = low;
            end1 = mid;
            start2 = mid;
            end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while(start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
        if (cmp_same == 1)
        {
            printf("Merge Sort\n");
            for (i = 0; i < N-1; i++)
            {
                printf("%d ", a[i]);
            }
            printf("%d", a[N-1]);
            break;
        }
        for (k = 0; k < N; k++)
        {
            cmp_same = 1;
            if (a[k] != sort_first[k])
            {
                cmp_same = 0;
                break;
            }
        }
    }
    if (NULL != b)
    {
        //free(b);
        b = NULL;
    }

    return ret;
}

int insert_sort_test (int* input, int* sort_first, int N)
{
    int ret = 0, i, j, k, tmp, cmp_same = 0, next_num = 0;
    int insert[101];
    if (NULL == input || NULL == sort_first)
    {
        ret = 1;
        return ret;
    }
    for (i = 0; i < N; i++)
    {
        insert[i] = input[i];
    }

    for (i = 1; i < N; i++)
    {
        tmp = insert[i];
        next_num = 0;
        for (j = i-1; j >= 0 && tmp < insert[j]; j--)
        {
            next_num = 1;
            insert[j+1] = insert[j];
        }
        insert[j+1]= tmp;
        if (cmp_same && next_num)
        {
            printf("Insertion Sort\n");
            for (i = 0; i < N-1; i++)
            {
                printf("%d ", insert[i]);
            }
            printf("%d", insert[N-1]);
        }
        for (k = 0; k < N; k++)
        {
            cmp_same = 1;
            if (insert[k] != sort_first[k])
            {
                cmp_same = 0;
                break;
            }
        }
    }

    return 0;
}
int main()
{
    int N, i;
    int input[101], sort_first[101];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", input+i);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", sort_first+i);
    }
    insert_sort_test (input, sort_first, N);
    merge_sort_test (input, sort_first, N);
    return 0;
}

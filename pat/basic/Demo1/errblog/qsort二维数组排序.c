/* 二维数组排序调用 qsort
 * return a > b ? 1;-1;
 * 如果a > b 返回1 按照降序排列，
 * qsort() 最后一个参数cmp可任意取名 ，返回1 表示交换 0 相等
 * cmp()的参数const * 内部强制转换，注意 一维二维
 * 多维数组可以用结构体类型
 */
int cmp(const void *p, const void *q)
{
    int **left = (int **)p;
    int **right = (int **)q;

    if ((*left)[3] ==(*right)[3])
    {
        if ((*left)[1] == (*right)[1])
        {
            return  ((*left)[0] > (*right)[0])? 1:-1;
        }
        else return ((*left)[1] > (*right)[1])? -1:1;
    }
    else return ((*left)[3] > (*right)[3])?-1:1;
}

int sort_socre(int **sort_arr, int ac_num)
{
    int i = 0;
    qsort(sort_arr, ac_num, sizeof(*sort_arr), cmp);
    for (i = 0; i < ac_num; i++)
    {
        printf("%d %d %d %d\n", sort_arr[i][0], sort_arr[i][1], sort_arr[i][2], sort_arr[i][3]);
    }
    printf ("ac_num%d", ac_num);
    return 0;
}

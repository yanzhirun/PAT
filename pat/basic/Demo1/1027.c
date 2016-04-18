#include "stdlib.h"
#include "stdio.h"

int find_max (int N)
{
    int i = 1, sum = 1;
    while (sum <= N)
    {
        i += 2;
        sum += i*2;
    }
    i -= 2;
 //   printf ("%d %d\n", i-2 ,sum-2*i);

    return i;
}
int print_oneline (int star, int line, char ch)
{
    int i = 0;
    for (i = 0; i < line; i++)
    {
         printf (" ");
    }
    for (i = 0; i < star; i++)
    {
        printf ("%c", ch);
    }
    printf ("\n");
    return 0;
}

int print_ch (N, ch)
{

    int i = 0, j = 0, line = 0, star = 0, left = 0;
    i = find_max(N);
    if (i == 1)
    {
        printf("%c\n%d", ch, N-1);
        return 0;
    }
    for (line = 0; line < (i+1)/2; line++)
    {
        star = i-2*line;
        print_oneline(star, line, ch);
    }
    for (line = (i-1)/2-1; line >= 0; line--)
    {
        star = i-2*line;
        print_oneline(star, line, ch);
    }

    for (j = i; j >1; j--,j--)
    {
         left += j*2;

    }
    printf("%d", N-1-left);
    return 0;
}
int main()
{
    int N;
    char ch;
    scanf ("%d", &N);
    getchar();
    scanf ("%c", &ch);
    //printf ("%d %c", N, ch);

    print_ch (N, ch);

    return 0;
}

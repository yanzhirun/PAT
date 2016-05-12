#include "stdlib.h"
#include "stdio.h"

int main()
{
    int P1, P2, P3, A1, A2, A3;
    int ans1 = 0, ans2 = 0, ans3 = 0, tmp;
    scanf("%d.%d.%d", &P1, &P2, &P3);
    scanf("%d.%d.%d", &A1, &A2, &A3);
    if (A1*17*29 + A2*29 + A3 < P1*17*29 + P2*29 + P3)
    {
        tmp = A1;
        A1 = P1;
        P1 = tmp;
        tmp = A2;
        A2 = P2;
        P2 = tmp;
        tmp = A3;
        A3 = P3;
        P3 = tmp;
        printf ("-");
    }

    if (A3 < P3)
    {
        A2 -= 1;
        ans3 = 29;
    }
    ans3 += A3 - P3;
    if (A2 < P2)
    {
        A1 -= 1;
        ans2 = 17;
    }
    ans2 += A2 - P2;
    ans1 = A1 - P1;
    printf ("%d.%d.%d", ans1, ans2, ans3);

    return 0;
}

#include "stdlib.h"
#include "stdio.h"
#include "math.h"

typedef struct {
    int negitive;
    int k;
    int a;
    int b;
}Num_special;

Num_special reduce (Num_special num)
{
    Num_special calc_num;
    int a, b;
    int i = 2;
    a = num.a;
    b = num.b;
    calc_num.negitive = 1;
    calc_num.k = 0;
    if (num.a < 0)
    {
        a = abs(num.a);
        calc_num.negitive = -1;
    }
    do {
        while (a%i == 0 && b%i == 0)
        {
            a = a/i;
            b = b/i;
        }
        i++;
    }while (i < (a>b?b:a));
    //reduction of fraction end

    if (a > b)
    {
        calc_num.k = a/b;
        a = a - calc_num.k*b;
        if (a%b == 0)
            b = 1;
        //printf ("%d ", k);
    }
    calc_num.a = a;
    calc_num.b = b;
//    if (negitive) printf(")");
    return calc_num;
}
int print_num(Num_special num)
{
    if (num.negitive == -1)
        printf("(-");
    if (num.a != 0)
    {
        if (num.k != 0)
            printf("%d ",num.k);
        printf ("%d/%d", num.a, num.b);
    }
    else{
        printf ("%d", num.k);
    }
    if (num.negitive == -1)
        printf(")");

    return 0;
}

Num_special calculate (Num_special num1, Num_special num2)
{
    Num_special result;
    num1 = reduce (num1);
    print_num(num1);
    printf (" + ");
    num2 = reduce (num2);
    print_num(num2);

    result.k = num1.negitive * num1.k + num2.negitive * num2.k;
    result.b = num1.b * num2.b;
    result.a = num1.negitive * num1.a * num2.b + num2.negitive * num2.a * num1.b + result.k * result.b;
    result = reduce (result);

    printf (" = ");
    print_num(result);
    printf("\n");
    //subtraction
    print_num(num1);
    printf (" - ");
    print_num(num2);
    //printf("====\n num2.k%d  num2.a %d  num2.b%d",num2.k,num2.a,num2.b);
    result.k = num1.negitive * num1.k - num2.negitive * num2.k;
    result.b = num1.b * num2.b;
    result.a = num1.negitive * num1.a * num2.b - num2.negitive * num2.a * num1.b + result.k * result.b;
    result = reduce (result);
    printf (" = ");
    print_num(result);
    printf("\n");

    print_num(num1);
    printf (" * ");
    print_num(num2);
    result.a = (num1.negitive * num2.negitive) * ( num1.k * num1.b + num1.a) * (num2.k * num2.b + num2.a);
    result.b = num1.b * num2.b;
    result = reduce (result);
    printf (" = ");
    print_num(result);
    printf("\n");

    print_num(num1);
    printf (" / ");
    print_num(num2);
    printf (" = ");
    if (num2.k == 0 && num2.a == 0)
        printf ("Inf");
    else {
        result.a = (num1.negitive * num2.negitive) * ( num1.k * num1.b + num1.a) * num2.b;
        result.b = num1.b * (num2.k * num2.b + num2.a);
        result = reduce (result);
        print_num(result);
    }

}

int main()
{
    Num_special num1, num2, result;
    scanf ("%d/%d %d/%d", &num1.a, &num1.b, &num2.a, &num2.b);
    num1.k = 0;
    num2.k = 0;

    calculate (num1, num2);
    //printf ("%d %d %d %d", num1.a, num1.b, num2.a, num2.b);

    return 0;
}

#include "stdlib.h"
#include "stdio.h"

typedef struct {
    long long int negitive;
    long long int k;
    long long int a;
    long long int b;
}Num_special;

Num_special reduce (Num_special num)
{
    long long int a, b, r;
    Num_special calc_num;
    calc_num.negitive = 1;
    calc_num.k = 0;
    if (num.a == 0 && num.k == 0)
    {
        calc_num.k = 0;
        calc_num.a = 0;
        calc_num.b = 0;
        return calc_num;
    }
    if (num.a < 0)
    {
        num.a *= -1;
        calc_num.negitive = -1;
    }
    a = num.a > num.b ?num.a:num.b;
    b = num.a < num.b ?num.a:num.b;
    r = b;
    while (r != 0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    if ((calc_num.a = num.a/a) > (calc_num.b = num.b/a))
    {
        calc_num.k = calc_num.a/calc_num.b;
        calc_num.a = calc_num.a - calc_num.k*calc_num.b;
        if (calc_num.a == 0)
            calc_num.b = 1;
        //printf ("%lld ", k);
    }
    return calc_num;
}

int print_num(Num_special num)
{
    if (num.negitive == -1)
        printf("(-");
    if (num.a != 0)
    {
        if (num.k != 0)
            printf("%lld ",num.k);
        if (num.b != 1)
            printf ("%lld/%lld", num.a, num.b);
        else
            printf ("%lld", num.a);
    }
    else{
        printf ("%lld", num.k);
    }
    if (num.negitive == -1)
        printf(")");

    return 0;
}

void calculate (Num_special num_left, Num_special num_right)
{
    Num_special result, num1, num2;
    num1 = reduce (num_left);
    num2 = reduce (num_right);

    print_num(num1);
    printf (" + ");
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
    //printf("====\n num2.k%lld  num2.a %lld  num2.b%lld",num2.k,num2.a,num2.b);
    result.a = num_left.a*num_right.b - num_right.a*num_left.b;
    result.b = num_left.b*num_right.b;
    //if (result.a < 0) { result.negitive = -1; result.a = abs(result.a); }
    result = reduce (result);
    printf (" = ");
    print_num(result);
    printf("\n");

    //num_left.a = num1.negitive*num1.k*num1.b + num1.a; num_right.a = num2.negitive*num2.k*num2.b + num2.a; num_left.b = num1.b; num_right.b = num2.b;

    print_num(num1);
    printf (" * ");
    print_num(num2);
    result.a = num_left.a * num_right.a;
    result.b = num_left.b * num_right.b;
    result = reduce (result);
    printf (" = ");
    print_num(result);
    printf("\n");

    print_num(num1);
    printf (" / ");
    print_num(num2);
    printf (" = ");
    result.a = num_left.a*num_right.b;
    result.b = num_right.a*num_left.b;
    if (result.b == 0)
        printf ("Inf");
    else
    {
        if (result.b < 0)
        {
            result.a *= -1;
            result.b *= -1;
        }
        result = reduce (result);
        print_num(result);
    }

    return;
}

int main()
{
    Num_special num1, num2;
    scanf ("%lld/%lld %lld/%lld", &num1.a, &num1.b, &num2.a, &num2.b);

    calculate (num1, num2);
    //printf ("%lld %lld %lld %lld", num1.a, num1.b, num2.a, num2.b);

    return 0;
}

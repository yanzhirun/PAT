#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define CLK_TCK 100

int main ()
{
    float start, end;
    double time;
    int h,m,s;
    scanf ("%f%f", &start, &end);
//    sleep(20);
//    start = clock();
//    end = clock();
//    end = 4577973;
//    printf("%f",CLK_TCK);
    //printf("time : %f \n", (double)(end - start)/CLOCKS_PER_SEC);
    time = (double)(end - start)/CLK_TCK;
//    printf("time : %f \n", time);
    h = time/60/60;
    m = (time - h*60*60)/60;
    s =(int) (time -h*60*60-m*60+0.5);
    printf("%02d:%02d:%02d", h, m, s);

    return 0;
}

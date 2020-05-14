#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double p,s,a,b,c;
    printf("请输入三角形的三边a,b,c:\n");
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a<=0||b<=0||c<=0)
    {
        printf("Please input right number!");
    }
    else if(a+b<=c||b+c<=a||a+c<=b)
        printf("这不是三角形");
    else
    {
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("这是一个三角形，面积是 %lf",s);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double p,s,a,b,c;
    printf("�����������ε�����a,b,c:\n");
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a<=0||b<=0||c<=0)
    {
        printf("Please input right number!");
    }
    else if(a+b<=c||b+c<=a||a+c<=b)
        printf("�ⲻ��������");
    else
    {
        p=(a+b+c)/2;
        s=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("����һ�������Σ������ %lf",s);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
int main()
{
    const double pi=3.14159;
    float r;
    double s,v;
    printf("输入球的半径r：\n");
    scanf("%f",&r);
    s=4*PI*r*r;
    v=pi*r*r*r*3/4;
    printf("球的面积s是 %f, 球的体积v是 %lf",s,v);
    return 0;
}

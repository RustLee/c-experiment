#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159
int main()
{
    const double pi=3.14159;
    float r;
    double s,v;
    printf("������İ뾶r��\n");
    scanf("%f",&r);
    s=4*PI*r*r;
    v=pi*r*r*r*3/4;
    printf("������s�� %f, ������v�� %lf",s,v);
    return 0;
}

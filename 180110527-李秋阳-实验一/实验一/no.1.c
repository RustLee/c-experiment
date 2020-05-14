#include<stdio.h>

int main()
{
    char a;
    short b;
    int c;
    short int d;
    float e;
    double f;
    printf("please input char a:");
    scanf("%d",&a);
    printf("char a=%d,size of char is %d\n",a,sizeof(char));

    printf("please input short b:");
    scanf("%d",&b);
    printf("short b=%d,size of short is %d\n",b,sizeof(short));

    printf("please input int c:");
    scanf("%d",&c);
    printf("int c=%d,size of int is %d\n",c,sizeof(int));

    printf("please input short d:");
    scanf("%d",&d);
    printf("short int d=%d,size of short int is %d\n",d,sizeof(short int));

    printf("please input float e:");
    scanf("%f",&e);
    printf("float e=%f,size of float is %d\n",e,sizeof(float));

    printf("please input double:");
    scanf("%lf",&f);
    printf("double f=%f,size of double is %d\n",f,sizeof(double));

    return 0;

}

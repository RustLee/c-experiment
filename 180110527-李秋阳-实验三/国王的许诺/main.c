#include <stdio.h>
#include <stdlib.h>
#define M 1.42e8
int main()
{
    printf("Number:180110527\nsubject No.2\n\n\n");
    int n;
    double q=1,sum=1;
    for(int i=1;i<64;i++)
    {
        q=2*q;
        sum=sum+q;
    }
    printf("颗粒数是%.3f\n",sum);
    printf("体积是%.3f立方米",sum/M);
    return 0;
}

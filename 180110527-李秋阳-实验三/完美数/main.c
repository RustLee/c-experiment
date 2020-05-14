#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t=0,n;
    printf("Number:180110527\nsubject No.1 Program No.2\n\n\n");
    printf("Please input a integer\n");
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        if(n%i==0){
        t=t+i;
    }
    }
    if(t==n){
        printf("这是一个完美数");
    }
    else{
        printf("这不是一个完美数");
    }
    return 0;
}

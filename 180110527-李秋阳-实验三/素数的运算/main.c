#include<stdio.h>
int main()
{
    printf("Number:180110527\nsubject No.1 Program No.1\n\n\n");
    int a=0,n;
    printf("请输入一个大于1的数\n");
    scanf("%d",&n);
    if(n<=1)
    printf("请输入一个大于1的数!");
    else
    {
    for(int i=2;i<n;i++)
    {
    while(a<n&&n%i==0){
        a++;
    }
    if(a==0){
        printf("It's a prime number.");
        break;
    }
    else{
        printf("%d=",n);
        int t=n;
        for(int j=2;j<t;j++)
        {
            if(n%j==0){
            if(n==j)
                printf("%d",j);
            else
                printf("%d*",j);
            n=n/j--;
            }
        }
    }
    }
    }
    return 0;
}

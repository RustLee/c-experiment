#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a;
    printf("please input a lowercase:");
    scanf("%c",&a);
    if(a>='a'&&a<='z')
        a=a-32;
    for(int i=0;i<=4;i++)
    {
            printf("%c %c %c %c %c %c %c %c\n %c %c %c %c %c %c %c %c\n",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    }
    return 0;
}

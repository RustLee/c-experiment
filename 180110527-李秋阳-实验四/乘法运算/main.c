#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    printf("Number:180110527\nsubject:No.1\n\n\n");
    int n1,n2,counter1,counter2,counter3,r;
    srand(time(NULL));
    counter3=0;
    counter1=0;
    do{
        counter2=0;
        n1=rand()%10+1;
        n2=rand()%10+1;
        printf("请计算%d * %d=",n1,n2);
        scanf("%d",&r);
        do{
        counter2++;
        if(r!=n1*n2&&counter2<=2)
            {
            printf("Wrong! Please try again.\n");
            scanf("%d",&r);
            }
        else if(r!=n1*n2&&counter2==3)
        {
            printf("Wrong！Test next subject!\n");
            break;
        }
        else if(r==n1*n2){
            printf("right!\n");
            counter1++;
            break;
        }
    }while(counter2<=3);
    counter3++;
    }while(counter3<10);
    printf("正确率为%.2f%%",(float)counter1*10);
    return 0;
}

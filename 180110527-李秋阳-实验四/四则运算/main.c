#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Calculate(int x,char op,int y);
int CRN();
char CRO();
void PrintR();
void PrintW();
int main()
{
    printf("Number:180110527\nsubject:No.2\n\n\n");
    int a,b,userAnswer,i,rightNumber=0,flag=0;
    char opChar;
    srand(time(NULL));
    do{
        for(i=0;i<10;i++)
        {
            a=CRN();
            b=CRN();
            opChar=CRO();
            printf("%d%c%d=?\n",a,opChar,b);
            scanf("%d",&userAnswer);
            if(userAnswer==Calculate(a,opChar,b))
            {
                PrintR();
                rightNumber++;
            }
            else
            {
                PrintW();
            }
        }
        printf("Total score is %d\n",rightNumber*10);
        printf("Rate of correctness is %d%%\n",rightNumber*10);
        if(rightNumber*10<75)
        {
            printf("Once Again!\n");
            rightNumber=0;
            flag=1;
        }
    }while(flag);
    return 0;
}
int Calculate(int x,char op,int y)
{
    switch(op)
    {
    case '+': return x+y;
    case '-': return x-y;
    case '*': return x*y;
    case '/': return x/y;
    default:printf("Operator error!\n");return 0;
    }
}
int CRN()
{
    return rand()%10+1;
}
char CRO()
{
    int op;
    op=rand()%4+1;
    switch(op)
    {
    case 1:return '+';
    case 2:return '-';
    case 3:return '*';
    case 4:return '/';
    }
    return 0;
}
void PrintR()
{
    int i;
    i=rand()%4+1;
    switch(i)
    {
        case 1:printf("Very good!\n");
               break;
        case 2:printf("Excellent!\n");
               break;
        case 3:printf("Nice work!\n");
               break;
        case 4:printf("Keep up the good work!\n");
               break;
        default:printf("Wrong type!");
    }
}
void PrintW()
{
    int i;
    i=rand()%4+1;
    switch(i)
    {
        case 1:printf("No.Please try again.\n");
               break;
        case 2:printf("Wrong. Be careful.\n");
               break;
        case 3:printf("Don't give up!\n");
               break;
        case 4:printf("Not correct.Keep trying.\n");
               break;
        default:printf("Wrong type!");
    }
}

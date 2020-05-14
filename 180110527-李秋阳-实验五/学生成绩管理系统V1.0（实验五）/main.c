#include <stdio.h>
#include <stdlib.h>
#define N 30
int Inputrecord(long number[],int score[]);
void Calculate(long number[],int score[],int sum,float aver,int x);
void SortscoreD(long number[],int score[],int x);
void SortscoreA(long number[],int score[],int x);
void Sortnumber(long number[],int score[],int x);
int Searchnumber(long number[],int score[],long m,int x);
void Analysis(long number[],int score[],int x);
void Listrecord(long number[],int score[],int sum,float aver,int x);
int main()
{
    printf("Number:180110527\nSubject:No.1\n\n\n");
    int x,n,sum=0,ret;
    long m;
    float aver;
    int score[N];
    long number[N];
    do{
        printf("1.Input record\n2.Calculate total and average score of course\n3.Sort in descending order by score\n");
        printf("4.Sort in ascending order by score\n5.Sort in ascending order by number\n6.Search by number\n");
        printf("7.Statistic analysis\n8.List record\n0.Exit\nPlease enter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                x=Inputrecord(number,score);
                break;
            }
        case 2:
            {
                Calculate(number,score,sum,aver,x);
                break;
            }
        case 3:
            {
                SortscoreD(number,score,x);
                break;
            }
        case 4:
            {
                SortscoreA(number,score,x);
                break;
            }
        case 5:
            {
                Sortnumber(number,score,x);
                break;
            }
        case 6:
            {
                ret=Searchnumber(number,score,m,x);
                if(ret!=-1)
                    printf("score=%d\n\n",score[ret]);
                else
                    printf("Not found!\n\n");
                break;
            }
        case 7:
            {
                Analysis(number,score,x);
                break;
            }
        case 8:
            {
                Listrecord(number,score,sum,aver,x);
                break;
            }
        case 0:
            break;
        }
    }while(n>0&&n<=8);
    return 0;
}
int Inputrecord(long number[],int score[])    /*键盘输入学生学号与成绩*/
{
    int i=-1;
    do{
        i++;
        printf("Please input number and score:\n");
        scanf("%ld%d",&number[i],&score[i]);
    }while(number[i]>0);
    return i;
}
void Calculate(long number[],int score[],int sum,float aver,int x)    /*计算课程总分与平均分*/
{
    for(int i=0;i<x;i++)
    {
        sum+=score[i];
    }
    aver=(float)sum/x;
    printf("The sum is %d.\nThe aver is %f.\n\n",sum,aver);
}
void SortscoreD(long number[],int score[],int x)    /*按成绩由高到低输出成绩表*/
{
    int i,j,k,temp1;
    long temp2;
    for(i=0;i<x-1;i++)
    {
        k=i;
        for(j=i+1;j<x;j++)
        {
            if(score[j]>score[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=score[k];score[k]=score[i];score[i]=temp1;
            temp2=number[k];number[k]=number[i];number[i]=temp2;
        }
    }
    for(int p=0;p<x;p++)
    {
        printf("%10ld%4d\n",number[p],score[p]);
    }
    printf("\n");
}
void SortscoreA(long number[],int score[],int x)    /*按成绩由低到高输出成绩表*/
{
    int i,j,k,temp1;
    long temp2;
    for(i=0;i<x-1;i++)
    {
        k=i;
        for(j=i+1;j<x;j++)
        {
            if(score[j]>score[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=score[k];score[k]=score[i];score[i]=temp1;
            temp2=number[k];number[k]=number[i];number[i]=temp2;
        }
    }
    for(int p=x-1;p>=0;p--)
    {
        printf("%10ld%4d\n",number[p],score[p]);
    }
    printf("\n");
}
void Sortnumber(long number[],int score[],int x)    /*按学号由低到高输出成绩表*/
{
    int i,j,k,temp1;
    long temp2;
    for(i=0;i<x-1;i++)
    {
        k=i;
        for(j=i+1;j<x;j++)
        {
            if(number[j]>number[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=score[k];score[k]=score[i];score[i]=temp1;
            temp2=number[k];number[k]=number[i];number[i]=temp2;
        }
    }
    for(int p=x-1;p>=0;p--)
    {
        printf("%10ld%4d\n",number[p],score[p]);
    }
    printf("\n");
}
int Searchnumber(long number[],int score[],long m,int x)    /*按学号查找成绩*/
{
    printf("Please input the number for researching:\n");
    scanf("%ld",&m);
    int i;
    for(i=0;i<x;i++)
    {
        if(number[i]==m)
            return i;
    }
    return -1;
}
void Analysis(long number[],int score[],int x)  /*统计各层次学生百分比*/
{
    int count1=0,count2=0,count3=0,count4=0,count5=0;
    for(int i=0;i<x;i++)
    {
        if(score[i]>=90&&score[i]<=100)
        {
            count1++;
        }
        else if(score[i]>=80&&score[i]<=89)
        {
            count2++;
        }
        else if(score[i]>=70&&score[i]<=79)
        {
            count3++;
        }
        else if(score[i]>=60&&score[i]<=69)
        {
            count4++;
        }
        else
            count5++;
    }
    printf("优秀占%.2f%%\n,良好占%.2f%%\n,中等占%.2f%%\n,及格占%.2f%%\n,不及格占%.2f%%\n\n",(float)count1/x*100,(float)count2/x*100,(float)count3/x*100,(float)count4/x*100,(float)count5/x*100);
}
void Listrecord(long number[],int score[],int sum,float aver,int x)    /*输出成绩表与课程总分、平均分*/
{
    for(int p=0;p<x;p++)
    {
        printf("%10ld%4d\n",number[p],score[p]);
    }
    for(int i=0;i<x;i++)
    {
        sum+=score[i];
    }
    aver=(float)sum/x;
    printf("课程总分为%d,平均分为%f.\n",sum,aver);
}

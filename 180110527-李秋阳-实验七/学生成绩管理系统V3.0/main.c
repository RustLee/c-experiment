#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
int Inputrecord(long number[],char name[][10],int score[][6],int x,int cl);
void Calculate_cl(int score[][6],int sum_cl[],float aver_cl[],int x,int cl);
void Calculate_stu(int score[][6],int sum_stu[],float aver_stu[],int x,int cl);
void SortscoreD(long number[],char name[][10],int score[][6],int x,int cl,int sum_stu[]);
void SortscoreA(long number[],int sum_stu[],char name[][10],int score[][6],int x,int cl);
void Sortnumber(long number[],int sum_stu[],char name[][10],int score[][6],int x,int cl);
void Sortname(long number[],int sum_stu[],char name[][10],int score[][6],int x,int cl);
int Searchnumber(long number[],int score[][6],long m,int x);
int Searchname(long number[],int score[][6],char name[][10],int x);
void Analysis(long number[],int score[][6],int x,int cl);
void Listrecord(long number[],char name[][10],int score[][6],int sum_cl[],float aver_cl[],int sum_stu[],float aver_stu[],int x,int cl);
int main()
{
    printf("Number:180110527\nSubject:No.1\n\n\n");
    int x,n,sum,ret,cl;
    long m;
    float aver_cl[6],aver_stu[30];
    int score[N][6],sum_cl[6],sum_stu[30];
    long number[N];
    char name[N][10];
    do{
        printf("1.Input record\n2.Calculate total and average score of course\n3.Calculate total and average score of\n4.Sort in descending order by score\n");
        printf("5.Sort in ascending order by score\n6.Sort in ascending order by number\n7.Sort in dictionary order by name\n");
        printf("8.Search by number\n9.Search by name\n10.Statistic analysis\n11.List record\n0.Exit\nPlease enter your choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            {
                printf("Please input the number of students taking the exam:");
                scanf("%d",&x);
                printf("Please input the number of classes:");
                scanf("%d",&cl);
                Inputrecord(number,name,score,x,cl);
                break;
            }
        case 2:
            {
                Calculate_cl(score,sum_cl,aver_cl,x,cl);
                break;
            }
        case 3:
            {
                Calculate_stu(score,sum_stu,aver_stu,x,cl);
                break;
            }
        case 4:
            {
                SortscoreD(number,name,score,x,cl,sum_stu);
                for(int p=0;p<x;p++)
                {
                    printf("%10ld   %s  %4d",number[p],name[p],sum_stu[p]);
                    for(int q=0;q<cl;q++)
                        {
                            printf("%4d ",score[p][q]);
                        }
                    printf("\n");
                }
                printf("\n");
                break;
            }
        case 5:
            {
                SortscoreA(number,sum_stu,name,score,x,cl);
                break;
            }
        case 6:
            {
                Sortnumber(number,sum_stu,name,score,x,cl);
                break;
            }
        case 7:
            {
                Sortname(number,sum_stu,name,score,x,cl);
                break;
            }
        case 8:
            {
                ret=Searchnumber(number,score,m,x);
                SortscoreD(number,name,score,x,cl,sum_stu);
                if(ret!=-1)
                {
                    printf("score:");
                    for(int i=0;i<cl;i++)
                    {
                        printf("%4d",score[ret][i]);
                    }
                    printf("\nTop.%d\n\n",ret+1);
                }
                else
                    printf("Not found!\n\n");
                break;
            }
        case 9:
            {
                ret=Searchname(number,score,name,x);
                SortscoreD(number,name,score,x,cl,sum_stu);
                if(ret!=-1)
                {
                    printf("score:");
                    for(int i=0;i<cl;i++)
                    {
                        printf("%4d",score[ret][i]);
                    }
                    printf("\nTop.%d\n\n",ret+1);
                }
                else
                    printf("Not found!\n\n");
                break;
            }
        case 10:
            {
                Analysis(number,score,x,cl);
                break;
            }
        case 11:
            {
                Listrecord(number,name,score,sum_cl,aver_cl,sum_stu,aver_stu,x,cl);
                break;
            }
        case 0:
            break;
        }
    }while(n>0&&n<=11);
    return 0;
}
int Inputrecord(long number[],char name[][10],int score[][6],int x,int cl)    /*键盘输入学生学号与成绩*/
{
    int i=-1;
    do{
        i++;
        printf("Please input number,name:\n");
        scanf("%ld %s",&number[i],&name[i]);
        printf("Please input the score:\n");
        for(int j=0;j<cl;j++)
        {
            scanf("%d",&score[i][j]);
        }
    }while(i<x-1);
    return 0;
}
void Calculate_cl(int score[][6],int sum_cl[],float aver_cl[],int x,int cl)    /*计算每门课程总分与平均分*/
{
    for(int i=0;i<cl;i++)
    {
        int temp=0;
        for(int j=0;j<x;j++)
        {
            temp+=score[j][i];
        }
        sum_cl[i]=temp;
        aver_cl[i]=(float)sum_cl[i]/x;
    }
    for(int p=0;p<cl;p++)
    {
        printf("class%d:%4d %4.2f\n",p+1,sum_cl[p],aver_cl[p]);
    }
    printf("\n");
}
void Calculate_stu(int score[][6],int sum_stu[],float aver_stu[],int x,int cl)    /*计算每位学生总分和平均分*/
{
    for(int i=0;i<x;i++)
    {
        int temp=0;
        for(int j=0;j<cl;j++)
        {
            temp+=score[i][j];
        }
        sum_stu[i]=temp;
        aver_stu[i]=(float)sum_stu[i]/cl;
    }
    for(int p=0;p<x;p++)
    {
        printf("student%d:%4d %4.2f\n",p+1,sum_stu[p],aver_stu[p]);
    }
    printf("\n");
}
void SortscoreD(long number[],char name[][10],int score[][6],int x,int cl,int sum_stu[])    /*按成绩由高到低输出成绩表*/
{
    int i,j,k,temp1;
    long temp2;
    char temp3[10];
    int temp4;
    for(i=0;i<x-1;i++)
    {
        k=i;
        for(j=i+1;j<x;j++)
        {
            if(sum_stu[j]>sum_stu[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=sum_stu[k];sum_stu[k]=sum_stu[i];sum_stu[i]=temp1;
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);
            temp2=number[k];number[k]=number[i];number[i]=temp2;
            for(int n=0;n<cl;n++)
            {
                temp4=score[k][n];
                score[k][n]=score[i][n];
                score[i][n]=temp4;
            }
        }
    }
}
void SortscoreA(long number[],int sum_stu[],char name[][10],int score[][6],int x,int cl)    /*按成绩由低到高输出成绩表*/
{
    int i,j,k,temp1,temp4;
    long temp2;
    char temp3[10];
    for(i=0;i<x-1;i++)
    {
        k=i;
        for(j=i+1;j<x;j++)
        {
            if(sum_stu[j]>sum_stu[k])
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=sum_stu[k];sum_stu[k]=sum_stu[i];sum_stu[i]=temp1;
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);
            temp2=number[k];number[k]=number[i];number[i]=temp2;
            for(int n=0;n<cl;n++)
            {
                temp4=score[k][n];
                score[k][n]=score[i][n];
                score[i][n]=temp4;
            }
        }
    }
    for(int p=x-1;p>=0;p--)
    {
       {
        printf("%10ld  %s  %4d",number[p],name[p],sum_stu[p]);
        for(int q=0;q<cl;q++)
        {
            printf("%4d",score[p][q]);
        }
        printf("\n");
    }
    }printf("\n");
}
void Sortnumber(long number[],int sum_stu[],char name[][10],int score[][6],int x,int cl)    /*按学号由低到高输出成绩表*/
{
    int i,j,k,temp1,temp4;
    long temp2;
    char temp3[10];
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
            temp1=sum_stu[k];sum_stu[k]=sum_stu[i];sum_stu[i]=temp1;
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);
            temp2=number[k];number[k]=number[i];number[i]=temp2;
            for(int n=0;n<cl;n++)
            {
                temp4=score[k][n];
                score[k][n]=score[i][n];
                score[i][n]=temp4;
            }
        }
    }
    for(int p=x-1;p>=0;p--)
    {
        {
        printf("%10ld  %s  %4d",number[p],name[p],sum_stu[p]);
        for(int q=0;q<cl;q++)
        {
            printf("%4d ",score[p][q]);
        }
        printf("\n");
    }
    }printf("\n");
}
void Sortname(long number[],int sum_stu[],char name[][10],int score[][6],int x,int cl)   /*按姓名输出成绩表*/
{
    int i,j,k,temp1,temp4;
    long temp2;
    char temp3[10];
    for(i=0;i<x-1;i++)
    {
        k=i;
        for(j=i+1;j<x;j++)
        {
            if(strcmp(name[j],name[k])>0)
            {
                k=j;
            }
        }
      if(k!=i)
        {
            temp1=sum_stu[k];sum_stu[k]=sum_stu[i];sum_stu[i]=temp1;
            strcpy(temp3,name[k]);
            strcpy(name[k],name[i]);
            strcpy(name[i],temp3);
            temp2=number[k];number[k]=number[i];number[i]=temp2;
            for(int n=0;n<cl;n++)
            {
                temp4=score[k][n];
                score[k][n]=score[i][n];
                score[i][n]=temp4;
            }
        }
    }
    for(int p=x-1;p>=0;p--)
    {
        printf("%10ld  %s  %4d",number[p],name[p],sum_stu[p]);
        for(int q=0;q<cl;q++)
        {
            printf("%4d ",score[p][q]);
        }
        printf("\n");
    }
    printf("\n");
}
int Searchnumber(long number[],int score[][6],long m,int x)    /*按学号查找成绩*/
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
int Searchname(long number[],int score[][6],char name[][10],int x)    /*按姓名查找成绩*/
{
    char a[N];
    printf("Please input the name for researching:\n");
    int i;
    getchar();
    gets(a);
    for(i=0;i<x;i++)
    {
        if(strcmp(name[i],a)==0)
        return i;
    }
    return -1;
}
void Analysis(long number[],int score[][6],int x,int cl)  /*统计各层次学生百分比*/
{
    for(int k=0;k<cl;k++)
    {
        printf("class %d\n",k+1);
        int count1=0,count2=0,count3=0,count4=0,count5=0;
        for(int i=0;i<x;i++)
            {
                if(score[i][k]>=90&&score[i][k]<=100)
                {
                    count1++;
                }
                else if(score[i][k]>=80&&score[i][k]<=89)
                {
                    count2++;
                }
                else if(score[i][k]>=70&&score[i][k]<=79)
                {
                    count3++;
                }
                else if(score[i][k]>=60&&score[i][k]<=69)
                {
                    count4++;
                }
                else
                    count5++;
            }
        printf("优秀占%.2f%%\n,良好占%.2f%%\n,中等占%.2f%%\n,及格占%.2f%%\n,不及格占%.2f%%\n\n",(float)count1/x*100,(float)count2/x*100,(float)count3/x*100,(float)count4/x*100,(float)count5/x*100);
    }

}
void Listrecord(long number[],char name[][10],int score[][6],int sum_cl[],float aver_cl[],int sum_stu[],float aver_stu[],int x,int cl)    /*输出成绩表与课程总分、平均分*/
{
    for(int p=x-1;p>=0;p--)
    {
        printf("%10ld  %s  %4d",number[p],name[p],sum_stu[p]);
        for(int q=0;q<cl;q++)
        {
            printf("%4d ",score[p][q]);
        }
        printf("\n");
    }
    for(int p=0;p<cl;p++)
    {
        printf("class%d:%6d%6.2f\n",p+1,sum_cl[p],aver_cl[p]);
    }
    printf("\n");
}


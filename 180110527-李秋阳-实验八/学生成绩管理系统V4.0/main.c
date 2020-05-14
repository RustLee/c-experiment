#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
typedef struct student
{
    long number;
    char name[10];
    int score[6];
}STUDENT;
int Inputrecord(STUDENT stu[],int x,int cl);
void Calculate_cl(STUDENT stu[],int sum_cl[],float aver_cl[],int x,int cl);
void Calculate_stu(STUDENT stu[],int sum_stu[],float aver_stu[],int x,int cl);
void SortscoreD(STUDENT stu[],int x,int cl,int sum_stu[]);
void SortscoreA(STUDENT stu[],int x,int cl,int sum_stu[]);
void Sortnumber(STUDENT stu[],int x,int cl,int sum_stu[]);
void Sortname(STUDENT stu[],int x,int cl,int sum_stu[]);
int Searchnumber(STUDENT stu[],long m,int x);
int Searchname(STUDENT stu[],int x);
void Analysis(STUDENT stu[],int x,int cl);
void Listrecord(STUDENT stu[],int sum_cl[],float aver_cl[],int sum_stu[],float aver_stu[],int x,int cl);
int main()
{
    printf("Number:180110527\nSubject:No.1\n\n\n");
    int x,n,sum,ret,cl;
    long m;
    float aver_cl[6],aver_stu[N];
    int sum_cl[6],sum_stu[N];
    STUDENT stu[N];
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
                Inputrecord(stu,x,cl);
                break;
            }
        case 2:
            {
                Calculate_cl(stu,sum_cl,aver_cl,x,cl);
                break;
            }
        case 3:
            {
                Calculate_stu(stu,sum_stu,aver_stu,x,cl);
                break;
            }
        case 4:
            {
                SortscoreD(stu,x,cl,sum_stu);
                for(int p=0;p<x;p++)
                {
                    {
                        printf("%10ld  %s  %4d",stu[p].number,stu[p].name,sum_stu[p]);
                    for(int q=0;q<cl;q++)
                    {
                        printf("%4d ",stu[p].score[q]);
                    }
                    printf("\n");
                    }
                }printf("\n");
                break;
            }
        case 5:
            {
                SortscoreA(stu,x,cl,sum_stu);
                break;
            }
        case 6:
            {
                Sortnumber(stu,x,cl,sum_stu);
                break;
            }
        case 7:
            {
                Sortname(stu,x,cl,sum_stu);
                break;
            }
        case 8:
            {
                ret=Searchnumber(stu,m,x);
                SortscoreD(stu,x,cl,sum_stu);
                if(ret!=-1)
                {
                    printf("score:");
                    for(int i=0;i<cl;i++)
                    {
                        printf("%4d",stu[ret].score[i]);
                    }
                    printf("\nTop.%d\n\n",ret+1);
                }
                else
                    printf("Not found!\n\n");
                break;
            }
        case 9:
            {
                ret=Searchname(stu,x);
                SortscoreD(stu,x,cl,sum_stu);
                if(ret!=-1)
                {
                    printf("score:");
                    for(int i=0;i<cl;i++)
                    {
                        printf("%4d",stu[ret].score[i]);
                    }
                    printf("\nTop.%d\n\n",ret+1);
                }
                else
                    printf("Not found!\n\n");
                break;
            }
        case 10:
            {
                Analysis(stu,x,cl);
                break;
            }
        case 11:
            {
                Listrecord(stu,sum_cl,aver_cl,sum_stu,aver_stu,x,cl);
                break;
            }
        case 0:
            break;
        }
    }while(n>0&&n<=11);
    return 0;
}
int Inputrecord(STUDENT stu[],int x,int cl)
{
    int i,j;
    for(i=0;i<x;i++)
    {
        printf("Input record %d:\n",i+1);
        scanf("%ld",&stu[i].number);
        scanf("%s",&stu[i].name);
        for(j=0;j<cl;j++)
        {
            scanf("%d",&stu[i].score[j]);
        }
    }
}
void Calculate_cl(STUDENT stu[],int sum_cl[],float aver_cl[],int x,int cl)
{
     for(int i=0;i<cl;i++)
    {
        sum_cl[i]=0;
        for(int j=0;j<x;j++)
        {
            sum_cl[i]=sum_cl[i]+stu[j].score[i];
        }
        aver_cl[i]=(float)sum_cl[i]/x;
    }
    for(int p=0;p<cl;p++)
    {
        printf("class%d:%4d %4.2f\n",p+1,sum_cl[p],aver_cl[p]);
    }
    printf("\n");
}
void Calculate_stu(STUDENT stu[],int sum_stu[],float aver_stu[],int x,int cl)
{
    for(int i=0;i<x;i++)
    {
        sum_stu[i]=0;
        for(int j=0;j<cl;j++)
        {
            sum_stu[i]=sum_stu[i]+stu[i].score[j];
        }
        aver_stu[i]=(float)sum_stu[i]/cl;
    }
    for(int p=0;p<x;p++)
    {
        printf("student%d:%4d %4.2f\n",p+1,sum_stu[p],aver_stu[p]);
    }
    printf("\n");
}
void SortscoreD(STUDENT stu[],int x,int cl,int sum_stu[])
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
            strcpy(temp3,stu[k].name);
            strcpy(stu[k].name,stu[i].name);
            strcpy(stu[i].name,temp3);
            temp2=stu[k].number;stu[k].number=stu[i].number;stu[i].number=temp2;
            for(int n=0;n<cl;n++)
            {
                temp4=stu[k].score[n];
                stu[k].score[n]=stu[i].score[n];
                stu[i].score[n]=temp4;
            }
        }
    }
}
void SortscoreA(STUDENT stu[],int x,int cl,int sum_stu[])
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
            strcpy(temp3,stu[k].name);
            strcpy(stu[k].name,stu[i].name);
            strcpy(stu[i].name,temp3);
            temp2=stu[k].number;stu[k].number=stu[i].number;stu[i].number=temp2;
            for(int n=0;n<cl;n++)
            {
                temp4=stu[k].score[n];
                stu[k].score[n]=stu[i].score[n];
                stu[i].score[n]=temp4;
            }
        }
    }
    for(int p=x-1;p>=0;p--)
    {
        {
        printf("%10ld  %s  %4d",stu[p].number,stu[p].name,sum_stu[p]);
        for(int q=0;q<cl;q++)
        {
            printf("%4d ",stu[p].score[q]);
        }
        printf("\n");
    }
    }printf("\n");
}
void Sortnumber(STUDENT stu[],int x,int cl,int sum_stu[])
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
            if(stu[j].number>stu[k].number)
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=sum_stu[k];sum_stu[k]=sum_stu[i];sum_stu[i]=temp1;
            strcpy(temp3,stu[k].name);
            strcpy(stu[k].name,stu[i].name);
            strcpy(stu[i].name,temp3);
            temp2=stu[k].number;stu[k].number=stu[i].number;stu[i].number=temp2;
            for(int n=0;n<cl;n++)
            {
                temp4=stu[k].score[n];
                stu[k].score[n]=stu[i].score[n];
                stu[i].score[n]=temp4;
            }
        }
    }
    for(int p=x-1;p>=0;p--)
    {
        {
        printf("%10ld  %s  %4d",stu[p].number,stu[p].name,sum_stu[p]);
        for(int q=0;q<cl;q++)
        {
            printf("%4d ",stu[p].score[q]);
        }
        printf("\n");
    }
    }printf("\n");
}
void Sortname(STUDENT stu[],int x,int cl,int sum_stu[])
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
            if(strcmp(stu[j].name,stu[k].name)>0)
            {
                k=j;
            }
        }
        if(k!=i)
        {
            temp1=sum_stu[k];sum_stu[k]=sum_stu[i];sum_stu[i]=temp1;
            strcpy(temp3,stu[k].name);
            strcpy(stu[k].name,stu[i].name);
            strcpy(stu[i].name,temp3);
            temp2=stu[k].number;stu[k].number=stu[i].number;stu[i].number=temp2;
            for(int n=0;n<cl;n++)
            {
                temp4=stu[k].score[n];
                stu[k].score[n]=stu[i].score[n];
                stu[i].score[n]=temp4;
            }
        }
    }
    for(int p=x-1;p>=0;p--)
    {
        {
        printf("%10ld  %s  %4d",stu[p].number,stu[p].name,sum_stu[p]);
        for(int q=0;q<cl;q++)
        {
            printf("%4d ",stu[p].score[q]);
        }
        printf("\n");
    }
    }printf("\n");
}
int Searchnumber(STUDENT stu[],long m,int x)
{
    printf("Please input the number for researching:\n");
    scanf("%ld",&m);
    int i;
    for(i=0;i<x;i++)
    {
        if(stu[i].number==m)
            return i;
    }
    return -1;
}
int Searchname(STUDENT stu[],int x)
{
    char a[N];
    printf("Please input the name for researching:\n");
    int i;
    getchar();
    gets(a);
    for(i=0;i<x;i++)
    {
        if(strcmp(stu[i].name,a)==0)
        return i;
    }
    return -1;
}
void Analysis(STUDENT stu[],int x,int cl)
{
    for(int k=0;k<cl;k++)
    {
        printf("class %d\n",k+1);
        int count1=0,count2=0,count3=0,count4=0,count5=0;
        for(int i=0;i<x;i++)
            {
                if(stu[i].score[k]>=90&&stu[i].score[k]<=100)
                {
                    count1++;
                }
                else if(stu[i].score[k]>=80&&stu[i].score[k]<=89)
                {
                    count2++;
                }
                else if(stu[i].score[k]>=70&&stu[i].score[k]<=79)
                {
                    count3++;
                }
                else if(stu[i].score[k]>=60&&stu[i].score[k]<=69)
                {
                    count4++;
                }
                else
                    count5++;
            }
        printf("优秀占%.2f%%\n,良好占%.2f%%\n,中等占%.2f%%\n,及格占%.2f%%\n,不及格占%.2f%%\n\n",(float)count1/x*100,(float)count2/x*100,(float)count3/x*100,(float)count4/x*100,(float)count5/x*100);
    }

}
void Listrecord(STUDENT stu[],int sum_cl[],float aver_cl[],int sum_stu[],float aver_stu[],int x,int cl)
{
    for(int p=x-1;p>=0;p--)
    {
        printf("%10ld  %s  %4d",stu[p].number,stu[p].name,sum_stu[p]);
        for(int q=0;q<cl;q++)
        {
            printf("%4d ",stu[p].score[q]);
        }
        printf("\n");
    }
    for(int p=0;p<cl;p++)
    {
        printf("class%d:%6d%6.2f\n",p+1,sum_cl[p],aver_cl[p]);
    }
    printf("\n");
}

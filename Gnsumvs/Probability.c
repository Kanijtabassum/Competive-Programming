#include<stdio.h>
#define SIZEN 102
double Grid[SIZEN][SIZEN];
int Table[SIZEN][SIZEN];
int N,E,mt,t,Case;
double T[SIZEN],F[SIZEN],P;

void initi()
{
    int i,j;
    for(i=0;i<SIZEN;i++)
    {
        for(j=0;j<SIZEN;j++)
        {
            Grid[i][j]=0.000;
            Table[i][j]=0;
        }

        T[i]=0.000;
        F[i]=0.000;

    }
}
void readCase()
{
    int u,v;;
    scanf("%d %d %d",&N,&E,&mt);
    while(E--)
    {
        scanf("%d %d %lf",&u,&v,&P);
        Grid[u][v]=P;
        Table[u][v]=1;
    }
    t=mt/10;


}
void solveCase()
{
    int i,j,k;
    F[1]=1.000;
    for(i=1;i<=t;i++)
    {
        for(j=1;j<=N;j++)
        {
            for(k=1;k<=N;k++)
            {
                T[k]+=F[j]*Grid[j][k];
            }
        }
        int x;
        for(x=1;x<=N;x++)
        {
            F[x]=T[x];
            T[x]=0.000;
        }
    }
}
void printCase()
{
    int i, node;
    double max;
    max=F[1];
    node=1;
    for(i=2;i<=N;i++)
    {
        if(max<F[i])
        {
            max=F[i];
            node=i;
        }
    }
    if(max==0.000)
        printf("#%d 0\n",++Case);
    else
    printf("#%d %d %lf\n",++Case,node,max);
}
int main()
{
    int T;
    freopen("Probability_input1.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        initi();
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}

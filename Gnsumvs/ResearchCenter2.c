#include<stdio.h>
#define SIZEN 22
#define SIZER 6

int N,C,X[SIZER],Y[SIZER],Case,Ans;
int Grid[SIZEN][SIZEN];
int Max[SIZEN][SIZEN];
int Dist[SIZER][SIZEN][SIZEN];
void readCase()
{

    scanf("%d %d",&N,&C);
    int k,i,j;
    for(i=1;i<=C;i++)
        scanf("%d %d",&X[i],&Y[i]);

    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            Grid[i][j]=0;

    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            scanf("%d",&Grid[i][j]);

    for(k=1;k<=C;k++)
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                Dist[k][i][j]=N*N;
}
void dfs(int i, int j, int k, int cost)
{
    if(cost<Dist[k][i][j])
        Dist[k][i][j]=cost;
    else
        return;
    if(i-1>0 && Grid[i-1][j])
        dfs(i-1,j,k,cost+1);
    if(i+1<=N && Grid[i+1][j])
        dfs(i+1,j,k,cost+1);
    if(j-1>0 && Grid[i][j-1])
        dfs(i,j-1,k,cost+1);
     if(j+1<=N && Grid[i][j+1])
        dfs(i,j+1,k,cost+1);
}
void solveCase()
{
    int k;
    for(k=1;k<=C;k++)
        dfs(X[k],Y[k],k,0);
    int i,j;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            Max[i][j]=0;
    for(k=1;k<=C;k++)
    {
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {

                if(Max[i][j]<Dist[k][i][j])
                    Max[i][j]=Dist[k][i][j];
            }
        }
    }

    Ans=11111;
    for(k=1;k<=C;k++)
    {
        Max[X[k]][Y[k]]=11111;
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(Ans>Max[i][j])
                Ans=Max[i][j];
        }
    }
}
void printCase()
{
    /*
    int i,j,k;
      for(i=1;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                printf("%d ",Max[i][j]);
            }
            printf("\n");
        }
*/

        printf("#%d %d\n",++Case,Ans);
}
int main()
{
    int T;
    freopen("researchCenter_input.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        readCase();
        solveCase();
        printCase();

    }
    return 0;
}

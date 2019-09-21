#include<stdio.h>
#define SIZEN 101
int Grid[SIZEN][SIZEN];
int N,M,color[SIZEN],flag;
void readCase()
{
    scanf("%d %d",&N,&M);
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
        {
            Grid[i][j]=0;
        }
        color[i]=0;
    }
    while(M--)
    {
        int u, v;
        scanf("%d %d",&u,&v);
        Grid[u][v]=Grid[v][u]=1;
    }
}
int solve(int i, int c)
{
    color[i]=c;
    int j;
    for(j=1;j<=N;j++)
    {
        if(Grid[i][j])
        {
            if(!color[j])
            {
                if(0==solve(j,3-c))
                    return 0;
            }
            else if(color[j]==c)
                return 0;

        }
    }
    //color[i]=0;
    return 1;
}
void solveCase()
{
    int i;
    flag=0;
    for(i=1;i<=N;i++) if(!color[i])
    {
        if(1==solve(i,1))
            flag=1;
        else
            break;
    }
}
void printCase()
{
    int i;
    if(flag)
    {
        for(i=1;i<=N;i++) if(color[i]==2)
            printf("%d ",i);
        printf("\n");
    }
    else
        printf("-1\n");
}
int main()
{
    int T;
    freopen("bicoloringInput.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}

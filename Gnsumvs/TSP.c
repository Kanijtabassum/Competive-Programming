#include<stdio.h>
#define SIZEN 101
int T,N,x[SIZEN],y[SIZEN],Case;
int path[SIZEN][SIZEN];
int visited[SIZEN],Min,Ans;
void readCase()
{
    int i;
    scanf("%d",&N);
    scanf("%d %d",&x[0],&y[0]);
    scanf("%d %d",&x[N+1],&y[N+1]);
    for(i=1;i<=N;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
}
int Abs(int i,int j)
{
    if(i>j)
        return i-j;
    else
        return j-i;
}
int pathCost(int i, int j)
{
    int sum=0;
    sum+=Abs(x[i],x[j]);
    sum+=Abs(y[i],y[j]);
    return sum;
}
void solveCase(int level, int i, int cost)
{
    if(cost>Min)
        return;
    if(level==N+1)
    {
        if(Min>cost+path[i][N+1])
            Min=cost+path[i][N+1];
        Ans=Min;
        return;
    }
    int j;
    for(j=1;j<=N+1;j++) if(!visited[j])
    {
        visited[j]=1;
        solveCase(level+1,j,cost+path[i][j]);
        visited[j]=0;
    }
}
void initi()
{
    int i,j;
    Min=1111111;
    for(i=0;i<=N+1;i++)
    {
        for(j=0;j<=N+1;j++)
        {
            path[i][j]=pathCost(i,j);
        }
        visited[i]=0;
    }
}
void printCase()
{
    printf("#%d: %d\n",++Case,Ans);
}
int main()
{
    freopen("TSP_input.txt","r",stdin);
    //freopen("TSP_output.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        readCase();
        initi();
        solveCase(0,0,0);
        printCase();
    }
    return 0;
}

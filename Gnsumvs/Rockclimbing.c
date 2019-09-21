#include<stdio.h>
#define SIZEN 53
#define INF (SIZEN*SIZEN)
int Grid[SIZEN][SIZEN];
int dp[SIZEN][SIZEN];
int T,N,X,Y,cas;
void readCase()
{
    int i,j;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d",&Grid[i][j]);
            if(3==Grid[i][j])
            {
                X=i;
                Y=j;
            }
        }
    }
}
void solve(int x, int y, int curZero , int maxZero)
{
    if(0==Grid[x][y])
        curZero++;
    else
        curZero=0;
    if(curZero>maxZero)
        maxZero=curZero;

    if(maxZero<dp[x][y])
        dp[x][y]=maxZero;
    else
        return;
    if(x-1>=0)
        solve(x-1,y,curZero, maxZero);
    if(x+1<N)
        solve(x+1,y,curZero, maxZero);
    if(y-1>=0 && Grid[x][y-1])
        solve(x,y-1,curZero,maxZero);
    if(y+1<N && Grid[x][y+1])
        solve(x,y+1,curZero, maxZero);
}
void solveCase()
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            dp[i][j]=INF;
    solve(N-1,0,0,0);
    if(INF==dp[X][Y])
        dp[X][Y]=-1;

}
void printCase()
{
    printf("#%d: %d\n",++cas,dp[X][Y]);
}
int main()
{
    freopen("Rock_input.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}

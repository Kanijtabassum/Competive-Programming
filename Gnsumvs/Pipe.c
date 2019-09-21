#include<stdio.h>
#define SIZEN 55
int dp[SIZEN][SIZEN];
int Grid[SIZEN][SIZEN];
int T,N,M,X,Y,L;
int count,cas;

void dpinit()
{
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            Grid[i][j]=0;
        }
    }
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            scanf("%d",&Grid[i][j]);
}
void readCase()
{
    scanf("%d %d %d %d %d",&N,&M,&X,&Y,&L);

}
void solve(int x, int y, int l)
{
    if(l>L)
        return;

    int temp;
    count++;
    temp=Grid[x][y];
    Grid[x][y]=0;

    if((1==temp || 2==temp || 4==temp || 7==temp) && (x-1>=0) && (1==Grid[x-1][y] || 2==Grid[x-1][y] || 5==Grid[x-1][y] || 6==Grid[x-1][y]) )
        solve(x-1,y,l+1);

    if((1==temp || 2==temp || 5==temp || 6==temp) && (x+1<N) && (1==Grid[x+1][y] || 2==Grid[x+1][y] || 4==Grid[x+1][y] || 7==Grid[x+1][y]) )
        solve(x+1,y,l+1);

    if((1==temp || 3==temp || 5==temp || 4==temp) && (y+1<M) && (1==Grid[x][y+1] || 3==Grid[x][y+1] || 7==Grid[x][y+1] || 6==Grid[x][y+1]) )
        solve(x,y+1,l+1);

    if((1==temp || 3==temp || 6==temp || 7==temp) && (y-1>=0) && (1==Grid[x][y-1] || 3==Grid[x][y-1] || 5==Grid[x][y-1] || 4==Grid[x][y-1]) )
        solve(x,y-1,l+1);
}
int main()
{
    freopen("PipeInput.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        count=0;
        readCase();
        dpinit();
        solve(X,Y,0);
        printf("#%d : %d\n",++cas,count);
    }
    return 0;
}


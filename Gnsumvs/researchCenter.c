#include<stdio.h>
#define SIZEN 22
#define SIZER 6
int Grid[SIZEN][SIZEN];
int dist[SIZEN][SIZEN][SIZER];
int X[SIZER],Y[SIZER];
int N,M,R,C,Ans,Case;


void readCase()
{
    int i,j;
    scanf("%d %d %d",&N,&M,&C);
    for(i=0;i<N;i++) for(j=0;j<M;j++)
        scanf("%d",&Grid[i][j]);
    for(i=0;i<C;i++)
        scanf("%d %d",&X[i],&Y[i]);
}
void dfs(int i, int j, int k, int cost)
{
    if(cost<dist[i][j][k])
        dist[i][j][k]=cost;
    else
        return;
    if(i-1>=0 && 1==Grid[i-1][j])
        dfs(i-1,j,k,cost+1);
    if(i+1<N && 1==Grid[i+1][j])
        dfs(i+1,j,k,cost+1);
    if(j-1>=0 && 1==Grid[i][j-1])
        dfs(i,j-1,k,cost+1);
    if(j+1<M && 1==Grid[i][j+1])
        dfs(i,j+1,k,cost+1);
}
void solveCase()
{
    int i, j, k, x, y, max, centerdist, cardist;
    Ans=N*N;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            for(k=0;k<C;k++)
                dist[i][j][k]=N*M;
    for(k=0;k<C;k++)
        dfs(X[k],Y[k],k,0);
    for(k=0;k<C;k++)
        Grid[X[k]][Y[k]]=2;
    for(i=0;i<N;i++)
        for(j=0;j<M;j++)
            if(1==Grid[i][j]){
                    for(x=0;x<N;x++) for(y=0;y<M;y++) if(Grid[x][y]){
                            max=0;
                            for(k=0;k<C;k++){
                                centerdist=dist[i][j][k];
                                cardist=dist[x][y][k];
                                if(centerdist<cardist){
                                    if(centerdist>max)
                                        max=centerdist;
                                }
                                else
                                {
                                    if(cardist>max)
                                        max=cardist;
                                }
                            }
                            if(max<Ans)
                                Ans=max;
                    }
            }
}
void printCase()
{
    if(Ans==N*M)
        Ans=-1;
    printf("#%d %d\n",++Case,Ans);
}
int main()
{
    int T;
    freopen("c.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
         readCase();
         solveCase();
        printCase();
    }
    return 0;
}

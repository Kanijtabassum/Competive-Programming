#include<stdio.h>
#define SIZEN 21
int path[SIZEN][SIZEN];
int visited[SIZEN];
int M,N,flag,cas;
void readCase()
{
    int i,j,x,y;
    scanf("%d%d",&N,&M);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            path[i][j]=0;
        }

    }
    while(M--)
    {
        scanf("%d%d",&x,&y);
        path[x][y]=1;
    }
}
int fill(int src, int cur)
{
    int i;
    visited[cur]=1;
    for(i=1;i<=N;i++)
    {
        if(1==path[cur][i])
        {
            if(0==visited[i])
            {
                if(1==fill(src,i))
                    return 1;
            }
            else if(src==i)
                return 1;
        }
    }
    visited[i]=0;
    return 0;
}
void solveCase()
{
    int i;
    flag=0;
    for(i=1;i<=N;i++)
        visited[i]=0;
    for(i=1;i<=N;i++)
    {
        if(0==visited[i])
        {
            if(1==fill(1,1)){
                flag=1;
                break;
            }
        }
    }
}
void printCase()
{

    printf("#%d ",++cas);
    int i,j;
    if(flag)
    {

        for(i=1;i<=N;i++)
        {
            if(1==visited[i])
                printf("%d ",i);
        }
         printf("\n");

    }

    else
            printf("-1\n");

}
int main()
{
    int T;
    freopen("h.txt","r",stdin);
    scanf("%d",&T);
    while(T--){
        readCase();
        solveCase();
        printCase();
    }
    return 0;

}

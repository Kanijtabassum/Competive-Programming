#include<stdio.h>
#define SIZEN 10001
int Grid[SIZEN][SIZEN];
int visited[SIZEN];
int n,m,l,x,count;
void readCase()
{
    scanf("%d %d %d",&n,&m,&l);
    while(m--)
    {
        int n1,n2;
        scanf("%d %d",&n1,&n2);
        Grid[n1][n2]=1;

    }

}
void initi()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            Grid[i][j]=0;
        }
        visited[i]=0;
    }
}
void solve(int x)
{

    visited[x]=1;

    int i;
    for(i=1;i<=n;i++) if(Grid[x][i])
    {
        if(!visited[i])
        {

            solve(i);
        }
    }
}
void solveCase()
{
    int i;
    for(i=1;i<=l;i++){
            scanf("%d",&x);
            solve(x);
        }
}
void printCase()
{
    int i;
    for(i=1;i<=n;i++){
        if(visited[i])
            count++;
    }
    printf("%d\n",count);
}
int main()
{
    int T,i;
    freopen("h.txt","r",stdin);
   // freopen("o.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        count=0;
        initi();
        readCase();
        solveCase();
        printCase();


    }
    return 0;
}

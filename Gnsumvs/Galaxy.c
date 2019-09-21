#include<stdio.h>
#define SIZEN 20
int N,M,W,X[SIZEN],Y[SIZEN];
int U[SIZEN], V[SIZEN], cost[SIZEN];
int visited[SIZEN],Ans,Case;

void readCase()
{
    int i;
    scanf("%d %d %d",&N,&M,&W);
   for(i=1;i<=M;i++)
    {
        scanf("%d %d",&X[i],&Y[i]);
    }
    for(i=1;i<=W;i++)
    {
        scanf("%d %d %d",&U[i],&V[i],&cost[i]);
    }
}
int Abs(int i,int j)
{
    if(i>j)
        return i-j;
    else
        return j-i;
}
void solve(int level, int r, int c, int dist)
{
   int i,distu,distv;
   if((N-r+N-c+dist)<Ans){
        Ans=N-r+N-c+dist;
   }
   if(level==W)
    return;
   if(dist>Ans)
    return;
   for(i=1;i<=W;i++) if(!visited[i])
    {
        visited[i]=1;
        distu=Abs(r,X[U[i]])+Abs(c,Y[U[i]]);
        distv=Abs(r,X[V[i]])+Abs(c,Y[V[i]]);
        if(distu<distv)
            solve(level+1, X[V[i]],Y[V[i]], distu+dist+cost[i]);
        else
            solve(level+1, X[U[i]],Y[U[i]], distv+dist+cost[i]);
        visited[i]=0;
    }

}
void solveCase()
{
    int i;
    for(i=1;i<=W;i++)
        visited[i]=0;
    Ans=2*(N-1);
    solve(0,1,1,0);
}

void printCase()
{
    int i;
    printf("#%d: %d\n",++Case,Ans);
}
int main()
{
    freopen("Galaxy_input.txt","r", stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}

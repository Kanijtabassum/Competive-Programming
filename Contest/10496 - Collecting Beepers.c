#include<stdio.h>
int N,flag[100],min;
int x[12],y[12];
int diff(int i, int j)
{
    int sum=0;
    if(x[i]>x[j])
        sum+=x[i]-x[j];
    else
        sum+=x[j]-x[i];
    if(y[i]>y[j])
        sum+=y[i]-y[j];
    else
        sum+=y[j]-y[i];
    return sum;


}
void solve(int level, int i,int cost)
{
    if(level==N)
    {
        if(min>(cost+diff(i,0)))
           min=(cost+diff(i,0));
        //printf("%d\n",cost);

        return;
    }
    int j;
    for(j=1;j<=N;j++)
    {
        if(flag[j]==0)
        {
            flag[j]=1;
            solve(level+1,j,(cost+diff(i,j)));
            flag[j]=0;

        }
    }
}
int main()
{
    int i,j,tc;
    freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    while(tc--)
    {
        min=10000;
        scanf("%*d %*d");
        scanf("%d%d",&x[0],&y[0]);
        scanf("%d",&N);
        for(i=1,j=0;i<=N,j<N;i++,j++)
        {
            scanf("%d%d",&x[i],&y[i]);
            flag[j]=0;
        }
        solve(0,0,0);
       printf("The shortest path has length %d\n",min);

    }
    return 0;
}

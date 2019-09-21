#include<stdio.h>
#define SIZEN 101
int flag[SIZEN],ballons[SIZEN],blust[SIZEN],arr[SIZEN];
int T,N,max,Case;
void readCase()
{
    scanf("%d",&N);
    int i;
    for(i=0;i<N;i++)
        scanf("%d",&ballons[i]);
    for(i=0;i<SIZEN;i++)
        flag[i]=0;
}
int left(int x)
{
    int i;
    for(i=x-1;i>=0;i--) if(!blust[i])
        return ballons[i];
    return 1;
}
int right(int x)
{
    int i;
    for(i=x+1;i<N;i++) if(!blust[i])
        return ballons[i];
    return 1;
}
int cal(int i)
{
    int l,r;
    l=left(arr[i]);
    r=right(arr[i]);
    // return l*ballons[arr[i]]*r;     3 balloon multiplication
    return l*r;
}
void solve(int i, int sum)
{
    int j,cv;
    if(i==N)
    {
        if(sum>max)
            max=sum-1;
        return;
    }
    for(j=0;j<N;j++) if(!flag[j])
    {
        flag[j]=1;
        blust[j]=1;
        arr[i]=j;
        cv=cal(i);
        solve(i+1,sum+cv);
        flag[j]=0;
        blust[j]=0;
    }
}
void printCase()
{
    printf("#%d: %d\n",++Case,max);
}
int main()
{
    max=0;
    freopen("balloon_input.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        max=0;
        readCase();
        solve(0,0);
        printCase();
    }

    return 0;
}

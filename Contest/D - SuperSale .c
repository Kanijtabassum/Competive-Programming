#include<stdio.h>
#define SIZEM 1002
#define SIZE_MW 35
int m,mw,p[SIZEM],w[SIZEM],total,q;
int dp[SIZEM][SIZE_MW];
int solve(int i, int sum1)
{
    int left,right;

    if(dp[i][sum1]!=-1)
        return dp[i][sum1];

    if(i==m)
    {
        return dp[i][sum1]=0;
    }

    left = solve(i+1,sum1);
    if(sum1>=w[i])
        right = p[i]+solve(i+1,sum1-w[i]);
    else
        right=0;
    if(left> right)
        return dp[i][sum1]=left;
    else
       return dp[i][sum1]= right;

}
int main()
{
    int i,j,tc;
    freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    while(tc--)
    {
        for(i=0;i<SIZEM;i++)
        {
            for(j=0;j<SIZE_MW;j++)
            {
                dp[i][j]=-1;
            }
        }

        total=0;
         scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&p[i],&w[i]);
        }
         scanf("%d",&q);
         for(i=0;i<q;i++)
        {
            scanf("%d",&mw);
            total+=solve(0,mw);
        }

       printf("%d\n",total);

    }
    return 0;
}


#include<stdio.h>
#define SIZEN 5
#define SIZE_amt 7490
int dp[SIZEN][SIZE_amt];
int coin[]={1,5,10,25,50};
int C,Ans;
int solveCase(int i, int amount)
{
     int left,right;

    if(i==5){
        if(amount==0)
            return 1;
        else
            return 0;
        }
    if(dp[i][amount]!=-1)  return dp[i][amount];

    left=solveCase(i+1,amount);
    if(amount-coin[i]>=0)
        right=solveCase(i,amount-coin[i]);
    else right=0;

    return dp[i][amount]=left+right;

}
void printCase()
{
    printf("%d\n",Ans);
}
int main()
{
   freopen("h.txt","r",stdin);
   //freopen("o.txt","w",stdout);
    int i,j;
        for(i=0;i<SIZEN;i++)
            for(j=0;j<SIZE_amt;j++)
                dp[i][j]=-1;
    while(1==scanf("%d",&C))
    {
        Ans=0;


        Ans=solveCase(0,C);
        printCase();
    }
    return 0;
}


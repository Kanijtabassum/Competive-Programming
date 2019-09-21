#include<stdio.h>
#define SIZEN 52
#define SIZE_K 1001
#define SIZE_C 22
long long int dp[SIZEN][SIZE_C][SIZE_K];
long long int C[SIZEN],A[SIZEN];
long long int N,K,Ans,Case;

 long long int solveCase(long long int i, long long int taken, long long int amount)
{
     long long int left,right;

    if(i==N){
        if(amount==0)
            return 1;
        else
            return 0;
        }
    if(dp[i][taken][amount]!=-1)  return dp[i][taken][amount];

    left=solveCase(i+1,0,amount);
    if(amount-A[i]>=0 && taken<C[i])
        right=solveCase(i,taken+1,amount-A[i]);
    else right=0;

    return dp[i][taken][amount]=(left+right)%100000007;

}

void readCase()
{
    long long int i;
    scanf("%lld %lld",&N,&K);
    for(i=0;i<N;i++)
        scanf("%lld",&A[i]);
    for(i=0;i<N;i++)
        scanf("%lld",&C[i]);
}
void printCase()
{
    printf("Case %lld: %lld\n",++Case,Ans);
}
int main()
{
   freopen("h.txt","r",stdin);
   freopen("o.txt","w",stdout);
    long long int i,j,z,T;

    scanf("%lld",&T);
    while(T--)
    {
        for(i=0;i<SIZEN;i++)
            for(j=0;j<SIZE_C;j++)
                for(z=0;z<SIZE_K;z++)
                    dp[i][j][z]=-1;

        readCase();
        Ans=solveCase(0,0,K);
        printCase();
    }
    return 0;
}



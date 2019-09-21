#include<stdio.h>
#define SIZEN 10000
#define S_I 30
 long long int dp[S_I][SIZEN],N;
long long int c[ ] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
int cube(int i)
{
        return i*i*i;
}

long long int solve( long long int  i, long long int amount)
{
    long long int left,right;

    if(i==21){
      if(0==amount)
            return 1;
        else
            return 0;

    }


    if(dp[i][amount]!=-1) return dp[i][amount];

    left = solve(i+1,amount);

    if(0<=amount-c[i]){
        right=solve(i,amount-c[i]);
    }
    else
        right=0;


        return dp[i][amount]=left+right;
}

int main()
{
    freopen("h.txt","r",stdin);
   //freopen("o.txt","w",stdout);
   int i,j;
        for(i=0;i<S_I;i++)
            for(j=0;j<SIZEN;j++)
                dp[i][j]=-1;

    while(1==scanf("%lld",&N))
    {

        printf("%lld\n",solve(0,N));
    }

    return 0;
}

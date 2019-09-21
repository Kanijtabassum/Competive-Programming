#include<stdio.h>

#define SIZEN 200
typedef long long  ll;

ll Grid[SIZEN][SIZEN];
ll dp[SIZEN][SIZEN];
ll T,N,R,Ans,C,Case;
void readCase()
{
    ll i,j,k;
    scanf("%lld",&N);
    R=N*2-1;
    C=N;
    for(i=0;i<N;i++)
        for(j=0;j<=i;j++)
            scanf("%lld",&Grid[i][j]);
    for(i=N,k=N-1;i<N*2-1;i++,k--)
        for(j=0;j<k;j++)
            scanf("%lld",&Grid[i][j]);



}
void initDP()
{
    ll i,j,z;
    for(i=0;i<SIZEN;i++){
            for(j=0;j<SIZEN;j++){
                    dp[i][j]=-1;
                    Grid[i][j]=0;
            }
    }

}
ll max(ll x, ll y)
{

    if(x>y)
        return x;
    else
        return y;
}
ll solveCase(ll i, ll j)
{
    if(i>=0 && i < R && j>=0 && j< C){

        if(dp[i][j]!=-1)  return dp[i][j];
        ll temp=-111111111111111;

        temp=max(temp,solveCase(i+1,j)+Grid[i][j]);
        if(i<N-1)
            temp=max(temp,solveCase(i+1,j+1)+Grid[i][j]);
        else
            temp=max(temp,solveCase(i+1,j-1)+Grid[i][j]);
        return dp[i][j]=temp;

    }
    else
        return 0;
}

void printCase()
{
    printf("Case %lld: %lld\n",++Case,Ans);
}
int main()
{
     freopen("h.txt","r",stdin);
     //freopen("o.txt","w",stdout);

    scanf("%lld",&T);
    while(T--)
    {

        initDP();
        readCase();
        Ans=solveCase(0,0);
        printCase();
    }
    return 0;
}

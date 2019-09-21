#include<stdio.h>
#define SIZEN 202
#define SIZE_M 12
#define SIZE_D 22

int dp[SIZEN][SIZE_M][SIZE_D];
int Data[SIZEN];
int N,M,D,Q,Query,set;

int solveCase( int i, int taken, int sum)
{
     int left,right;

    if(M==taken){
        if(sum==0)
            return 1;
        else
            return 0;
        }
    if(i==N)
        return 0;
    if(dp[i][taken][sum]!=-1)  return dp[i][taken][sum];

    left=solveCase(i+1,taken,sum);
    right=solveCase(i+1,taken+1,(((sum+Data[i])%D)+D)%D);


    return dp[i][taken][sum]=(left+right);

}
void initDP()
{
    int i,j,z;
    for(i=0;i<N;i++)
            for(j=0;j<M;j++)
                for(z=0;z<D;z++)
                    dp[i][j][z]=-1;

}
void readQuery()
{
    int Ans;
     for(Query=1;Query<=Q;Query++){
        scanf("%d %d",&D,&M);
        initDP();
        Ans=solveCase(0,0,0);
        printf("QUERY %d: %d\n",Query,Ans);
    }
}
void readCase()
{
    long long int i;

    for(i=0;i<N;i++)
        scanf("%d",&Data[i]);

}

int main()
{
   freopen("h.txt","r",stdin);
  freopen("o.txt","w",stdout);


    set=1;
    while(scanf("%d %d",&N,&Q) && N && Q)
    {

        readCase();
        printf("SET %d:\n",set++);
        readQuery();

    }
    return 0;
}




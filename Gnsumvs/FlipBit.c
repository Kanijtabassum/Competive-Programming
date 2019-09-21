#include<stdio.h>
#define SIZEN 101
int T,N,M,K,Ans;
int flip[SIZEN][SIZEN],dec[SIZEN];
void readCase()
{
    int i,j;
    scanf("%d%d%d",&N,&M,&K);
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            scanf("%d",&flip[i][j]);
        }
    }
}
void solve()
{
    int i,j;
    int zero,count;
    for(i=0;i<N;i++)
    {
        dec[i]=flip[i][0];
        for(j=1;j<M;j++)
            dec[i]=2*dec[i]+flip[i][j];
    }
    for(i=0;i<N;i++)
    {
        zero=0;
        count=0;
        for(j=0;j<M;j++)
            if(!flip[i][j])
                zero++;
        if(K>=zero)
        {
            if((K-zero)%2==0)
            {
                for(j=0;j<N;j++)
                {
                    if(dec[i]==dec[j])
                        count++;
                }
                if(Ans<count)
                    Ans=count;
            }
        }
    }
    printf("%d\n",Ans);
}

int main()
{
    freopen("FilpBitInput.txt","r",stdin);
    scanf("%d",&T);
    while(T--)
    {
        Ans=0;
        readCase();
        solve();
    }
    return 0;
}

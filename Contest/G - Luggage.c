#include<stdio.h>
#define SIZEN 21
#define MAX_SUM 201
int sum;
int n,w[SIZEN],m;
int Ans,half;
void readCase()
{
        n=0;
        char ch;
        while(2==scanf("%d%c",&w[n],&ch)){
            n++;
            if(ch!=' ')
                break;
	  	}
}
void solve(int i, int sum)
{
    if(sum==half)
    {
        Ans=1;
        return;
    }
    if(n==i)
        return;
    solve(i+1,sum);
    solve(i+1,sum+w[i]);

}
void solveCase()
{
    int i;
    sum=0;

    for(i=0;i<n;i++)
        sum+=w[i];
    Ans=0;
    if(sum%2)
        return;
    half=sum/2;
    solve(0,0);
}
void printCase()
{
    if(Ans)
        printf("YES\n");
    else
        printf("NO\n");
}
int main()
{
    int tc;
    freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    while(tc--)
    {
        readCase();
        solveCase();
        printCase();

    }
return 0;

}

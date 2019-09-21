#include<stdio.h>
#define SIZE 1000000000000000
#define SIZE2 100000
                                           // X = A*N + B*log(N) + C*N*N*N
 int a,b,c,Case;
long long int x,n,result,Ans,limit;

int Log(long long n)
{
	double d = (double)n;
	int value = 0;
	while (d >= 2.71828) {
		d /= 2.71828;
		value++;
	}
	return value;
}

void readCase()
{
    scanf("%d %d %d %lld",&a,&b,&c,&x);
}
long long int solve(long long int initiValue,long long int limit, long long int x )
{
    if(initiValue<=limit)
    {
        long long int mid=initiValue+(limit-initiValue)/2;
        long long int var=a*mid+b*Log(mid)+c*mid*mid*mid;
        if(x==var)
            return mid;
        if(var>x)
            return solve(initiValue,mid-1,x);
        return solve(mid+1,limit,x);
    }
    return -1;
}
int main()
{
    freopen("Equation_input.txt","r", stdin);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        readCase();
        if(c==0)
            Ans=solve(0,SIZE,x);
        else
            Ans=solve(0,SIZE2,x);

        printf("#%d: %lld\n",++Case,Ans);


    }

    return 0;
}

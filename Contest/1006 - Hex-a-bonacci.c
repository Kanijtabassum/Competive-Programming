#include<stdio.h>
long long int dp[10001];
long long int a, b, c, d, e, f;
long long int fn( long long int n ) {

    if( n == 0 ) return dp[n]=a;
    if( n == 1 ) return dp[n]=b;
    if( n == 2 ) return dp[n]=c;
    if( n == 3 ) return dp[n]=d;
    if( n == 4 ) return dp[n]=e;
    if( n == 5 ) return dp[n]=f;
    if(dp[n]!=-1)
        return dp[n];
    else
        return dp[n]=( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )%10000007;
}
int main() {
    freopen("h.txt","r",stdin);
   long long int n, caseno = 0, cases;
    int i,j;
    scanf("%lld", &cases);
    while( cases-- ) {
            for(i=0;i<10001;i++)
                 dp[i]=-1;
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}

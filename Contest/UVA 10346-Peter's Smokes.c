#include<stdio.h>
int main()
{
    int n,k;
    while((scanf("%d%d",&n,&k))==2)
    {
        int total=n, renew;
        while(n>=k)
        {
            renew=n/k;
            total+=renew;
            n=renew+(n%k);
        }
        printf("%d\n",total);
    }
    return 0;
}

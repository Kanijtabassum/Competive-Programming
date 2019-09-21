#include<stdio.h>
long long int h,op;
int main(){
    //freopen("h.txt","r",stdin);
    while(scanf("%lld%lld",&h,&op)!=EOF)
    {
        if(h>op)
        {
            printf("%lld\n",h-op);
        }
        else
            printf("%lld\n",op-h);
    }
    return 0;

}

#include<stdio.h>
int minConv(int h,int m)
{
    return h*60+m;
}
int main()
{
    int h1,m1,h2,m2;
    freopen("h.txt","r",stdin);
    while(1)
    {
        scanf("%d%d%d%d",&h1,&m1,&h2,&m2);
        if(0==(h1+m1) && 0==(h2+m2))
            break;
        int current=minConv(h1,m1);
        int alarm=minConv(h2,m2);
        if(current>alarm)
            alarm+=(24*60);
        printf("%d\n",alarm-current);
    }
    return 0;
}

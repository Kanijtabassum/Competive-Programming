#include<stdio.h>
int main()
{
    int n, t,x,count[2001],i;
    // freopen("h.txt","r",stdin);

        for(i=0;i<2001;i++)
        {
            count[i]=0;

        }
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            count[x]++;
        }

        for(i=1;i<2001;i++)
        {
            if(count[i]>0)
            {
                printf("%d aparece %d vez(es)\n",i,count[i]);
            }
        }

    return 0;
}

#include<stdio.h>
int T, m1,m2,m3,p1,p2,p3;
int Ans,max,min,cas;
int abs_diff(int i, int j)
{
    if(i>j)
        return i-j;
    else
        return j-i;
}
int isMax(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int isMin(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}
void solveCase()
{
    int i,j,k;
    int dist1, dist2,dist3,left, right;
    Ans=30;
    for(i=1;i+m1+m2+m3-1<=30;i++)
    {
        left=abs_diff(i,p1);
        right=abs_diff(p1, i+m1-1);
        dist1=isMax(left, right);

        for(j=i+m1;j+m2+m3-1<=30;j++)
        {
            left=abs_diff(j,p2);
            right=abs_diff(p2, j+m2-1);
            dist2=isMax(left, right);

            for(k=j+m2;k+m3-1<=30;k++)
            {
                left=abs_diff(k,p3);
                right=abs_diff(p3, k+m3-1);
                dist3=isMax(left, right);

                max=isMax(dist1,dist2);
                max=isMax(max,dist3);
                Ans=isMin(Ans,max);
            }

        }

    }
}
void readCase()
{
    scanf("%d %d",&p1,&m1);
    scanf("%d %d",&p2,&m2);
    scanf("%d %d",&p3,&m3);
}
int main()
{
    max=0;
    freopen("River_input .txt","r",stdin);
    scanf("%d",&T);

    while(T--)
    {
        max=-1111111;
        readCase();
        solveCase();
        printf("#%d : %d\n",++cas,Ans);
    }

    return 0;
}

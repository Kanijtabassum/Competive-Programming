#include<stdio.h>
#include<iostream>
#define MAX 11
using namespace std;
int mat[MAX][MAX],color[MAX][MAX];
int main()
{
    int n,i,j,sum ,cas=0;
    int left, right;
    freopen("h.txt","r",stdin);
    while(scanf("%d",&n)&&n)
    {
        cas++;

        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",&mat[i][j]);
                color[i][j]=0;
            }
        }
        printf("Case %d:",cas);
        sum =0;
        left=0;
        right=n-1;
        while(left<=right)
        {

            for(i=0;i<n;i++)
            {
                for(j=0; j<n; j++)
                {
                    if((i==left || j==left || i==right || j==right) &&color[i][j]==0)
                    {

                        sum+=mat[i][j];
                        color[i][j]=1;
                    }
                }
            }

            printf(" %d",sum);

            sum=0;
            left++;
            right--;

        }
        printf("\n");

    }

    return 0;

}

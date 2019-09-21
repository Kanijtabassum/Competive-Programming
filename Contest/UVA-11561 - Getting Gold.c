#include<stdio.h>
#define SIZEN 55
int W,H;
int X,Y;
char Grid[SIZEN][SIZEN];
int visited[SIZEN][SIZEN],Ans;

void fill(int i,int j)
{
    if(i<=0 || j<=0 || i>H || j>W )
        return;
    if('G'==Grid[i][j])
        Ans++;

    visited[i][j]=1;

     if('T'==Grid[i-1][j])
       return;
    if('T'==Grid[i+1][j])
       return;
     if('T'==Grid[i][j-1])
       return;
    if('T'==Grid[i][j+1])
       return;


    if(('.'== Grid[i-1][j] || 'G'==Grid[i-1][j]) && 0==visited[i-1][j])
        fill(i-1,j);
    if(('.'== Grid[i+1][j] || 'G'==Grid[i+1][j])  && 0==visited[i+1][j])
        fill(i+1,j);
    if(('.'== Grid[i][j-1] || 'G'==Grid[i][j-1])  && 0==visited[i][j-1])
        fill(i,j-1);
    if(('.'== Grid[i][j+1] || 'G'==Grid[i][j+1]) && 0==visited[i][j+1])
        fill(i,j+1);



}
int main()
{
    freopen("h.txt","r",stdin);
     freopen("o.txt","w",stdout);
    while(2==scanf("%d%d",&W,&H))
    {
        Ans=0;
        int i, j;
        for(i=0;i<H;i++){
            scanf("%s",Grid[i]);
           // printf("%s\n",Grid[i]);

        }
        for(i=0;i<H;i++){
            for(j=0;j<W;j++){
                if('P'==Grid[i][j])
                {
                    X=i;
                    Y=j;
                }
                visited[i][j]=0;

            }
        }


        fill(X,Y);

        printf("%d\n",Ans);

    }
    return 0;
}

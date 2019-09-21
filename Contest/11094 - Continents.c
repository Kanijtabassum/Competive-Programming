#include<stdio.h>
#define SIZEN 22
int M,N;
int X,Y;
char Grid[SIZEN][SIZEN];
int visited[SIZEN][SIZEN],Ans;

void fill(int i,int j)
{
    if(i<=0 || j<=0 || i>M || j>N )
        return;
        if('l'==Grid[i][j])
            Ans++;
        visited[i][j]=1;
    if(('w'== Grid[i][j-1] || 'l'==Grid[i][j-1]) && 0==visited[i][j-1])
        fill(i,j-1);
   if(('w'== Grid[i][j+1] || 'l'==Grid[i][j+1]) && 0==visited[i][j+1])
        fill(i,j+1);





}
int main()
{
    freopen("h.txt","r",stdin);
     //freopen("o.txt","w",stdout);
    while(2==scanf("%d%d",&M,&N))
    {
        Ans=0;
        int i, j;
        for(i=0;i<M;i++){
            scanf("%s",Grid[i]);
           // printf("%s\n",Grid[i]);

        }
        scanf("%d%d",&X,&Y);

        for(i=0;i<M;i++){
            for(j=0;j<N;j++){

                visited[i][j]=0;

            }
        }

        fill(X,Y);

        for(i=0;i<M;i++){
            for(j=0;j<N;j++){

                fill(i,j);

            }
        }

        printf("%d\n",Ans);

    }
    return 0;
}


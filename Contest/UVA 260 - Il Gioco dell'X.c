#include<stdio.h>
int N;
#define SIZEN 201
char A[SIZEN][SIZEN];
int visited[SIZEN][SIZEN];
int win=1,count;
void printCase()
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%s\n",A[i]);
    }
    printf("\n");
}
void fill(int x, int y)
{
    if(y==N-1)
    {
        count=2;
        return;
    }
    visited[x][y]=1;
    if (x - 1 >= 0 && y - 1 >= 0 && 0==visited[x - 1][y-1] && 'w' == A[x - 1][y - 1])
		fill(x - 1, y - 1);
	if (x - 1 >= 0 && 0==visited[x - 1][y] && 'w' == A[x - 1][y])
		fill(x - 1, y);
	if (y - 1>=0  && 0==visited[x][y-1] &&'w' == A[x][y - 1])
		fill(x, y-1);
	if (y + 1<N && 0==visited[x][y+1] && 'w' ==A[x][y + 1])
		fill(x, y+1);
	if (x + 1 < N  && 0==visited[x + 1][y] &&'w' == A[x + 1][y])
		fill(x + 1, y);
	if (x + 1 < N && y + 1 <N && 0==visited[x + 1][y+1] && 'w' == A[x + 1][y + 1])
		fill(x + 1, y+1);
}
int main()
{
    int i,j;
    freopen("h.txt","r",stdin);
    freopen("o.txt","w",stdout);
    while(1==scanf("%d",&N))
    {
        count=1;
        if(N==0)
            break;
        for(i=0;i<N;i++)
        {
            scanf("%s",A[i]);
        }
        for(i=0;i<SIZEN;i++)
        {
            for(j=0;j<SIZEN;j++)
                visited[i][j]=0;
        }


        for(i=0;i<N;i++)
        {

                fill(i,0);
                if(count==2)
                    break;
        }
        if(count==1)
            printf("%d B\n",win);
        else
            printf("%d W\n",win);

        win++;
    }
    return 0;
}

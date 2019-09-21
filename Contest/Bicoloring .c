#include<stdio.h>
#define SIZEN 202
int path[SIZEN][SIZEN];
int color[SIZEN];
int N,l,Ans;

void readCase()
{
    int i,j;
    int x,y;
    scanf("%d",&l);
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            path[i][j]=0;
    }

    while(l--)
    {
        scanf("%d%d",&x,&y);
        path[x][y]=path[y][x]=1;
    }
}
void fill(int x, int current_col)
{
    int y;
    color[x] = current_col;
    for(y=0;y<N;y++)if(1== path[x][y])
    {

            if(0==color[y])
            {
                fill(y,3-current_col);
            }
            else if(color[y]==current_col)
            {
                Ans=0;
            }
    }
}

void solveCase()
{
    int i;
    Ans=1;
    for(i=0;i<N;i++)
    {
        color[i]=0;
    }
    for(i=0;i<N;i++)
    {
        if(0==color[i])
            fill(i,1);
    }
}
void PrintCase()
{
    if(Ans)
        printf("BICOLORABLE.\n");
    else
        printf("NOT BICOLORABLE.\n");
}
int main()
{
    freopen("h.txt","r",stdin);
    while(1==scanf("%d",&N)&& N)
    {
        Ans=0;
        readCase();
        solveCase();
        PrintCase();
    }
    return 0;
}

#include<stdio.h>
char Grid[100][100];
int visited[100][100];
int N=5,M=12,pxl;
void floodfill(int i, int j,int ch)
{

    if(i<0 || j<0 || i>=N || j>=M)
    {
            return;
    }



        if(ch==Grid[i][j] && !visited[i][j])
        {

      //  printf("Hi\n");
             visited[i][j]=1;
              pxl++;
            floodfill(i-1,j-1,ch);
            floodfill(i-1,j,ch);
            floodfill(i-1,j+1,ch);
            floodfill(i,j-1,ch);
            floodfill(i,j+1,ch);
            floodfill(i+1,j-1,ch);
            floodfill(i+1,j,ch);
            floodfill(i+1,j+1,ch);
        }

}

int main()
{
    freopen("h.txt","r",stdin);
    int i,j;
    for(i=0;i<N;i++){
            scanf("%s",Grid[i]);
            printf("%s\n",Grid[i]);
    }
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            visited[i][j]=0;
        }
    }
    pxl=0;
    int cnt=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if('R'==Grid[i][j] && 0==visited[i][j])
            {
                cnt++;
                floodfill(i,j,'R');

            }
        }
    }

    printf("R - %d region %d pixel\n",cnt,pxl);
    pxl=0;
    cnt=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if('G'==Grid[i][j] && 0==visited[i][j])
            {
                cnt++;
                floodfill(i,j,'G');

            }
        }
    }

    printf("G - %d region %d pixel\n",cnt,pxl);
    pxl=0;
    cnt=0;
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if('B'==Grid[i][j] && 0==visited[i][j])
            {
                cnt++;
                floodfill(i,j,'B');

            }
        }
    }

    printf("B - %d region %d pixel\n",cnt,pxl);

    return 0;
}

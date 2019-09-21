#include<stdio.h>
#define SIZEN 50

char Grid[SIZEN][SIZEN];
int T,Count,Max,len;
void readCase()
{
    int i,j;
    for(i=0;i<SIZEN;i++)
        for(j=0;j<SIZEN;j++)
            Grid[i][j]='\0';
    i=0;

    while(gets(Grid[i]))
    {
            if(Grid[i][0]=='\0')
                break;
            i++;
    }
    len=i;
    Max=0;

}
void dfs(int i,int j)
{

    if(i<0 ||j<0 || i>=len || Grid[i][j]=='\0')
        return;

    if(Grid[i][j]=='0')
        return;

    else
    {
        Grid[i][j]='0';
        Count++;


        dfs(i-1,j);
        dfs(i-1,j+1);
        dfs(i,j+1);
        dfs(i+1,j+1);
        dfs(i+1,j);
        dfs(i+1,j-1);
        dfs(i,j-1);
        dfs(i-1,j-1);

    }
}
void solveCase()
{
    int i,j;
    Max=0;
    for(i=0;i<len;i++)
    {
        for(j=0;Grid[i][j]!='\0';j++){

            if('1'==Grid[i][j]){
                Count=0;
                dfs(i,j);
                if(Max<Count)
                    Max=Count;
            }
        }
    }

}
void printCase()
{

    printf("%d\n",Max);
}
int main()
{

    int i;
    freopen("h.txt","r",stdin);

    scanf("%d",&T);
    getchar();
    getchar();
    for(i=1;i<=T;i++){
            if(i!=1)
                printf("\n");
        readCase();
        solveCase();
        printCase();
    }
    return 0;
}

#include<stdio.h>

#define SIZEN 1002

int T,N,M,X,Y,L,Ans;
int Grid[SIZEN][SIZEN];
int visited[SIZEN][SIZEN];
typedef struct queueStruct{
    int x,y,len;

}Queue;

int front,rear;
Queue Q[SIZEN*SIZEN];

int isEmpty()
{
    return (rear==front);
}

void QueInti()
{
    rear=front=0;
}
void push(int x, int y, int l)
{
    Q[rear].x=x;
    Q[rear].y=y;
    Q[rear].len=l;
    rear++;
}
Queue pop()
{
    return Q[front++];
}
int isUp(int n)
{
    switch(n){

    case 1:
    case 2:
    case 4:
    case 7:
        return 1;
    }
    return 0;
}
int isDown(int n)
{
    switch(n){

    case 1:
    case 2:
    case 5:
    case 6:
        return 1;
    }
    return 0;
}
int isLeft(int n)
{
    switch(n){

    case 1:
    case 3:
    case 6:
    case 7:
        return 1;
    }
    return 0;
}

int isRight(int n)
{
    switch(n){

    case 1:
    case 3:
    case 5:
    case 4:
        return 1;
    }
    return 0;
}
int main()
{
    freopen("anuragEndo.txt", "r", stdin);
    scanf("%d",&T);
    while(T--)
    {
        Ans=0;
        scanf("%d %d %d %d %d",&N,&M,&X,&Y,&L);
    int i,j;
    Queue q;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            scanf("%d",&Grid[i][j]);
            if(Grid[i][j])
                visited[i][j]=0;
            else
                visited[i][j]=1;
        }
    }

    if(Grid[X][Y])
    {
        push(X,Y,1);
        visited[X][Y]=1;
        Ans++;
    }
    while(!isEmpty())
    {

        q=pop();
        if(q.len<L)
        {
            if(q.x-1>=0 && (0==visited[q.x-1][q.y]) && isDown(Grid[q.x-1][q.y]) && isUp(Grid[q.x][q.y]))
            {
                push(q.x-1, q.y,q.len+1);
                visited[q.x-1][q.y]=1;
                Ans++;
            }

             if(q.x+1<N && (0==visited[q.x+1][q.y]) && isUp(Grid[q.x+1][q.y]) && isDown(Grid[q.x][q.y]))
            {
                push(q.x+1, q.y,q.len+1);
                visited[q.x+1][q.y]=1;
                Ans++;
            }
             if(q.y-1>=0 && (0==visited[q.x][q.y-1]) && isRight(Grid[q.x][q.y-1]) && isLeft(Grid[q.x][q.y]))
            {
                push(q.x, q.y-1,q.len+1);
                visited[q.x][q.y-1]=1;
                Ans++;
            }
             if(q.y+1<M && (0==visited[q.x][q.y+1]) && isLeft(Grid[q.x][q.y+1]) && isRight(Grid[q.x][q.y]))
            {
                push(q.x, q.y+1,q.len+1);
                visited[q.x][q.y+1]=1;
                Ans++;
            }
        }
    }
        printf("%d\n",Ans);
    }
    return 0;
}

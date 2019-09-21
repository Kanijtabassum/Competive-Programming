/*
#include <stdio.h>
int N,M;
int A[11][11];
int visited[11][11];
int dfs(int x, int y)
{
    if(x==N && y==M)
     return 1;
    if(x<1 || y<1)
        return 0;
    if(x>N || y>M)
     return 0;
    if(visited[x][y]==1)
        return 0;
    if(A[x][y]==0)
     return 0;

    visited[x][y]=1;
    if(dfs(x-1,y)==1)
        return 1;
    if(dfs(x,y-1)==1)
        return 1;
    if(dfs(x,y+1)==1)
        return 1;
    if(dfs(x+1,y)==1)
        return 1;
    return 0;

}
int main(){
	int i,j;
	freopen("h.txt","r",stdin);
	scanf("%d%d",&N,&M);
	for(i=1;i<=N;i++)
	{
	    for(j=1;j<=M;j++)
	    {

	        scanf("%d",&A[i][j]);
	    }
	}// Reading input from STDIN
	      // Writing output to STDOUT


	if(dfs(1,1))
	    printf("Yes");
	else
    	printf("No");


    return 0;

}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

#include <iostream>
using namespace std;
int N,M;
int A[11][11];
int visited[11][11];
int dfs(int x, int y)
{
    if(x==N && y==M)
     return 1;
    if(x<1 || y<1)
        return 0;
    if(x>N || y>M)
     return 0;
    if(visited[x][y]==1)
        return 0;
    if(A[x][y]==0)
     return 0;

    visited[x][y]=1;
    if(dfs(x-1,y))
        return 1;
    if(dfs(x,y-1))
        return 1;
    if(dfs(x,y+1))
        return 1;
    if(dfs(x+1,y))
        return 1;
    return 0;

}
int main(){
	int i,j;
	freopen("h.txt","r",stdin);
	cin>>N>>M;
	for(i=1;i<=N;i++)
	{
	    for(j=1;j<=M;j++)
	    {

	        cin>>A[i][j];
	    }
	}// Reading input from STDIN
	      // Writing output to STDOUT


	if(dfs(1,1))
	    cout>>"Yes">>endl;
	else
    	cout>>"No">>endl;


    return 0;

}

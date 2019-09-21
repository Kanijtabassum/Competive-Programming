#include<iostream>
using namespace std;
int visited[11][11];
int mat[11][11],n,m;

int DFS(int x,int y)
{
if(x==n&&y==m)
return 1;
if(x>n||y>m)
return 0;
if(x<1||y<1)
return 0;
if(visited[x][y]==1)
return 0;
if(mat[x][y]==0)
return 0;
visited[x][y]=1;
if(DFS(x+1,y))
return 1;
if(DFS(x-1,y))
return 1;
if(DFS(x,y+1))
return 1;
if(DFS(x,y-1))
return 1;
return 0;
}
int main()
{
cin >> n >> m;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=m;j++)
cin >> mat[i][j];
}
if(DFS(1,1))
cout << "Yes";
else
cout << "No";

return 0;
}

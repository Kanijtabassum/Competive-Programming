#include<stdio.h>
#define SIZE 21

int Grid[SIZE][SIZE];
int Visited[SIZE];
int T, Case=0;
int M, N;
int flag;

void readcase(){
	int x, y;
	scanf("%d %d", &N, &M);
	for (x = 1; x <= N; x++){
		for (y = 1; y <= N; y++){
			Grid[x][y] = 0;
		}
	}
	while (M--)
	{
		scanf("%d %d", &x, &y);
		Grid[x][y] = 1;
	}

}

int fill(int src, int cur){
	int i;
	Visited[cur] = 1;
	for (i = 1; i <= N;i++)
		if (Grid[cur][i]){
			if (0 == Visited[i]){
				if (1 == fill(src, i))
					return 1;
			}
			else if (i == src)
				return 1;
		}
	Visited[cur] = 0;
	return 0;
}

void solvecase(){
	int i;
	flag = 0;
	for (i = 1; i <= N; i++)
		Visited[i] = 0;
	for (i = 1; i <= N; i++){
		if (0 == Visited[i]){
			if (1 == fill(i, i)){
				flag = 1;
				break;
			}
		}
	}
}

void printcase(){
	int i;
	printf("#%d", ++Case);
	if (1 == flag){
		for (i = 1; i <= N; i++) if (1 == Visited[i])
			printf(" %d", i);
		printf("\n");
	}
	else
		printf(" -1\n");
}

int main(){
	freopen("CycleInput.txt", "r", stdin);
	scanf("%d", &T);
	while (T--){
		readcase();
		solvecase();
		printcase();
	}
	return 0;
}

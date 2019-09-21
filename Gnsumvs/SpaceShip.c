#include<stdio.h>

int Case;
int N;
int Board[101][6];
int MAX;

void readcase(){
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) for (j = 0; j < 5; j++)
		scanf("%d", &Board[i][j]);
}

void go(int row, int col, int life, int score){
	if (row < 0){
		if (score > MAX)
			MAX = score;
		return;
	}
	if (life > 0 && life < 6)
		life--;
	if (1 == Board[row][col])
		score++;
	else if (2 == Board[row][col]){
		if (0 == life){
			if (score > MAX)
				MAX = score;
			return;
		}
		else if (6 == life)
			life--;
	}
	if (col - 1 >= 0)
		go(row - 1, col - 1, life, score);
	go(row - 1, col, life, score);
	if (col + 1 < 6)
		go(row - 1, col + 1, life, score);
}

void solvecase(){
	MAX = 0;
	go(N - 1, 1, 6, 0);
	go(N - 1, 2, 6, 0);
	go(N - 1, 3, 6, 0);
}

void printcase(){
	printf("#%d %d\n", Case, MAX);
}

int main(){
	int T;
	freopen("c.txt", "r", stdin);
	scanf("%d", &T);
	for (Case = 1; Case <= T; Case++){
		readcase();
		solvecase();
		printcase();
	}
	return 0;
}

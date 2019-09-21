#include<stdio.h>
#define SIZEN 103


int main()
{
	int n, m;
	char Grid[SIZEN][SIZEN];
	freopen("h.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	while (2==scanf("%d%d", &n, &m))
	{
		int i, j, count = 0;
		char Grid[SIZEN][SIZEN] = { 0 };
		if (n == 0 && m == 0)
			break;
		for (i = 0; i < n; i++)
		{

				scanf("%s", Grid[i]);
		}
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<m; j++)
				if (Grid[i][j] == '*')
				{
					if (Grid[i - 1][j - 1] != '*'&& Grid[i - 1][j] != '*'&& Grid[i - 1][j + 1] != '*'&&
                        Grid[i][j - 1] != '*'&& Grid[i][j + 1] != '*'&& Grid[i + 1][j - 1] != '*'&&
                        Grid[i + 1][j] != '*'&& Grid[i + 1][j + 1] != '*')

						count++;
				}
		}
		printf("%d\n", count);
	}
	return 0;
}

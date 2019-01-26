#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> field =
{
	{'W','.','.','.','.','.','.','.','.','W','W','.'},
	{'.','W','W','W','.','.','.','.','.','W','W','W'},
	{'.','.','.','.','W','W','.','.','.','W','W','.'},
	{'.','.','.','.','.','.','.','.','.','W','W','.'},
	{'.','.','.','.','.','.','.','.','.','W','.','.'},
	{'.','.','W','.','.','.','.','.','.','W','.','.'},
	{'.','W','.','W','.','.','.','.','.','W','W','.'},
	{'W','.','W','.','W','.','.','.','.','.','W','.'},
	{'.','W','.','W','.','.','.','.','.','.','W','.'},
	{'.','.','W','.','.','.','.','.','.','.','W','.'}
};
int N = field.size();
int M = field[0].size();

void DFS(int x, int y)
{
	field[x][y] = '.';

	for (int dx = -1; dx <= 1; ++dx)
		for (int dy = -1; dy <= 1; ++dy)
		{
			int nx = x + dx;
			int ny = y + dy;

			if (0 <= nx && nx < N && 0 <= ny && ny < M && field[nx][ny] == 'W')
				DFS(nx, ny);
		}
}

void Solve()
{
	int ans = 0;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			if (field[i][j] == 'W')
			{
				DFS(i, j);
				++ans;
			}
		}
	cout << ans << endl;
}

int main()
{
	Solve();
	return 0;
}
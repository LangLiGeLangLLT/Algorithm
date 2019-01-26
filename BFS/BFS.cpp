#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int MAX_INF = 0x7fffffff;
const int MAX_N = 101;

typedef pair<int, int> P;

vector<vector<char>> maze =
{
	{'#','S','#','#','#','#','#','#','.','#'},
	{'.','.','.','.','.','.','#','.','.','#'},
	{'.','#','.','#','#','.','#','#','.','#'},
	{'.','#','.','.','.','.','.','.','.','.'},
	{'#','#','.','#','#','.','#','#','#','#'},
	{'.','.','.','.','#','.','.','.','.','#'},
	{'.','#','#','#','#','#','#','#','.','#'},
	{'.','.','.','.','#','.','.','.','.','.'},
	{'.','#','#','#','#','.','#','#','#','.'},
	{'.','.','.','.','#','.','.','.','G','#'},
};
int N = maze.size();
int M = maze[0].size();
int sx, sy;
int gx, gy;
int d[MAX_N][MAX_N];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void Init()
{
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
		{
			if (maze[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
			else if (maze[i][j] == 'G')
			{
				gx = i;
				gy = j;
			}
			d[i][j] = MAX_INF;
		}
}

int BFS()
{
	queue<P> que;
	que.push(P(sx, sy));
	d[sx][sy] = 0;

	while (que.size())
	{
		P p = que.front();
		que.pop();

		if (p.first == gx && p.second == gy)
			break;

		for (int i = 0; i < 4; ++i)
		{
			int nx = p.first + dx[i];
			int ny = p.second + dy[i];

			if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == MAX_INF)
			{
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	return d[gx][gy];
}

void Solve()
{
	cout << BFS() << endl;
}

int main()
{
	Init();
	Solve();
	return 0;
}
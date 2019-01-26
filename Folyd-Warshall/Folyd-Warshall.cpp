/*
	多源最短路问题 (Floyd-Warshall 算法)

	图：

	A——[2]——B——[10]——E
	|     / |        |  [5]
	[5][4] [6]      [3]      G
	| /     |        |  [9]
	C——[2]——D——[1]—— F

	邻接矩阵：

		[j]	[0]	[1]	[2]	[3]	[4]	[5]	[6]
	[i]		 A	 B	 C	 D	 E	 F	 G
	[0]	 A	 0	 2	 5	 ∞	 ∞	 ∞	 ∞
	[1]	 B	 2	 0	 4	 6	 10	 ∞	 ∞
	[2]	 C	 5	 4	 0	 2	 ∞	 ∞	 ∞
	[3]	 D	 ∞	 6	 2	 0	 ∞	 1	 ∞
	[4]	 E	 ∞	 10	 ∞ 	 ∞	 0 	 3	 5
	[5]	 F	 ∞	 ∞	 ∞	 1	 3	 0	 9
	[6]	 G	 ∞	 ∞	 ∞	 ∞	 5	 9	 0

	邻接表：

	[0]: A ——> [1] B (2), [2] C (5)
	[1]: B ——> [0] A (2), [2] C (4), [3] D (6), [4] E (10)
	[2]: C ——> [0] A (5), [1] B (4), [3] D (2)
	[3]: D ——> [1] B (6), [2] C (2), [5] F (1)
	[4]: E ——> [1] B (10), [5] F (3), [6] G (5)
	[5]: F ——> [3] D (1), [4] E (3), [6] G (9)
	[6]: G ——> [4] E (5), [5] F (9)

	输入样例：
	7 10
	0 1 2
	0 2 5
	1 2 4
	1 3 6
	1 4 10
	2 3 2
	3 5 1
	4 5 3
	4 6 5
	5 6 9
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_V = 100;
const int INF = 10000;

int d[MAX_V][MAX_V]; // d[u][v] 表示边 e = (u, v) 的权值 (不存在时设为 INF, 不过 d[i][i] = 0)
int V, E;

void Init()
{
	cin >> V >> E;
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
		{
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
		}
	
	for (int i = 0; i < E; ++i)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		d[from][to] = cost;
		d[to][from] = cost; // 无向图
	}
}

void Floyd()
{
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

void Solve()
{
	// 求从 A 到 G 的最短距离
	// A -> C -> D -> F -> E -> G 共 16
	Floyd();
	cout << d['A' - 'A']['G' - 'A'] << endl;
}

int main()
{
	Init();
	Solve();
	return 0;
}
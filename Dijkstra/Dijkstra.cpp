/*
	单源最短路问题 2 (Dijkstra 算法)

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

int cost[MAX_V][MAX_V]; // cost[u][v] 表示边 e = (u, V) 的权值 (不存在这天边时设为 INF)
int d[MAX_V];			// 顶点 s 出发的最短距离
bool used[MAX_V];		// 已经使用过的图
int V, E;

void Init()
{
	cin >> V >> E;
	for (int i = 0; i < V; ++i)
		for (int j = 0; j < V; ++j)
		{
			if (i == j)
				cost[i][j] = 0;
			else
				cost[i][j] = INF;
		}

	for (int i = 0; i < E; ++i)
	{
		int f, t, c; // from, to, cost
		cin >> f >> t >> c;
		cost[f][t] = c;
		cost[t][f] = c; // 无向图
	}
}

// 求从起点 s 出发到各个顶点的最短距离
void Dijkstra(int s)
{
	fill(d, d + V, INF);
	fill(used, used + V, false);
	d[s] = 0;

	while (true)
	{
		int v = -1;
		// 从尚未使用过的顶点中选择一个距离最小的顶点
		for (int u = 0; u < V; ++u)
			if (!used[u] && (v == -1 || d[u] < d[v]))
				v = u;

		if (v == -1)
			break;
		used[v] = true;

		for (int u = 0; u < V; ++u)
			d[u] = min(d[u], d[v] + cost[v][u]);
	}
}

void Solve()
{
	// 求从 A 到 G 的最短距离
	// A -> C -> D -> F -> E -> G 共 16
	Dijkstra('A' - 'A');
	cout << d['G' - 'A'] << endl;
}

int main()
{
	Init();
	Solve();
	return 0;
}
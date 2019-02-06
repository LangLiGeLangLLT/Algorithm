/*
	最小生成树问题 (Prim 算法)

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

int cost[MAX_V][MAX_V]; // cost[u][v] 表示边 e = (u, v)的权值 (不存在的情况下设为 INF)
int mincost[MAX_V];		// 从集合 X 出发的边到每个顶点的最小权值
bool used[MAX_V];		// 顶点 i 是否包含在集合 X 中
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
		cost[t][f] = c;
	}
}

int Prim()
{
	for (int i = 0; i < V; ++i)
	{
		mincost[i] = INF;
		used[i] = false;
	}
	mincost[0] = 0;
	int res = 0;

	while (true)
	{
		int v = -1;
		// 从不属于 X 的顶点中选取从 X 到其权值最小的顶点
		for (int u = 0; u < V; ++u)
			if (!used[u] && (v == -1 || mincost[u] < mincost[v]))
				v = u;

		if (v == -1)
			break;
		used[v] = true;		// 把顶点 v 加入 X
		res += mincost[v];	// 把边的长度加到结果里

		for (int u = 0; u < V; ++u)
			mincost[u] = min(mincost[u], cost[v][u]);
	}

	return res;
}

void Solve()
{
	cout << Prim() << endl;
}

int main()
{
	Init();
	Solve();
	return 0;
}

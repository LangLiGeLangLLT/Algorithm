/*
	最短路径还原问题 (Dijkstra 算法为例)

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
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

struct Edge
{
	int to, cost;

	Edge() {}
	Edge(int to, int cost) :to(to), cost(cost) {}
};

typedef pair<int, int> P; // first 是最短距离，second 是顶点的编号

const int MAX_V = 100;
const int INF = 10000;

vector<Edge> G[MAX_V];
int d[MAX_V];
int pre_v[MAX_V]; // 最短路上的前趋顶点
int V, E;

void Init()
{
	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		G[from].push_back(Edge(to, cost));
		G[to].push_back(Edge(from, cost)); // 无向图
	}
}

void Dijkstra(int s)
{
	priority_queue<P, vector<P>, greater<P>> que;
	fill(d, d + V, INF);
	fill(pre_v, pre_v + V, -1);
	d[s] = 0;
	que.push(P(d[s], s));

	while (que.size())
	{
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) // 当取出的最小值不是最短距离的话，就丢弃这个值。
			continue;

		for (int i = 0; i < G[v].size(); ++i)
		{
			Edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost)
			{
				d[e.to] = d[v] + e.cost;
				pre_v[e.to] = v;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

vector<int> GetPath(int t)
{
	vector<int> path;
	for (; t != -1; t = pre_v[t]) // 不断沿着 pre_v[t] 走直到 t = s
		path.push_back(t);

	// 这样得到的是按照 t 到 s 的顺序，所以翻转之
	reverse(path.begin(), path.end());
	return path;
}

void Solve()
{
	// 求从 A 到 G 的最短距离
	// A -> C -> D -> F -> E -> G 共 16
	Dijkstra('A' - 'A');
	vector<int> shortest_path = GetPath('G' - 'A'); // 源点由 Dijkstra 决定

	cout << d['G' - 'A'] << endl;
	for (int i = 0; i < shortest_path.size(); ++i)
		cout << char(shortest_path[i] + 'A') << " ";
}

int main()
{
	Init();
	Solve();
	return 0;
}
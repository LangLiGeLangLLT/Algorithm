/*
	单源最短路问题 1 (Bellman-Ford 算法)

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
#include <cstring>

using namespace std;

// 从顶点 from 指向 to 的权值为 cost 的边
struct Edge
{
	int from, to, cost;

	Edge() {}
	Edge(int from, int to, int cost) :from(from), to(to), cost(cost) {}
};

const int MAX_E = 100;
const int MAX_V = 100;
const int INF = 10000;

Edge es[MAX_E];	// 边
int d[MAX_V];	// 最短距离
int V, E;		// V 是顶点数，E 是边数

void Init()
{
	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		// 从 from 向 to 连边
		int from, to, cost;
		cin >> from >> to >> cost;
		es[i] = Edge(from, to, cost);
		es[i + E] = Edge(to, from, cost); // 如果是无向图，则需要再从 to 向 from 连边
	}
}

// 求解从顶点 s 出发到所有点的最短距离
void ShortestPath(int s)
{
	for (int i = 0; i < V; ++i)
		d[i] = INF;
	d[s] = 0;

	while (true)
	{
		bool update = false;
		for (int i = 0; i < 2 * E; ++i) // 因为此图是无向图，需要 2 * E，否则为 E
		{
			Edge e = es[i];
			if (d[e.from] != INF && d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;
				update = true;
			}
		}
		if (!update)
			break;
	}
}

// 如果返回 true 则存在负圈 (负圈: 存在权为负数的边)
bool FindNegativeLoop()
{
	memset(d, 0, sizeof(d));

	for (int i = 0; i < V; ++i)
		for (int j = 0; j < 2 * E; ++j) // 因为此图是无向图，需要 2 * E，否则为 E
		{
			Edge e = es[j];
			if (d[e.to] > d[e.from] + e.cost)
			{
				d[e.to] = d[e.from] + e.cost;

				// 如果第 V 次仍然更新了，则存在负圈
				if (i == V - 1)
					return true;
			}
		}
	return false;
}

void Solve()
{
	// 求从 A 到 G 的最短距离
	// A -> C -> D -> F -> E -> G 共 16
	ShortestPath('A' - 'A');
	cout << d['G' - 'A'] << endl;
	
	// 判断是否存在负圈
	cout << boolalpha << FindNegativeLoop() << noboolalpha << endl;
}

int main()
{
	Init();
	Solve();
	return 0;
}
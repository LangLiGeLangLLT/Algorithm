#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int from, to, cost;

	Edge() {}
	Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}

	bool operator<(const Edge& e)
	{
		return cost < e.cost;
	}
};

const int MAX_N = 5000 + 5;

int V, E;
vector<Edge> es;
int par[MAX_N];

// 查询树根
int find(int x)
{
	return par[x] == x ? x : par[x] = find(par[x]);
}

void Init()
{
	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		es.push_back(Edge(from, to, cost));
		es.push_back(Edge(to, from, cost));
	}
}

void Kruskal()
{
	for (int i = 0; i <= V; ++i)
		par[i] = i;

	sort(es.begin(), es.end());

	int ans = 0;
	int cnt = 0;
	for (Edge e : es)
	{
		int x = e.from;
		int y = e.to;
		if (find(x) == find(y))
			continue;

		++cnt;
		ans += e.cost;
		par[find(x)] = find(y);
	}

	if (cnt == V - 1)
		cout << ans << endl;
	else
		cout << "图不连通" << endl;
}

int main()
{
	Init();
	Kruskal();
	return 0;
}
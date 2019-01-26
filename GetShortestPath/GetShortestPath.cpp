/*
	���·����ԭ���� (Dijkstra �㷨Ϊ��)

	ͼ��

	A����[2]����B����[10]����E
	|     / |        |  [5]
	[5][4] [6]      [3]      G
	| /     |        |  [9]
	C����[2]����D����[1]���� F

	�ڽӾ���

		[j]	[0]	[1]	[2]	[3]	[4]	[5]	[6]
	[i]		 A	 B	 C	 D	 E	 F	 G
	[0]	 A	 0	 2	 5	 ��	 ��	 ��	 ��
	[1]	 B	 2	 0	 4	 6	 10	 ��	 ��
	[2]	 C	 5	 4	 0	 2	 ��	 ��	 ��
	[3]	 D	 ��	 6	 2	 0	 ��	 1	 ��
	[4]	 E	 ��	 10	 �� 	 ��	 0 	 3	 5
	[5]	 F	 ��	 ��	 ��	 1	 3	 0	 9
	[6]	 G	 ��	 ��	 ��	 ��	 5	 9	 0

	�ڽӱ�

	[0]: A ����> [1] B (2), [2] C (5)
	[1]: B ����> [0] A (2), [2] C (4), [3] D (6), [4] E (10)
	[2]: C ����> [0] A (5), [1] B (4), [3] D (2)
	[3]: D ����> [1] B (6), [2] C (2), [5] F (1)
	[4]: E ����> [1] B (10), [5] F (3), [6] G (5)
	[5]: F ����> [3] D (1), [4] E (3), [6] G (9)
	[6]: G ����> [4] E (5), [5] F (9)

	����������
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

typedef pair<int, int> P; // first ����̾��룬second �Ƕ���ı��

const int MAX_V = 100;
const int INF = 10000;

vector<Edge> G[MAX_V];
int d[MAX_V];
int pre_v[MAX_V]; // ���·�ϵ�ǰ������
int V, E;

void Init()
{
	cin >> V >> E;
	for (int i = 0; i < E; ++i)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		G[from].push_back(Edge(to, cost));
		G[to].push_back(Edge(from, cost)); // ����ͼ
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
		if (d[v] < p.first) // ��ȡ������Сֵ������̾���Ļ����Ͷ������ֵ��
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
	for (; t != -1; t = pre_v[t]) // �������� pre_v[t] ��ֱ�� t = s
		path.push_back(t);

	// �����õ����ǰ��� t �� s ��˳�����Է�ת֮
	reverse(path.begin(), path.end());
	return path;
}

void Solve()
{
	// ��� A �� G ����̾���
	// A -> C -> D -> F -> E -> G �� 16
	Dijkstra('A' - 'A');
	vector<int> shortest_path = GetPath('G' - 'A'); // Դ���� Dijkstra ����

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
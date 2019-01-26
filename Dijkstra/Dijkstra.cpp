/*
	��Դ���·���� 2 (Dijkstra �㷨)

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
#include <algorithm>

using namespace std;

const int MAX_V = 100;
const int INF = 10000;

int cost[MAX_V][MAX_V]; // cost[u][v] ��ʾ�� e = (u, V) ��Ȩֵ (�����������ʱ��Ϊ INF)
int d[MAX_V];			// ���� s ��������̾���
bool used[MAX_V];		// �Ѿ�ʹ�ù���ͼ
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
		cost[t][f] = c; // ����ͼ
	}
}

// ������ s �����������������̾���
void Dijkstra(int s)
{
	fill(d, d + V, INF);
	fill(used, used + V, false);
	d[s] = 0;

	while (true)
	{
		int v = -1;
		// ����δʹ�ù��Ķ�����ѡ��һ��������С�Ķ���
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
	// ��� A �� G ����̾���
	// A -> C -> D -> F -> E -> G �� 16
	Dijkstra('A' - 'A');
	cout << d['G' - 'A'] << endl;
}

int main()
{
	Init();
	Solve();
	return 0;
}
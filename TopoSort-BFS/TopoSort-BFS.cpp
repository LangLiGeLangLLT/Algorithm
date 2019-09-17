#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// BFS

bool TopoSort(int N, const vector<vector<int>>& G, vector<int>& indegree, vector<int>& ans)
{
	int cnt = 0;
	
	queue<int> que;
	for (int v = 1; v <= N; ++v)
	{
		if (indegree[v] == 0) que.push(v);
	}

	while (!que.empty())
	{
		int v = que.front(); que.pop();

		++cnt;
		ans.push_back(v);

		for (int u : G[v])
		{
			if (--indegree[u] == 0) que.push(u);
		}
	}

	return cnt == N;
}

int main()
{
	// 课程关系：course[0] -> course[1]
	// 课程号：1 - 5
	vector<vector<int>> courses = { {1, 2}, {1, 4}, {2, 3}, {4, 3}, {1, 4}, {2, 4}, {3, 5}, {4, 5} };
	int N = 5;

	// 环路
	// vector<vector<int>> courses = { {1, 2}, {2, 1} };
	// int N = 2;

	vector<vector<int>> G(N + 1);
	vector<int> indegree(N + 1);

	for (const vector<int>& course : courses)
	{
		++indegree[course[1]];
		G[course[0]].push_back(course[1]);
	}

	vector<int> ans;
	if (TopoSort(N, G, indegree, ans))
	{
		for (int num : ans) cout << num << " ";
	}
	else
		cout << "存在回环" << endl;

	return 0;
}
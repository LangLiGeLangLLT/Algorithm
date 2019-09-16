#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> TopoSortByBFS(const vector<vector<int>>& G, vector<int> indegree, int N)
{
	vector<int> ans;

	queue<int> que;
	for (int v = 1; v <= N; ++v)
	{
		if (indegree[v] == 0) que.push(v);
	}

	while (!que.empty())
	{
		int p = que.front(); que.pop();

		ans.push_back(p);

		for (int u : G[p])
		{
			if (--indegree[u] == 0) que.push(u);
		}
	}

	return ans;
}

void TopoSortByDFS(int v, const vector<vector<int>>& G, vector<int>& indegree, vector<int>& ans)
{
	ans.push_back(v);

	for (int u : G[v])
	{
		if (--indegree[u] == 0)
		{
			TopoSortByDFS(u, G, indegree, ans);
		}
	}
}

int main()
{
	// 课程关系：course[0] -> course[1]
	// 课程号：1 - 5
	vector<vector<int>> courses = { {1, 2}, {1, 4}, {2, 3}, {4, 3}, {1, 4}, {2, 4}, {3, 5}, {4, 5} };
	int N = 5;

	vector<vector<int>> G(N + 1);
	vector<int> indegree(N + 1); // 入度
	for (const vector<int>& course : courses)
	{
		++indegree[course[1]];
		G[course[0]].push_back(course[1]);
	}

	// BFS
	for (int num : TopoSortByBFS(G, indegree, N))
		cout << num << " ";

	cout << endl;

	// DFS
	vector<int> indegreeDFS(indegree.begin(), indegree.end());
	vector<int> ans;

	for (int v = 1; v <= N; ++v)
	{
		if (indegree[v] == 0)
			TopoSortByDFS(v, G, indegreeDFS, ans);
	}

	for (int num : ans) cout << num << " ";

	return 0;
}
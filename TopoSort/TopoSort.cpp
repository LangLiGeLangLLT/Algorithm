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

// 0：正在访问，1：访问成功，0x3f3f3f3f：未访问

void TopoSortByDFS(int v, const vector<vector<int>>& G, vector<int>& visit, vector<int>& ans)
{
	visit[v] = 0;
	
	for (int u : G[v])
	{
		if (visit[u] == 0) return;
		if (visit[u] == 0x3f3f3f3f) TopoSortByDFS(u, G, visit, ans);
	}

	visit[v] = 1;
	ans.push_back(v);
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
	vector<int> visit(N + 1, 0x3f3f3f3f);
	vector<int> ans;

	for (int v = 1; v <= N; ++v)
	{
		if (visit[v] == 0x3f3f3f3f)
			TopoSortByDFS(v, G, visit, ans);
	}
	reverse(ans.begin(), ans.end());

	for (int num : ans) cout << num << " ";

	return 0;
}
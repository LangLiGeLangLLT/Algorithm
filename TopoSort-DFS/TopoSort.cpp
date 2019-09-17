#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DFS

bool TopoSort(int v, const vector<vector<int>> G, vector<int>& visit, vector<int>& ans)
{
	visit[v] = 0; // 正在访问

	for (int u : G[v])
	{
		if (visit[u] == 0) return false;
		if (visit[u] == 0x3f3f3f3f && !TopoSort(u, G, visit, ans)) return false;
	}

	visit[v] = 1; // 访问成功
	ans.push_back(v);
	
	return true;
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
	vector<int> visit(N + 1, 0x3f3f3f3f); // 未被访问

	for (const vector<int>& course : courses)
	{
		G[course[0]].push_back(course[1]);
	}

	bool find = false; // 发现回环
	vector<int> ans;
	for (int v = 1; v <= N; ++v)
	{
		if (visit[v] == 0x3f3f3f3f)
		{
			if (!TopoSort(v, G, visit, ans))
			{
				find = true;
				break;
			}
		}
	}

	if (!find)
	{
		reverse(ans.begin(), ans.end());
		for (int num : ans) cout << num << " ";
	}
	else
		cout << "存在回环" << endl;

	return 0;
}
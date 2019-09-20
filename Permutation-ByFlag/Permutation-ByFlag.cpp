#include <iostream>
#include <vector>

using namespace std;

vector<bool> visit;
vector<int> tmp;

// 生成 { 0, 1, 2, 3, 4, ... , n - 1 } 的 n! 种排列
void permutation(const vector<int>& nums, int pos, int n)
{
	if (pos >= n)
	{
		// 这里编写需要对 nums 进行的操作
		for (const int& index : tmp) cout << nums[index] << " ";
		cout << endl;

		return;
	}

	for (int i = 0; i < n; ++i)
	{
		if (!visit[i])
		{
			tmp[pos] = i;
			visit[i] = true;

			permutation(nums, pos + 1, n);

			visit[i] = false;
		}
	}
}

int main()
{
	vector<int> nums = { 1, 2, 3 };
	int n = nums.size();
	visit.resize(n);
	tmp.resize(n);

	permutation(nums, 0, n);

	return 0;
}
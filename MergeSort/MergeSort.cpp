#include <iostream>
#include <vector>

using namespace std;

vector<int> temp; // 辅助存储

void MergeSort(vector<int>& nums, int l, int r)
{
	if (r - l <= 1) // 分到剩余 1 个元素为止
		return;

	int m = l + (r - l) / 2;
	int p = l, q = m, i = l;

	MergeSort(nums, l, m);
	MergeSort(nums, m, r);

	while (p < m || q < r)
	{
		if (q >= r || (p < m && nums[p] <= nums[q]))
			temp[i++] = nums[p++];
		else
			temp[i++] = nums[q++];
	}

	for (int k = l; k < r; ++k)
		nums[k] = temp[k];
}

int main()
{
	vector<int> nums = { 2, 1, 7, 9, 5, 8 };
	temp.resize(nums.size());

	for (int num : nums) cout << num << " ";

	MergeSort(nums, 0, nums.size());

	cout << endl;
	for (int num : nums) cout << num << " ";

	return 0;
}
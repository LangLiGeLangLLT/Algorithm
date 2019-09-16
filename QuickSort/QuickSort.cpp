#include <iostream>
#include <vector>

using namespace std;

// 每轮默认以第一个元素为基准，若原始数组有序，则时间复杂度为 O(n^2)

void QuickSort(vector<int>& nums, int l, int r)
{
	if (l >= r) // 分到剩余 1 个元素为止
		return;

	int i = l, j = r, key = nums[i];

	while (i < j)
	{
		while (i < j && nums[j] >= key) --j;
		nums[i] = nums[j];

		while (i < j && nums[i] <= key) ++i;
		nums[j] = nums[i];
	}
	nums[i] = key;

	QuickSort(nums, l, i - 1);
	QuickSort(nums, i + 1, r);
}

int main()
{
	vector<int> nums = { 2, 1, 7, 9, 5, 8 };

	for (int num : nums) cout << num << " ";

	QuickSort(nums, 0, nums.size() - 1);

	cout << endl;
	for (int num : nums) cout << num << " ";

	return 0;
}

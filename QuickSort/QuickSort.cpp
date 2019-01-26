#include <iostream>
#include <vector>

using namespace std;

void QuickSort(vector<int>& nums, int l, int r)
{
	if (r - l <= 1) // 分到剩余 1 个元素为止
		return;

	int i = l, j = r - 1, key = nums[i];

	while (i < j)
	{
		while (i < j && nums[j] >= key)
			--j;
		nums[i] = nums[j];

		while (i < j && nums[i] <= key)
			++i;
		nums[j] = nums[i];
	}
	nums[j] = key;

	QuickSort(nums, l, j);
	QuickSort(nums, j + 1, r);
}

int main()
{
	vector<int> nums = { 9,1,4,2,6 };

	QuickSort(nums, 0, nums.size());

	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";

	return 0;
}

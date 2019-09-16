#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 首先将数组分成左右两个部分，左边是已经排好序的部分，右边是还没有排好序的部分。
// 刚开始，左边已排好序的部分只有第一个元素2。
// 接下来，我们对右边的元素一个一个进行处理，将它们放到左边。

void InsertionSort(vector<int>& nums)
{
	for (int i = 1, j, current; i < nums.size(); ++i)
	{
		current = nums[i];

		for (j = i - 1; j >= 0 && nums[j] > current; --j)
			nums[j + 1] = nums[j];

		nums[j + 1] = current;
	}
}

int main()
{
	vector<int> nums = { 2, 1, 7, 9, 5, 8 };

	for (int num : nums) cout << num << " ";

	InsertionSort(nums);

	cout << endl;
	for (int num : nums) cout << num << " ";

	return 0;
}
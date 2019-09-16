#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 总共进行 n - 1 轮，若不再交换，则已排好序。
// 每轮都将较大的数进行冒泡，放在数组最后的位置。

void BubbleSort(vector<int>& nums)
{
	bool hasChanged = true;
	for (int i = 0; i < nums.size() - 1 && hasChanged; ++i)
	{
		hasChanged = false;

		for (int j = 0; j < nums.size() - 1 - i; ++j)
		{
			if (nums[j] > nums[j + 1])
			{
				swap(nums[j], nums[j + 1]);
				hasChanged = true;
			}
		}
	}
}

int main()
{
	vector<int> nums = { 2, 1, 7, 9, 5, 8 };

	for (int num : nums) cout << num << " ";

	BubbleSort(nums);

	cout << endl;

	for (int num : nums) cout << num << " ";

	return 0;
}
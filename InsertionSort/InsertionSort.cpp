#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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
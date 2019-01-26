#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Permutation(vector<int> nums, int pos, int size)
{
	if (pos == size)
	{
		// 这里编写需要对 nums 进行的操作
		for (int i = 0; i < size; ++i)
			cout << nums[i] << " ";
		cout << endl;

		return;
	}

	for (int i = pos; i < size; ++i)
	{
		swap(nums[pos], nums[i]);

		Permutation(nums, pos + 1, size);

		swap(nums[pos], nums[i]);
	}
}

int main()
{
	vector<int> nums = { 1,2,3,4 };

	Permutation(nums, 0, nums.size());

	return 0;
}
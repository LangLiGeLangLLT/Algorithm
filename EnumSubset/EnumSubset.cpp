#include <iostream>
#include <vector>

using namespace std;

void EnumSubset(vector<int> nums, int size)
{
	for (int i = 0; i < (1 << size); ++i)
	{
		for (int j = 0; j < size; ++j)
			if (i & (1 << j))
			{
				// 这里编写需要对 nums 进行的操作
				cout << nums[j] << " ";
			}
		cout << endl;
	}
}

int main()
{
	vector<int> nums = { 1,2,3,4 };

	EnumSubset(nums, nums.size());

	return 0;
}
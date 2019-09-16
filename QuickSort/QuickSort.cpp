#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// 首先，为了避免最糟糕的情况出现，我们随机地选择一个数作为基准值，
// 将它放置到最右边，也就是hi指针的位置，所以，nums[hi]就是我们的基准值。

// 接着，从左到右不断地拿每个数和基准值比较，如果发现当前的数比基准值小，就将它放到指针i所指向的位置。
// 循环完毕后，i指针之前的数都比基准值小。

// 最后将一开始放置在末尾的基准值放置到指针i的位置，这样一来，i 指针之后的数都比基准值大了。

// 返回指针i，作为基准点的位置。

int Partition(vector<int>& nums, int l, int r)
{
	uniform_int_distribution<int> u(l, r);
	static default_random_engine e;

	swap(nums[u(e)], nums[r]);

	int i, j;
	for (i = l, j = l; j < r; ++j)
	{
		if (nums[j] <= nums[r])
			swap(nums[i++], nums[j]);
	}

	swap(nums[i], nums[j]);

	return i;
}

// 首先判断是否只剩下了一个元素，如果是，就不需要排序了，直接返回。

// 接着，利用partition函数找到一个随机的基准点。
// 这个时候，基准点左边的数一定都小于基准值，而右边的数一定都大于基准值。

// 递归地对基准点左半边和右半边的数进行排序。

void QuickSort(vector<int>& nums, int l, int r)
{
	if (l >= r) // 分到剩余 1 个元素为止
		return;

	int p = Partition(nums, l, r);

	QuickSort(nums, l, p - 1);
	QuickSort(nums, p + 1, r);
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

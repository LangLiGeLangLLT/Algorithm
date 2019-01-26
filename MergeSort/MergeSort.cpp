#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 100;

int temp[MAX_N]; // �����洢

void MergeSort(vector<int>& nums, int l, int r)
{
	if (r - l <= 1) // �ֵ�ʣ�� 1 ��Ԫ��Ϊֹ
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
	vector<int> nums = { 9,1,8,2,5 };

	MergeSort(nums, 0, nums.size());

	for (int i = 0; i < nums.size(); ++i)
		cout << nums[i] << " ";

	return 0;
}
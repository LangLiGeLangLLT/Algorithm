#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool BinarySearch(vector<int> nums, int l, int r, int x)
{
	while (r - l >= 1)
	{
		int i = l + (r - l) / 2;

		if (nums[i] == x)
			return true;
		else if (nums[i] < x)
			l = i + 1;
		else
			r = i;
	}
	return false;
}

int main()
{
	vector<int> nums = { 9,5,4,6,2,3,7 };

	sort(nums.begin(), nums.end());

	cout << boolalpha << BinarySearch(nums, 0, nums.size(), 6) << endl
		<< BinarySearch(nums, 0, nums.size(), 1) << noboolalpha;

	return 0;
}
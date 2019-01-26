#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// ���Բ��� O(��n)
bool IsPrime(int n)
{
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return false;
	return n != 1; // 1 ������
}

// Լ��ö�� O(��n)
vector<int> Divisor(int n)
{
	vector<int> res;
	for (int i = 1; i * i <= n; ++i)
		if (n % i == 0)
		{
			res.push_back(i);
			if (i != n / i)
				res.push_back(n / i);
		}
	return res;
}

// �����ֽ� O(��n)
map<int, int> PrimeFactor(int n)
{
	map<int, int> res;
	for (int i = 2; i * i <= n; ++i)
		while (n % i == 0)
		{
			++res[i];
			n /= i;
		}
	if (n != 1)
		res[n] = 1;
	return res;
}

int main()
{
	cout << "41 ��������" << boolalpha << IsPrime(41) << noboolalpha << endl;
	cout << "42 ��������" << boolalpha << IsPrime(42) << noboolalpha << endl;
	cout << endl;

	vector<int> divisors = Divisor(42);
	for_each(divisors.begin(), divisors.end(), [](int item)
	{
		cout << item << " ";
	});
	cout << endl << endl;

	map<int, int> primefactors = PrimeFactor(42);
	for_each(primefactors.begin(), primefactors.end(), [](pair<int, int> item)
	{
		cout << item.first << " " << item.second << endl;
	});

	return 0;
}
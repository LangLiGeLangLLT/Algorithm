#include <iostream>

using namespace std;

const int MAX_N = 1000001;

int prime[MAX_N];		// �� i ������
bool is_prime[MAX_N];	// is_prime[i] Ϊ true ��ʾ i ������

int Sieve(int n) // ���� n ���������ĸ���
{
	int p = 0;
	for (int i = 0; i <= n; ++i)
		is_prime[i] = true;
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i <= n; ++i)
		if (is_prime[i])
		{
			prime[p++] = i;
			for (int j = 2 * i; j <= n; j += i)
				is_prime[j] = false;
		}

	return p;
}

int main()
{
	cout << Sieve(1000000) << endl;
	return 0;
}
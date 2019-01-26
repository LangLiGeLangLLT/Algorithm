#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MAX_L = 1000001;

bool is_prime[MAX_L];
bool is_prime_small[MAX_L];

// 对区间 [a, b) 内的整数执行筛法。is_prime[i - a] = true  <=>  i 是素数
void segment_sieve(ll a, ll b)
{
	for (int i = 0; (ll)i * i < b; ++i)
		is_prime_small[i] = true;
	for (int i = 0; i < b - a; ++i)
		is_prime[i] = true;

	for (int i = 2; (ll)i * i < b; ++i)
		if (is_prime_small[i])
		{
			for (int j = 2 * i; (ll)j * j < b; j += i) // 筛 [2, √b)
				is_prime_small[j] = false; 
			for (ll j = max(2LL, (a + i - 1) / i) * i; j < b; j += i) // 筛[a, b)
				is_prime[j - a] = false;
		}
}

int main()
{
	segment_sieve(22801763489, 22801787297);

	int cnt = 0;
	for (int i = 0; i < MAX_L; ++i)
		if (is_prime[i])
			++cnt;
	cout << cnt << endl;

	return 0;
}
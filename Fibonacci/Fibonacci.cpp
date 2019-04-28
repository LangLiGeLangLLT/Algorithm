/*
	F[0] = 0
	F[1] = 1
	F[n + 2] = F[n + 1] + F[n]

	求这个数列第 n 项的值对 10^4 取余后的结果
*/

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<int>> mat;

const int M = 10000;

ll n;

void Init()
{
	cin >> n;
}

mat Mul(const mat& A, const mat& B)
{
	mat C(A.size(), vector<int>(B[0].size()));
	for (int i = 0; i < A.size(); ++i)
		for (int k = 0; k < B.size(); ++k)
			for (int j = 0; j < B[0].size(); ++j)
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
	return C;
}

mat Pow(mat A, ll n)
{
	mat B(A.size(), vector<int>(A.size()));
	for (int i = 0; i < A.size(); ++i)
		B[i][i] = 1;
	while (n > 0)
	{
		if (n & 1) B = Mul(B, A);
		A = Mul(A, A);
		n >>= 1;
	}
	return B;
}

void Solve()
{
	mat A = { { 1, 1 }, { 1, 0 } };
	mat B = { { 1 }, { 1 } };
	A = Mul(Pow(A, n - 1), B);
	cout << A[1][0] << endl;
}

int main()
{
	Init();
	Solve();
	return 0;
}
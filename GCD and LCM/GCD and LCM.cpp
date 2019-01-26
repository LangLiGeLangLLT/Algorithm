#include <iostream>

using namespace std;

int GCD(int a, int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}

int LCM(int a, int b)
{
	return a / GCD(a, b) * b;
}

int main()
{
	cout << GCD(10, 15) << endl;
	cout << LCM(10, 15) << endl;

	return 0;
}
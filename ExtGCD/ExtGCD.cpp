#include <iostream>

using namespace std;

// 求整数 x 和 y 使得 ax + by = 1。
// 可以发现，如果 gcd(a, b) ≠ 1，显然无解。
// 反之，如果 gcd(a, b) = 1，就可以通过扩展原来的辗转相除法来求解。
// 事实上，一定存在整数对 (x, y) 使得 ax + by = gcd(a, b)，并可以用同样的算法求得。

// 设 int extgcd(int a, int b, int& x, int& y) 是求解该方程的函数，其返回值是 gcd(a, b)。
// 与 gcd 一样，我们可以递归地定义 extgcd。
// 假设已经求得了
//
//		bx' + (a % b)y' = gcd(a, b)
//
// 的整数解 x' 和 y'。
// 再将
//
//		a % b = a - (a / b) × b
//
// 代入后就得到
//
//		ay' + b(x' - (a / b) × y') = gcd(a, b)
//
// 而当 b = 0 时则有
//
//		a × 1 + b × 0 = a = gcd(a, b)
//

// ax + by = gcd(a, b) 的解的大小
// 事实上，如果 ab ≠ 0，就可以知道 |x| ≤ b 且 |y| ≤ a。

int ExtGCD(int a, int b, int& x, int& y)
{
	int d = a;
	if (b != 0)
	{
		d = ExtGCD(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else
	{
		x = 1;
		y = 0;
	}
	return d;
}

int GCD(int a, int b)
{
	return b == 0 ? a : GCD(b, a % b);
}

int main()
{
	int x, y;

	// 4x + 11y = gcd(4, 11)
	if (ExtGCD(4, 11, x, y) == GCD(4, 11))
		cout << x << " " << y << endl;
	else
		cout << "No answer" << endl;

	return 0;
}
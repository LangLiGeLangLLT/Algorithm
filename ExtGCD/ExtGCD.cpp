#include <iostream>

using namespace std;

// ������ x �� y ʹ�� ax + by = 1��
// ���Է��֣���� gcd(a, b) �� 1����Ȼ�޽⡣
// ��֮����� gcd(a, b) = 1���Ϳ���ͨ����չԭ����շת���������⡣
// ��ʵ�ϣ�һ������������ (x, y) ʹ�� ax + by = gcd(a, b)����������ͬ�����㷨��á�

// �� int extgcd(int a, int b, int& x, int& y) �����÷��̵ĺ������䷵��ֵ�� gcd(a, b)��
// �� gcd һ�������ǿ��Եݹ�ض��� extgcd��
// �����Ѿ������
//
//		bx' + (a % b)y' = gcd(a, b)
//
// �������� x' �� y'��
// �ٽ�
//
//		a % b = a - (a / b) �� b
//
// �����͵õ�
//
//		ay' + b(x' - (a / b) �� y') = gcd(a, b)
//
// ���� b = 0 ʱ����
//
//		a �� 1 + b �� 0 = a = gcd(a, b)
//

// ax + by = gcd(a, b) �Ľ�Ĵ�С
// ��ʵ�ϣ���� ab �� 0���Ϳ���֪�� |x| �� b �� |y| �� a��

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
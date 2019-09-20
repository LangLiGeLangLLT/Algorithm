// 1、树状数组是多叉树
// 2、树状数组的第一个元素是空节点
// 3、如果节点 tree[y] 是 tree[x] 的父节点，
//    那么满足如下条件：
//    y = x - (x & (-x))

// i -= i & -i 可以写作 i = i & (i - 1)

// [1, n]
int bit[MAX_N + 1], n;

int sum(int i)
{
	int s = 0;
	while (i > 0)
	{
		s += bit[i];
		i -= i & -i;
	}
	return s;
}

void add(int i, int x)
{
	while (i <= n)
	{
		bit[i] += x;
		i += i & -i;
	}
}
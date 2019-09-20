const int MAX_N = 1 << 17;

// 存储线段树的全局数组
int n, data[2 * MAX_N - 1];

// 初始化
void init(int N)
{
	n = 1;
	while (n < N) n *= 2;
	
	for (int i = 0; i < 2 * n - 1; ++i) data[i] = INT_MAX;
}

// 把第 k 个值（0 - indexed）更新为 val
void update(int k, int val)
{
	k += n - 1;
	data[k] = val;
	
	// 向上更新
	while (k > 0)
	{
		k = (k - 1) / 2;
		data[k] = min(data[k * 2 + 1], data[k * 2 + 2]);
	}
}

// 求 [a, b] 的最小值
// 后面的参数是为了计算起来方便而传入的。
// k 是节点的编号，l，r 表示这个节点对应的是 [l, r] 区间。
// 在外部调用时，用 query(a, b, 0, 0, n - 1)
int query(int a, int b, int k, int l, int r)
{
	// 如果 [a, b] 和 [l, r] 不相交，则返回 INT_MAX
	if (a > r || b < l) return INT_MAX;

	// 如果 [a, b] 完全包含 [l, r]，则返回当前节点的值
	if (a <= l && r <= b) return data[k];

	// 否则返回两个儿子中值的较小者
	int mid = l + (r - l) / 2;
	int vl = query(a, b, k * 2 + 1, l, mid);
	int vr = query(a, b, k * 2 + 2, mid + 1, r);

	return min(vl, vr);
}
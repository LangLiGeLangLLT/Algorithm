int par[MAX_N];		// 父亲
int rank[MAX_N];	// 树的高度

// 初始化 n 个元素
void init(int n)
{
	for (int i = 0; i < n; ++i)
	{
		par[i] = i;
		rank[i] = 0;
	}
}

// 查询树的根
int find(int x)
{
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}

// 合并 x 和 y 所属的集合
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rank[x] < rank[y])
		par[x] = y;
	else
	{
		par[y] = x;
		if (rank[x] == rank[y]) ++rank[x];
	}
}

// 判断 x 和 y 是否属于同一个集合
bool same(int x, int y)
{
	return find(x) == find(y);
}
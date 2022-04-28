//区间修改值，查询结果
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
struct Segment
{
	int l, r;
	ll sum, add;
} tr[N << 2];
void pushup(int u)
{
	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r)
{
	if (l == r)
	{
		tr[u] = {l, r, 1, 0};
	}
	else
	{
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}
void pushdown(int u)
{
	auto &root = tr[u], &L = tr[u << 1], &R = tr[u << 1 | 1];
	if (root.add)
	{
		L.add=root.add,L.sum = (ll)(L.r - L.l + 1) * root.add;
		R.add=root.add,R.sum = (ll)(R.r - R.l + 1) * root.add;
		root.add = 0;
	}
}
void modify(int u, int l, int r, int x)
{
	if (tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].sum = (ll)(tr[u].r - tr[u].l + 1) * x;
		tr[u].add = x;
	}
	else
	{ //一定要分裂
		pushdown(u);
		int mid = (tr[u].l + tr[u].r) >> 1;
		if (l <= mid)
			modify(u << 1, l, r, x);
		if (r > mid)
			modify(u << 1 | 1, l, r, x);
		pushup(u);
	}
}
ll query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r)
		return tr[u].sum;
	pushdown(u);
	int mid = tr[u].l + tr[u].r >> 1;
	ll sum = 0;
	if (l <= mid)
		sum += query(u << 1, l, r);
	if (r > mid)
		sum += query(u << 1 | 1, l, r);
	return sum;
}
int main()
{
	int t;
	scanf("%d", &t);
	int cnt = 1;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		int m;
		scanf("%d", &m);
		build(1, 1, n);
		int l, r, x;
		while (m--)
		{
			scanf("%d%d%d", &l, &r, &x);
			modify(1, l, r, x);
		}
		printf("Case %d: The total value of the hook is %lld.\n", cnt++, query(1, 1, n));
	}

	return 0;
}
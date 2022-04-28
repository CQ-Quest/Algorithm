//主席树，m个版本，每次建树4logn  则复杂度O(mlogn),求第k小数
/*难以做修改操作，懒标记过多，主席树可持续化的区别：可查询历史版本*/ 
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
struct ChairmanTree
{
    int l, r;
    int cnt;          //记录区间共有多少个数
} tr[N * 4 + N * 17]; // 4logN+logN
int root[N], idx;
vector<int> num;
int a[N];
int find(int x)
{
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}
int build(int l, int r) //l,r表示左右儿子
{
    int p = ++idx;
    if (l == r)
        return p;
    int mid = l + r >> 1;
    tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
    return p;
}
int insert(int p, int l, int r, int x)
{
    int q = ++idx;
    tr[q] = tr[p];
    if (l == r)
    {
        tr[q].cnt++;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].l = insert(tr[p].l, l, mid, x);
    else
        tr[q].r = insert(tr[q].r, mid + 1, r, x);
    tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
    return q;
}
int query(int q, int p, int l, int r, int k)
{
    if (l == r)
        return r;
    int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    int mid = l + r >> 1;
    if (k <= cnt)
        return query(tr[q].l, tr[p].l, l, mid, k);
    else
        return query(tr[q].r, tr[p].r, mid + 1, r, k - cnt);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), num.push_back(a[i]);
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    root[0] = build(0, num.size() - 1);
    for (int i = 1; i <= n; i++)
        root[i] = insert(root[i - 1], 0, num.size() - 1, find(a[i]));
    while (m--)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        //k = r - l + 1 - k + 1 ;
        printf("%d\n", num[query(root[r], root[l - 1], 0, num.size() - 1, k)]);
    }

    return 0;
}
//I Hate It
//查询最高成绩，修改成绩
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
struct node
{
    int l, r;
    int v;
} tr[maxn * 4];
int m, n;
int w[maxn];
void pushup(int u)
{
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}
void build(int u, int l, int r)
{
    if(l==r) tr[u]={l,r,w[r]};
    else{
        tr[u]={l,r};
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
     pushup(u);
    }
}
int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].v;
    int mid = (tr[u].l + tr[u].r) >> 1;
    int v = 0;
    if (l <= mid)
        v = max(v, query(u << 1, l, r));
    if (r > mid)
        v = max(v, query(u << 1 | 1, l, r));
    return v;
}
void modify(int u, int x, int v)
{
    if (tr[u].l == tr[u].r)
        tr[u].v = v;
    else
    {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
            cin >> w[i];
        build(1, 1, n);
        while (m--)
        {
            char op[2];
            int x, y;
            cin >> op >> x >> y;
            if (*op == 'Q')
            {
                cout << query(1, x, y) << endl;
            }
            else
            {
                modify(1, x, y);
            }
        }
    }
    
    return 0;
}
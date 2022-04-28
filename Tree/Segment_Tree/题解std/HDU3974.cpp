/*将任务y分配给员工x，查询x当前的任务
区间修改，单点查询
*/
#include <cstdio>
#include<cmath>
#include<cstring>
using namespace std;
typedef long long ll;
int cnt, idx;
const int N = 5e4 + 10;
int h[N << 1], ne[N << 1], e[N << 1];
int vis[N];
int in[N], out[N];
int n, m, temp;
struct Segment
{
    int l, r;
    ll add, sum;
} tr[N << 2];
void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}
void init()
{
    idx = 0, cnt = 0;
    memset(h, -1, sizeof h);
    for(int i=0;i<=n;i++) vis[i]=0;
}
void dfs(int x)
{
    in[x] = ++cnt;
    //vis[x] = true;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
       dfs(j);
    }
    out[x] = cnt;
}
void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void pushdown(int u)
{
    auto &root = tr[u], &L = tr[u << 1], &R = tr[u << 1 | 1];
    if (root.add)
    {
        L.add = root.add, L.sum = (ll)(L.r - L.l + 1) * root.add;
        R.add = root.add, R.sum = (ll)(R.r - R.l + 1) * root.add;
        root.add = 0;
    }
}
void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, -1};
    if (l != r)
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}
void modify(int u, int l, int r, int x)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum = x;
        tr[u].add = 1;
    }
    else
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, x);
        if (r > mid)
            modify(u << 1 | 1, l, r, x);
    }
}
ll query(int u, int x)
{
    if (tr[u].l ==x&& tr[u].r==x)
        return tr[u].sum;
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    ll sum = 0;
    if (x <= mid)
        sum += query(u << 1, x);
    if (x > mid)
        sum += query(u << 1 | 1, x);
    return sum;
}
int main()
{
    int t;
    scanf("%d", &t);
    int f = 1;
    while (t--)
    {
        init();
        scanf("%d", &n);
        build(1, 1, n);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(v, u);
            vis[u]++;
        }
        for (int i = 1; i <= n; i++)
            if (!vis[i]) dfs(i);

        scanf("%d", &m);
        printf("Case #%d:\n", f++);
        while (m--)
        {
            char op[3];
            int x, y;
            scanf("%s", op);
            if (*op == 'C')
            {
                scanf("%d", &x);
                printf("%lld\n", query(1, in[x]));
            }
            else
            {
                scanf("%d%d", &x, &y);
                modify(1, in[x], out[x], y);
            }
        }
    }
    return 0;
}
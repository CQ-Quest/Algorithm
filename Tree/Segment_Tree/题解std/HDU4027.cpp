//Can you answer these queries?
/*区间查询,区间修改为sqrt(x)
 if(tr[u].sum == (R-L+1)) return;
 //剪枝很重要，但结点为1是不需要再取根号
*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e6 + 10;
struct Segment
{
    int l, r;
    ll sum;
} tr[N*4];
int n, m;
ll w[N];
void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}
void build(int u, int l, int r)
{
    tr[u] = {l, r, w[r]};
    if (l != r)
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}
// void pushdown(int u){
//     auto &root=tr[u],&L=tr[u<<1],&R=tr[u<<1|1];
//     if(root.mul){

//     }
// }
void modify(int u, int l, int r)
{
    int L = tr[u].l, R = tr[u].r;
    if (L == R)
    {
        tr[u].sum = (ll)sqrt(tr[u].sum);
        return;
    }
    if (tr[u].sum == (R - L + 1))
        return; //剪枝很重要，但结点为1是不需要再取根号

    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        modify(u << 1, l, r);
    if (r > mid)
        modify(u << 1 | 1, l, r);
    pushup(u);
}

// void modify(int u, int x, int v)
// {
//     if (tr[u].l == tr[u].r)
//         tr[u].v = v;
//     else
//     {
//         int mid = (tr[u].l + tr[u].r) >> 1;
//         if (x <= mid)
//             modify(u << 1, x, v);
//         else
//             modify(u << 1 | 1, x, v);
//         pushup(u);
//     }
// }
ll query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].sum;
    //pushdown(u);
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
    int t = 1;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            scanf("%lld", &w[i]);
        build(1, 1, n);
        scanf("%d", &m);
        int op, l, r;
        printf("Case #%d:\n", t++);
        while (m--)
        {
            scanf("%d%d%d", &op, &l, &r);
            if (l > r)
                swap(l, r);
            if (op == 1)
                printf("%lld\n", query(1, l, r));
            else
                modify(1, l, r);
        }
        printf("\n");
    }
    return 0;
}
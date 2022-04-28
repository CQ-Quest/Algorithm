/*
数据结构
https://ac.nowcoder.com/acm/contest/200/B
1:求区间和
2:求区间平方和
3:区间乘法
4:区间加法
*/

#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 10010;
typedef long long ll;
struct node
{
    int l, r;
    ll sum[3];
    int lazy, tag; //lazy为加法标记，tag为乘法标记
} tr[N << 2];
void pushup(int u)
{
    tr[u].sum[1] = tr[u << 1].sum[1] + tr[u << 1 | 1].sum[1];
    tr[u].sum[2] = tr[u << 1].sum[2] + tr[u << 1 | 1].sum[2];
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
    tr[u].tag = 1;
    if (l == r)
    {
        scanf("%lld", &tr[u].sum[1]);
        tr[u].sum[2] = tr[u].sum[1] * tr[u].sum[1];
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void eval(node &u,int tag,int lazy)   //先乘后加
{
	u.sum[2] = u.sum[2] * tag;
	u.sum[1] = u.sum[1] * tag;
	u.sum[2] += 2 *u.sum[1] * lazy + (u.r-u.l+1) * lazy * lazy;
	u.sum[1] += (u.r -u.l + 1) * lazy;
    u.lazy = u.lazy * tag + lazy;
	u.tag *= tag;
}

void pushdown(int u)
{
    eval(tr[u << 1], tr[u].tag, tr[u].lazy);
    eval(tr[u << 1 | 1], tr[u].tag, tr[u].lazy);
    tr[u].lazy = 0, tr[u].tag = 1;
}

ll query1(int u, int l, int r, int L, int R)
{
    if (l >= L && r <= R)
        return tr[u].sum[1];
    pushdown(u);
    int mid = l + r >> 1;
    ll sum = 0;
    if (L <= mid)
        sum += query1(u << 1, l, mid, L, R);
    if (R > mid)
        sum += query1(u << 1 | 1, mid + 1, r, L, R);
    return sum;
}

ll query2(int u, int l, int r, int L, int R)
{
    if (l >= L && r <= R)
        return tr[u].sum[2];
    pushdown(u);
    int mid = l + r >> 1;
    ll sum = 0;
    if (L <= mid)
        sum += query2(u << 1, l, mid, L, R);
    if (R > mid)
        sum += query2(u << 1 | 1, mid + 1, r, L, R);
    return sum;
}

void modify(int u, int l, int r, int L, int R, int mul, int add)
{
    if (l >= L && r <= R)
        eval(tr[u], mul, add);
    else
    {
        pushdown(u);
        int mid = l + r >> 1;
        if (L <= mid)
            modify(u << 1, l, mid, L, R, mul, add);
        if (R > mid)
            modify(u << 1 | 1, mid + 1, r, L, R, mul, add);
        pushup(u);
    }
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    int op, l, r, c;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 4)
        {
            scanf("%d", &c);
            modify(1, 1, n, l, r, 1, c);
        }
        else if (op == 3)
            scanf("%d", &c), modify(1, 1, n, l, r, c, 0);
        else if (op == 1)
            printf("%lld\n", query1(1, 1, n, l, r));
        else if (op == 2)
            printf("%lld\n", query2(1, 1, n, l, r));
    }
    return 0;
}
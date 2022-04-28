/*扫描线性质：
永远只考虑根节点信息，query不会调用pushdown 
所有操作均是成对出现，且先加后减
操作1：将区间[L,R]+k,表示+1，-1覆盖区间 
操作2：整个区间中长度大于0的区间总长是多少 
*/ 
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=1e5+10;

int n;
struct Segment
{
    double x, y1, y2;
    int k;
    bool operator< (const Segment &t)const
    {
        return x < t.x;
    }
}seg[N * 2];  //维护2n个点 
struct Node
{
    int l, r;
    int cnt;  //区间覆盖数 
    double len;
}tr[N * 8];

vector<double> num;//离散化数组维护区间 

int find(double y)
{
    return lower_bound(num.begin(), num.end(), y) - num.begin();
}

void pushup(int u)
{
    if (tr[u].cnt) tr[u].len = num[tr[u].r + 1] - num[tr[u].l];
    else if (tr[u].l != tr[u].r)  //不是叶子节点 
    {
        tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    }
    else tr[u].len = 0;  //如果是叶子结点 
}

void build(int u, int l, int r)
{
    tr[u] = {l, r, 0, 0};
    if (l != r)
    {
    	tr[u]={l,r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u, int l, int r, int k)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].cnt += k;
        pushup(u);
    }
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, k);
        if (r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

int main()
{
    int cnt=0;
    while (scanf("%d", &n)&&n)
    {
        num.clear();
        for (int i = 0, j = 0; i < n; i ++ )
        {
            double x1, y1, x2, y2;
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            seg[j ++ ] = {x1, y1, y2, 1};
            seg[j ++ ] = {x2, y1, y2, -1};
            num.push_back(y1), num.push_back(y2);
        }

        sort(num.begin(),num.end());
        num.erase(unique(num.begin(),num.end()),num.end());

        build(1, 0, num.size() - 2);

        sort(seg, seg + n * 2);

        double res = 0;
        for (int i = 0; i < n * 2; i ++ )
        {
            if (i > 0) res += tr[1].len * (seg[i].x - seg[i - 1].x);
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        }

        printf("Test case #%d\n", ++cnt );
        printf("Total explored area: %.2lf\n\n", res);
    }

    return 0;
}
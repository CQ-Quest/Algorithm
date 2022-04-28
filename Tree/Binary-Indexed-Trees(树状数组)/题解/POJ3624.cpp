//Balanced Lineup 求区间最值差
#include <cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
const int N = 5e4 + 10;
int n, q;
int trM[N],w[N];
vector<int>trm(N,1e7);
int lowbit(int x)
{
    return x & -x;
}
void add(int x, int y)
{
    while (x <= n)
    {
        trM[x] = max(trM[x], y);
        trm[x] = min(trm[x], y);
        x += lowbit(x);
    }
}
int M,m;
int getsum(int l, int r)
{
     M=0,m=1e7;
    int len = r - l + 1;
    while (len && r)
    {
        if (lowbit(r) <= len)
        {
            M = max(trM[r], M);
            m = min(trm[r], m);
            len -= lowbit(r);
            r -= lowbit(r);
        }
        else
        {
            M = max(w[r], M);//与原数组对比
            m = min(w[r], m);
            len--, r--;
        }
    }
    return M-m;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]), add(i,w[i]);
   while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",getsum(l,r));
	}

    return 0;
}
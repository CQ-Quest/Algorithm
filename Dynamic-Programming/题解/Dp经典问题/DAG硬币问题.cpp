# 求最少硬币数目

     不妨将每种面值看作一个点，表示“还需凑足的面值”，则初始状态为货币的支付价值v,目标状态为0，
对于状态j，如存在货币i，j>=a[i](数组a用于存储货币的面值)，则当前状态从j转向j-a[i],换句话说，也就是存在有向边j-->j-a[i]。
看到这，很明显，我们把问题转换成图记忆化搜索的方式，由于货币张数无限，图也是无限大的，需固定起点和终点，求起点v到终点0的最短路径。

#include<cstdio>
#include<algorithm>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int maxn = 4e4;
ll dp[maxn];
int n,a[maxn];
int main() {
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	int v;
	while (~scanf("%d", &v) && v) {
		memset(dp, INF, sizeof(dp));
		dp[0] = 0;
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= v;j++)
				if (j >= a[i]) dp[j] = min(dp[j], dp[j - a[i]] + 1);
		printf("%lld\n", dp[v]);
	}
	return 0;
}

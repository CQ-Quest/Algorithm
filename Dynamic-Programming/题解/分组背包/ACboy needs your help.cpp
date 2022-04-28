#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
 
const int N = 200;
int dp[N],a[N][N];
int n,m;

int main()
{
    int i,j,k;
    while(~scanf("%d%d",&n,&m)&&(n+m))
    {
        memset(dp,0,sizeof(dp));
        for(i=1; i<=n; ++i)
            for(j=1; j<=m; ++j)
                scanf("%d",&a[i][j]);
        for(i=1; i<=n; ++i)
            for(j=m; j>=0; --j)
                for(k=1; k<=j; ++k)
                {
                    dp[j] = max(dp[j],dp[j-k]+a[i][k]);
                }
        printf("%d\n",dp[m]);
    }
    return 0;
}

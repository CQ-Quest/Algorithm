# 完全背包  
    一个背包载重量M,从n种物品中选取若干件（同一物品可多次选取，即数量无限），使其重量和小于等于M  =>  最大价值  
    
               上限             下限
     朴素        0  1  2  3  ...  n     for(int j=w[i];j<=m;j++)    //记w[i]为重量
     完全         直到装满，当前背包容量j/w[i]
     
        01背包写法     
                    for(int i=1;i<=n;i++)
                      for(int j=m;j>=1;j--)  //反向
                      for(int k=0;k<=j/w[i];k++)
                      dp[j]=max(dp[j],dp[j-k*w[i]+k*c[i]);
                      
                      
           优化**  dp[i][j]=max(dp[i-1][j],dp[i][j-w[i]]+c[i])
                     一维 dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
		     
        // dp[i][j]表示只看前i个物品，总体积是j的情况下，总价值最大是多少
		  Code:
		#include <iostream>
		#include <algorithm>
		using namespace std;

		const int N = 1010;
		int v[N], w[N], dp[N];

		int main() {
		    int n, m;
		    cin >> n >> m;
		    for (int i = 1; i <= n; i++) 
		     cin >> w[i] >> v[i];

		    for (int i = 1; i <= n; i++) {
			for (int j = v[i]; j <= m; j++) {    // 正序
			    f[j] = max(dp[j], dp[j - w[i]] + v[i]);
			    // 朴素：dp[i][j] = max(dp[i - 1][j], dp[i][j - w[i]] + v[i]) 
			    // dp[i][j - w[i]] + v[i] = max(x, x, x, ...)
			}
		    }

		    cout << dp[m] << endl;
		}

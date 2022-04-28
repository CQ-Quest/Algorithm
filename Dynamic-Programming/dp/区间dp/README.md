# 区间dp
      模板1：
          for(int len=1;len<=m;len++){
          for(int i=1;i+len-1<=m;i++){
              int j=i+len-1;
              for(int k=i;k<=j;k++){
                  f[i][j] = min(f[i][j],f[i][k-1]+f[k+1][j]+something);
              }
          }
      }
      ————————————————————————————————————————————————————————————————
      for(int i=1; i<=n; i++)            //n：石子堆数
             dp[i][i] = 0;                  //初始化 
      for(int j=2; j<=n; j++)            // 区间[i,j]的终点j，i<j<=n
            for(int i=j-1;i>=1;i--) {      // 区间[i,j]的起点i
                  dp[i][j]=INF;              //初始化为极大值
                  for(int k=i;k<j;k++)       //大区间[i,j]从小区间[i,k]和[k+1,j]转移而来
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + w[i][j]);
            }

       
      模板2,推荐使用
      其中用了一个辅助变量 l e n len len，它等于当前处理的区间 [ i , j ] [i, j] [i,j]的长度。dp[i][j]是大区间，
    它需要从小区间 dp[i][k]和dp[k+1][j]转移而来，所以应该先计算出小区间，才能根据小区间算出大区间。
    len就起到了这个作用，从最小的区间len=2开始，此时区间 [i,j]等于[i,i+1]；最后是最大区间len=n，此时区间 [i,j]等于[1,n]。
    
      for(int i=1; i<=n; i++) 
          dp[i][i] = 0;
      for(int len=2; len<=n; len++)       //len：区间[i,j]的长度，从小区间扩展到大区间
            for(int i=1; i<=n-len+1; i++){  // 区间起点i
                  int j = i + len - 1;        // 区间终点j，i<j<=n
              dp[i][j] = INF; 
                  for(int k=i; k<j; k++)
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + w[i][j]);
            }

      
 Code:
 
          #include <bits/stdc++.h>
          using namespace std;
          typedef long long ll;

          int n,m;
          int a[1001];
          int f[1001][1001]; 

          int main(){
              scanf("%d %d",&n,&m);
              for(int i=1;i<=m;i++){
                  scanf("%d",&a[i]);
              }
              sort(a+1,a+m+1);
              a[0] = 0;
              a[m+1] = n+1;
              for(int len=1;len<=m;len++){
                  for(int i=1;i+len-1<=m;i++){
                      int j=i+len-1;
                      f[i][j] = 1000000000;
                      for(int k=i;k<=j;k++){
                          f[i][j] = min(f[i][j],f[i][k-1]+f[k+1][j]+a[j+1]-a[i-1]-1-1);
                      }
                  }
              }
              printf("%d\n",f[1][m]);
              return 0;
          }


 

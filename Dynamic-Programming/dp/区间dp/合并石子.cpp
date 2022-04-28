      #include<bits/stdc++.h>
      #define INF 0x3f3f3f3f
      using namespace std;
       typedef long long ll;
       const int maxn=2020;
       ll sum[maxn],dp[maxn][maxn];
       int n;
       int main(){
            int x;
            scanf("%d",&n);
            memset(dp,INF,sizeof(dp));
            for(int i=1;i<=n;i++){
                  scanf("%d",&x);
                  sum[i]=sum[i-1]+x;
                  dp[i][i]=0;
             }
             for(int len=2;len<=n;len++)
             for(int i=1;i<=n-len+1;i++){
                  int j=i+len-1;
                  dp[i][j]=INF;
                  for(int k=i;k<j;k++){
                        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                        dp[i][j]+=sum[j]-sum[i-1];
                   }
             }
             cout<<dp[1][n]<<endl;
             return 0;
       }

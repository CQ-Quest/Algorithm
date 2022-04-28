#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int dp[maxn][12];
int main(){
	ios::sync_with_stdio(0);
	int n,x,t,k;
	while(cin>>n&&n){
		memset(dp,0,sizeof(dp));
		k=0;
		for(int i=0;i<n;i++){
			cin>>x>>t;
			dp[t][++x]++;
			k=max(k,t);
		}
		for(int i=k-1;i>=0;i--)
		for(int j=1;j<=11;j++)
		dp[i][j]+=max(dp[i+1][j],max(dp[i+1][j-1],dp[i+1][j+1]));
	   cout<<dp[0][6]<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int dp[maxn][maxn],a[maxn][maxn];
int main(){
	ios::sync_with_stdio(0);
	int n;
	int c;
	cin>>c;
	while(c--){
		memset(dp,0,sizeof dp);
		cin>>n;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++){
		cin>>a[i][j];
		dp[i][j]=a[i][j];
	}
		for(int i=n;i>=1;i--)
		for(int j=1;j<=i;j++)
		dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
		cout<<dp[1][1]<<endl;
	}
}

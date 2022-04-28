#include<bits/stdc++.h>
using namespace std;
const int maxn =4e4+10;
const int N =70;
vector<int>g[maxn];
struct node{
	int cost;
	int val;
}s[N];
int dp[N][maxn];
 
void dfs(int rt,int m){
	if(m==0){
		return;
	}
	for(int i=0;i<g[rt].size();i++){
		int u=g[rt][i];
		for(int j=0;j<=m;j++){
			dp[u][j]=dp[rt][j];
		}
		dfs(u,m-s[rt].cost);
		for(int j=m;j>=s[u].cost;j--){
			dp[rt][j]=max(dp[rt][j],dp[u][j-s[u].cost]+s[u].cost*s[u].val);
		}
	}
}
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		for(int i=0;i<=n;i++){
			g[i].clear();
		}
		int r,c,x;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&s[i].cost,&s[i].val,&x);
			g[x].push_back(i);
		}
		memset(dp,0,sizeof(dp));
		dfs(0,m);
		printf("%d\n",dp[0][m]);
	}
	return 0;
}

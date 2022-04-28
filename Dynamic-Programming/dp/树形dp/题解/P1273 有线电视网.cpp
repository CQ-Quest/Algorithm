#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int maxn=1e7+10;
int n,m;
int head[3010],k;
int val[3010];
int dp[3010][3010];
struct node{
	int to,next,w;
}edge[maxn];
void adde(int u,int v,int w)
{
	edge[++k].to=v;
    edge[k].next=head[u];
	edge[k].w=w,head[u]=k;
}
int dfs(int u)
{
	if(u>n-m){
		dp[u][1]=val[u];
		return 1;
	} 
	int sum=0,t;
	for(int k=head[u];k;k=edge[k].next){
		int v=edge[k].to;
		t=dfs(v);
		 sum+=t; 
		for(int j=sum;j>0;j--){
			for(int i=1;i<=t;i++)//遍历组中的元素，选多少个用户相当于一个元素 
			{
				if(j-i>=0) dp[u][j]=max(dp[u][j],dp[u][j-i]+dp[v][i]-edge[k].w);
			}
		}
	}
	return sum;
}
int main()
{
	memset(dp,-INF,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int u=1;u<=n-m;u++)
	{
		int size,v,w;
		scanf("%d",&size);
		for(int j=1;j<=size;j++)
		{
			scanf("%d%d",&v,&w);
			adde(u,v,w);
		}
	}
	for(int i=n-m+1;i<=n;i++) scanf("%d",&val[i]);
	for (int i=1;i<=n;i++) dp[i][0]=0;//选0个用户的花费肯定是0啦
	dfs(1);
	for (int i=m;i>=1;i--)
        if (dp[1][i]>=0)
		{
            printf("%d\n",i);
            break;
        }
	return 0;
}

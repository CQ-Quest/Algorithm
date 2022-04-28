#include<bits/stdc++.h>

using namespace std;
const int N = 50010;
int n;
int sum[N];//约数之和 
int idx = 0;
int d1[N],d2[N];//最大值，次大值 
int h[N],e[N<<1],ne[N<<1];
void add(int x,int y)
{
	e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
int dfs(int u,int fa)
{
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fa) continue;
		int d=dfs(j,u)+1;
		if(d>=d1[u]){
			d2[u]=d1[u];
			d1[u]=d;
		}
		else if(d>d2[u]) d2[u]=d;
	}
	return d1[u];
}

int main()
{
	memset(h,-1,sizeof h); 
	scanf("%d",&n); 
	for(int i=1;i<=n;++i)
	{
		for(int j=2;j <=n/i;++j)
		{
			sum[j * i] += i;
		}
	}
	for(int i=2;i<=n;++i)
	{
		if(sum[i] < i)
		{
			//add(i,sum[i]);
			add(sum[i],i);
		}
	}
	dfs(1,-1);
	int ans= 0;
	for(int i=1;i<=n;++i)
		ans = max(ans,d1[i]+d2[i]);
	printf("%d\n",ans);
	return 0;
}

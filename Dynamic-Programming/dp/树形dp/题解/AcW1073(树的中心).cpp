#include<bits/stdc++.h>
using namespace std;
int idx,n;
const int N=1e4+10;
#define INF 0x3f3f3f3f
int h[N<<1],e[N<<1],ne[N<<1];
int w[N],d1[N],d2[N];
void add(int x,int y,int z){
    w[idx]=z;
    e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
int p1[N],up[N];
int dfs(int u,int fa){
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fa) continue;
		int d=dfs(j,u)+w[i];
		if(d>=d1[u]){
			d2[u]=d1[u];
			d1[u]=d;
			p1[u]=j;//当前经过路径的结点编号 
		}
		else if(d>d2[u]) d2[u]=d;
	}
	return d1[u];
}

void dfs1(int u,int fa){
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fa) continue;
		if(p1[u]==j) up[j]=max(up[u],d2[u])+w[i];
		else up[j]=max(up[u],d1[u])+w[i];
		dfs1(j,u);
	}
}
void init(){
	idx=0;
	memset(h,-1,sizeof h);
}
int main()
{
	init();
	scanf("%d",&n);
	for(int i=2;i<=n;++i)
	{
		int u,v,z;
		scanf("%d%d%d",&u,&v,&z);
		add(u,v,z),add(v,u,z);
	}
	dfs(1,-1);
	dfs1(1,-1);
	int ans = INF;
	for(int i=1;i<=n;++i)
		ans = min(ans,max(up[i],d1[i]));
	printf("%d\n",ans);
		
	return 0;
}

/*Ê÷ÐÎdp
Ê÷µÄÖ±¾¶ 
*/
#include<bits/stdc++.h>
using namespace std; 
const int N=2e5+10;
int ne[N<<1],e[N<<1],h[N<<1],w[N<<1];
int d1[N],d2[N];
int n,idx;
void add(int x,int y,int z){
	w[idx]=z;
	e[idx]=y,ne[idx]=h[x],h[x]=idx++; 
}
int dfs(int u,int fa){
	for(int i=h[u];~i;i=ne[i]){
		int j=e[i];
		if(j==fa) continue;
		int d=dfs(j,u)+w[i];
		if(d>=d1[u]){
			d2[u]=d1[u];
			d1[u]=d;
		}
		else if(d>d2[u]) d2[u]=d;
	}
	return d1[u];
}
void init(){
	idx=0;
	memset(h,-1,sizeof h);
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=2;i<=n;i++){
		int u,v,z;
		scanf("%d%d%d",&u,&v,&z);
		add(u,v,z),add(v,u,z);
	}
	dfs(1,-1);
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,d1[i]+d2[i]);
	printf("%d\n",ans);
	return 0;
} 

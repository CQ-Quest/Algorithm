#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N=3e4+10;
int h[N<<1],ne[N<<1],e[N<<1],w[N];
int f[500][500];
int n,m,idx;
void add(int x,int y,int z){
	w[idx]=z;
    e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}
void init(){
	idx=0;
	memset(h,-1,sizeof h);
}
void dfs(int u,int fa){
	f[0][0]=0;
	for(int i=h[u];i!=-1;i=ne[i]){
		int v=e[i];
		if(v==fa) continue;
		dfs(v,u);
		for(int j=m;j>=0;j--)
		for(int k=0;k<j;k++)
		f[u][j]=max(f[u][j],f[v][k]+f[u][j-k-1]+w[i]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=2;i<=n;i++){
		int u,v,z;
		scanf("%d%d%d",&u,&v,&z);
		add(u,v,z),add(v,u,z);
	} 
    dfs(1,-1);
   printf("%d\n",f[1][m]);
    return 0;
} 

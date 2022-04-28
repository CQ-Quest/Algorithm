#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
const int N = 2000;
int h[N],e[N*2],ne[N*2],idx;
int f[N][3];
int w[N];
int n;

void add(int x,int y)
{
	e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}

void dfs(int u,int fa)
{
    f[u][1] = w[u];
    f[u][0] = 0;
    for(int i=h[u];~i;i=ne[i])
    {
        int v = e[i];
        if(v == fa) continue;
        dfs(v,u);
        f[u][1] += min(f[v][0],min(f[v][1],f[v][2]));
        f[u][0] += min(f[v][1],f[v][2]);
    }
    f[u][2] = INF;
    for(int i=h[u];~i;i=ne[i])
    {
    	int v = e[i];
    	if(v == fa) continue;
    	f[u][2] = min(f[u][2],f[v][1] + f[u][0] - min(f[v][1],f[v][2]));
    }
}

int main()
{
    memset(h,-1,sizeof h);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int u,k;
        scanf("%d",&u);
        scanf("%d%d",&w[u],&k);
        while(k--)
        {
            int v;
            scanf("%d",&v);
            add(u,v),add(v,u);
        }
    }
    dfs(1,-1);
    printf("%d\n",min(f[1][1],f[1][2]));
    return 0;
}

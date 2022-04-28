/*
因为每条边都要被观察到
所以父结点不选子节点一定要选
父结点选子节点可以选或不选
表示为转移方程就是
f[u][0] += f[v][1];
f[u][1] += min(f[v][1],f[v][0]);
*/ 

#include<bits/stdc++.h>

using namespace std;
const int N = 2000;

int f[N][2];//0表示不选当前结点，1表示选择当前结点 
int n;

int h[N],e[N<<1],ne[N<<1],idx;
void add(int x,int y)
{
	e[idx]=y,ne[idx]=h[x],h[x]=idx++;
}

void dfs(int u,int fa)
{
    f[u][1] = 1,f[u][0] = 0;
    for(int i=h[u];~i;i=ne[i])
    {
        int v = e[i];
        if(v == fa) continue;
        dfs(v,u);
        f[u][1] += min(f[v][1],f[v][0]);
        f[u][0] += f[v][1];
    }
}

void init()
{
    memset(h,-1,sizeof h);
    idx = 0;
}

int main()
{
    while(~scanf("%d",&n))
    {
        init();
        for(int i=0;i<n;++i)
        {
            int u,k;
            scanf("%d:(%d)",&u,&k);
            while(k--)
            {
                int v;
                scanf("%d",&v);
                add(u,v),add(v,u);
            }
        }
        dfs(1,-1);
        printf("%d\n",min(f[1][1],f[1][0]));
    }
    
    return 0;
}

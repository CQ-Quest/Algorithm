//Count on a tree 主席树+倍增dfn
//主席树，m个版本，每次建树4logn  则复杂度O(mlogn)
/*难以做修改操作，懒标记过多，主席树可持续化的区别：可查询历史版本*/ 
#include <cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;
const int N = 1e5 + 10;
int n, m;
struct ChairmanTree
{
    int l, r;
    int cnt;          //记录区间共有多少个数
} tr[N * 4 + N * 17]; // 4logN+logN
int root[N], idx,t;
vector<int> num;
int fa[N][20], deep[N];
int w[N];
int find(int x)
{
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}
int h[N<<2],ne[N<<2],e[N<<2];
void add(int a,int b){
    e[t]=b,ne[t]=h[a],h[a]=t++;
}
int build(int l, int r) //l,r表示左右儿子
{
    int p = ++idx;
    if (l == r)
        return p;
    int mid = l + r >> 1;
    tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
    return p;
}
int insert(int p, int l, int r, int x)
{
    int q = ++idx;
    tr[q] = tr[p];
    if (l == r)
    {
        tr[q].cnt++;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid)
        tr[q].l = insert(tr[p].l, l, mid, x);
    else
        tr[q].r = insert(tr[q].r, mid + 1, r, x);
    tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
    return q;
}
int query(int q, int p,int Lca,int FLca,int l, int r, int k)
{
    if (l == r)
        return r;
    int cnt = tr[tr[q].l].cnt+tr[tr[p].l].cnt-tr[tr[Lca].l].cnt-tr[tr[FLca].l].cnt;
    int mid = l + r >> 1;
    if (k <= cnt)
        return query(tr[q].l, tr[p].l,tr[Lca].l,tr[FLca].l, l, mid, k);
    else
        return query(tr[q].r, tr[p].r,tr[Lca].r,tr[FLca].r,mid + 1, r, k - cnt);
}

void dfs(int x,int father)
{
	deep[x]=deep[father]+1;
	root[x]=insert(root[father],0,num.size()-1,find(w[x]));
	fa[x][0]=father;
	for(int i=1;i<=17;i++)
	{
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=h[x];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(j==father) continue;
		dfs(j,x);
	}
}
int LCA(int x,int y){
    if(deep[x]<deep[y])  swap(x,y);  //让x位于更底层，即x的深度值更大
    //（1）把x和y提到相同的深度
    for(int i=19;i>=0;i--)           //x最多跳19次：2^19 = 500005
        if(deep[x]-(1<<i)>=deep[y])          //如果x跳过头了就换个小的i重跳
            x = fa[x][i];            //如果x还没跳到y的层，就更新x继续跳
    if(x==y)  return x;              //y就是x的祖先
    //（2）x和y同步往上跳，找到LCA
    for(int i=19;i>=0;i--)           //如果祖先相等，说明跳过头了，换个小的i重跳
        if(fa[x][i]!=fa[y][i]){      //如果祖先不等，就更新x、y继续跳
            x=fa[x][i];
            y=fa[y][i];
        }
    return fa[x][0];          //最后x位于LCA的下一层，父结点fa[x][0]就是LCA
}
int main()
{
    memset(h,-1,sizeof h);
    scanf("%d%d", &n, &m);
   for(int i=1;i<=n;i++) scanf("%d",&w[i]),num.push_back(w[i]);
   sort(num.begin(),num.end());
   num.erase(unique(num.begin(),num.end()),num.end());
    for(int i=2;i<=n;i++)
    {
        int u,v;scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
    }
    root[0]=build(0,num.size()-1);
    deep[0]=0;
    dfs(1,0);
    while(m--){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
       printf("%d\n",num[query(root[r],root[l],root[LCA(l,r)],root[fa[LCA(l,r)][0]],0,num.size()-1,k)]);
    }

    return 0;
}

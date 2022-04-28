/*2021牛客多校第七场 F xay loves trees，求最大子集
动态主席树dfs序+懒标记
dfs序性质:dfs序的区间要么某个区间全部包含某个区间，要不就是两个区间没有交集
在第二棵树上跑一边dfs，得到了dfs序，每个点就有一个区间[l,r]
主席树维护从根节点到链上的最大深度。每次插入新节点，询问不符合节点的id,
由于区间不相交，这样的值最多一个
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=3e5+5;
typedef long long ll;
struct ChairmanTree
{
    int l, r;
    int sum,add;         
} tr[N *32];//可持续化数组记得开大

int deep[N],n;
int root[N],idx;

int e[N*2],h[N*2],ne[N*2],idx1; 
void add(int x,int y){
    e[idx1]=y,ne[idx1]=h[x],h[x]=idx1++;
}

int e2[N*2],h2[N*2],ne2[N*2],idx2;
void add2(int x,int y){
    e2[idx2]=y,ne2[idx2]=h2[x],h2[x]=idx2++;
}

void insert(int &q,int p, int l, int r, int L,int R,int x) //l,r为左右儿子结点
{
     q = ++idx;
    tr[q] = tr[p];
    tr[q].sum=x;
    if (l>=L&&r<=R) {tr[q].add=x;return;}
    int mid = l + r >> 1;
    if (L <= mid)
        insert(tr[q].l,tr[p].l,l,mid,L,R,x);
    if(R>mid)
        insert(tr[q].r,tr[p].r,mid+1,r,L,R,x);
}
int query(int &u,int l,int r,int L,int R) {
	if(!u) return 0;
	int ans=tr[u].add;
	if(l>=L&&r<=R) return max(ans,tr[u].sum);
	int mid=(l+r)>>1;
	if(L<=mid) ans=max(ans,query(tr[u].l,l,mid,L,R));
	if(R>mid) ans=max(ans,query(tr[u].r,mid+1,r,L,R));
	return ans;
}

int L[N],R[N],cnt;
void dfs2(int x,int fa)
 {
 	L[x]=++cnt;
 	for(int i=h2[x];i!=-1;i=ne2[i])
 	{
        int j=e2[i];
 		if(j==fa)	continue;
 		dfs2(j,x);
 	}
 	R[x]=cnt;
 }

/*在第一棵树上dfs的时候维护根到当前点的一条链，建立一颗线段树，
当到某个点的时候就将这个点的dfs序的区间全部赋值为deep[u],
查询时只需要查当前点的dfs序区间[l,r]内的最大值*/
 int res=0;//存储最大子集
void dfs(int u,int fa,int d)
 {	
 	deep[u]=deep[fa]+1;
 	int now=max(d,query(root[fa],1,n,L[u],R[u]));
 	res=max(res,deep[u]-now);
 	insert(root[u],root[fa],1,n,L[u],R[u],deep[u]);
 	for(int i=h[u];i!=-1;i=ne[i])
 	{
         int j=e[i];
 		if(j==fa)	continue;
 		dfs(j,u,now);
 	}
 }
void init(){
    res=0,idx2=0,idx=0,idx1=0,cnt=0;
    
    memset(h,-1,sizeof h);
    memset(h2,-1,sizeof h2);
    
    memset(root,0,sizeof root);
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        init();
        scanf("%d",&n);
       for(int i=2;i<=n;i++){
           int u,v;scanf("%d%d",&u,&v);
           add(u,v),add(v,u);
       }
        for(int i=2;i<=n;i++){
            int u,v;scanf("%d%d",&u,&v);
            add2(u,v),add2(v,u);
        }
        dfs2(1,0);
        dfs(1,0,0);
        printf("%d\n",res);
    }

    return 0;
}
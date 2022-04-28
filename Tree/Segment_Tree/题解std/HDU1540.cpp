/* 
Tunnel Warfare HDU - 1540
D x 摧毁第x个村庄
Q x 查询第x个村庄连接其他村庄的数量
R   重建上个摧毁的村庄
*/
#include <cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
const int N=5e4;
struct node
{
	int ll,rl,ml;
}tree[N<<2];
int n,m,x;
stack<int> sk;
void build(int rt,int l,int r)
{
	tree[rt].ll=tree[rt].rl=tree[rt].ml=r-l+1;
    int mid=l+r>>1;
	if(l==r) return;
	build(rt<<1,l,mid),build(rt<<1|1,mid+1,r);
}
void modify(int rt,int x,int c,int l,int r)
{
	if(x<l||x>r) return;
	if(l==r) 
	{
		tree[rt].ll=tree[rt].rl=tree[rt].ml=c;
		return;
	}
    int mid=l+r>>1;
	modify(rt<<1,x,c,l,mid);
	modify(rt<<1|1,x,c,mid+1,r);
	//最大连续长度是 1.左儿子最大长 2.右儿子最大长 3.左儿子右边界+右儿子左边界最大长 之一 
	tree[rt].ml=max(max(tree[rt<<1].ml,tree[rt<<1|1].ml),tree[rt<<1].rl+tree[rt<<1|1].ll);
	
    tree[rt].ll=tree[rt<<1].ll;//最大左长为左儿子左长，若左儿子左长满区间，则要加右儿子左长 
	if(tree[rt].ll==mid-l+1) tree[rt].ll+=tree[rt<<1|1].ll;
	
    tree[rt].rl=tree[rt<<1|1].rl;//最大右长同理 
	if(tree[rt].rl==r-mid) tree[rt].rl+=tree[rt<<1].rl;
}
int query(int rt,int l,int r,int x)
{
	//叶子结点 或 完全连续 或 完全不连续 直接返回 
	if(l==r||tree[rt].ml==r-l+1||!tree[rt].ml) return tree[rt].ml;
    int mid=l+r>>1;
	if(x<mid+1-tree[rt<<1].rl) return query(rt<<1,l,mid,x);//在中间地带左侧 
	if(x>mid+tree[rt<<1|1].ll) return query(rt<<1|1,mid+1,r,x);//在中间地带右侧 
	return tree[rt<<1].rl+tree[rt<<1|1].ll;//在中间地带直接返回加合 
}
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		build(1,1,n);
		while(m--)
		{
			char op[3];
            scanf("%s",op);
			if(*op=='D') 
            scanf("%d",&x),modify(1,x,0,1,n),sk.push(x);
			else if(*op=='R')
             modify(1,sk.top(),1,1,n),sk.pop();
			else 
            scanf("%d",&x),printf("%d\n",query(1,1,n,x));
		}
	}
	return 0;
}

//P1969 积木大赛，每次只能对一个区间+1或者减1
// #include<cstdio>
// #include<cstring>
// #define lowbit(x) (x&-x)
// using namespace std;
// typedef long long ll;
// const int N=1e5+10;
//     int n;
// int w[N],tr[N];
// void add(int x,int y){
//      for(int i=x;i<=n;i+=lowbit(i))
//      tr[i]+=y;
// }
// ll getsum(int x){
//     ll ans=0;
//     for(int i=x;i;i-=lowbit(i))
//        ans+=tr[i];
//        return ans;
// }
// int main(){
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++) scanf("%d",&w[i]);
//     for(int i=2;i<=n;i++)
//     if(w[i]>w[i-1]) add(i,w[i]-w[i-1]);
//     printf("%lld\n",getsum(n)+w[1]);
//     return 0;
// }
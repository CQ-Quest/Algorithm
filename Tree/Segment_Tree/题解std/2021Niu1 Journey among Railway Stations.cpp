//单点修改，修改区间长度，询问
/*题目大意
   一段路上有 N 个点，每个点有一个合法时间段 [u_i, v_i]，相邻两个点有一个长度。每次问，在 u_i 的时间从 i 出发后，
   能否依次经过 i+1~j 的所有点，使得到达时间满足每个点的合法区间（如果提前到可以等待，迟到了失败了）。
   同时还可能修改一段路的长度，或者修改一个点的合法时间段。
   N, Q <= 1000000
*/
//设d(u_i)= u_i+d_i+di+1+…+dn-1,d(v_i)= vi+d_i+di+1+…+ dn-1
//现在(l, r)的限制变成了:d(u_i)≤d(v_i), max(d(u1), d(u2))≤d(v2),max(d(u1),d(u2),d(u3))≤v3
//线段树维护当前区间是否可行、u的最大值和v的最小值，复杂度是O(NlogN)。
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
typedef long long ll;
struct node{
	int l,r;
	int maxu,minv,w;
	bool flag;
}tr[N * 4];
int n,m,U[N],v[N],w[N];
node merge(node l,node r,int cost)  //区间合并
{
    node ans;
    ans.flag= l.flag&r.flag;
    if(l.maxu+cost> r.minv) ans.flag=0;
    ans.maxu=max(r.maxu,l.maxu+cost+r.w);
    ans.minv=min(l.minv,r.minv-cost-l.w);
    ans.w=l.w+r.w+cost;
    return ans;
}

void build(int u,int l,int r){
	tr[u] = {l,r};
	if(l == r){
		tr[u] = {l,r,U[l],v[l],0,1};
		return;
	}
	int mid = l + r >> 1;
	build(u << 1,l,mid);
	build(u << 1 | 1,mid + 1,r);
	tr[u] = merge(tr[u << 1],tr[u << 1 | 1],w[mid]);
}

node query(int u,int l,int r){
	if(tr[u].l >= l && tr[u].r <= r) return tr[u];
	int mid = tr[u].l + tr[u].r >> 1;
	if(r <= mid) return query(u << 1,l,r);
	else if(l > mid) return query(u << 1 | 1,l,r);
	else return(merge(query(u << 1,l,r),query(u << 1 | 1,l,r),w[mid]));
}

void modify(int u,int x){
	if(tr[u].l == tr[u].r){
		tr[u] = {x,x,U[x],v[x],0,1};
		return;
	}
	int mid = tr[u].l + tr[u].r >> 1;
	if(x <= mid) modify(u << 1,x);
	else modify(u << 1 | 1,x);
	tr[u] = merge(tr[u << 1],tr[u << 1 | 1],w[mid]);
}

int main(){
    int t; scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&U[i]);
        for(int i=1;i<=n;i++) scanf("%d",&v[i]);
        for(int i=1;i<n;i++) scanf("%d",&w[i]);
        build(1,1,n);
        
        scanf("%d",&m);
        while(m--){
            int op; scanf("%d",&op);
            if(op==1){
                int x,v; scanf("%d%d",&x,&v);
                w[x]=v;
                modify(1,x);
            }
            else if(op==0){
                int l,r;scanf("%d%d",&l,&r);
                if(query(1,l,r).flag) puts("Yes");
				else puts("No");
            }
            else{
                int x,p,q;scanf("%d%d%d",&x,&p,&q);
                U[x]=p,v[x]=q;
                modify(1,x);
            }
        }
    }
    return 0;
}

//对于一个数, (x+lowbit)/2+(x-lowbit)/2=x,查询的结果为其本身，求(w*2^(n*m))%mod
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+999;
#define int long long
int n,m;
typedef long long ll;
ll mod=998244353;
struct Segment{
    int l,r;
    ll sum,add;
}tr[N<<2];
void pushup(int u){
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%mod;
}
// void pushdown(int u){
//     auto &root=tr[u],&L=tr[u<<1],&R=tr[u<<1|1];
//     if(root.add){
//     L.add+=root.add,L.sum+=(ll)(L.r-L.l+1)*root.add;
//     R.add+=root.add,R.sum+=(ll)(R.r-R.l+1)*root.add;
//     root.add=0;
//     }
// }
ll qsm(ll d,ll z){
    ll res=1;
    d%=mod;
    while(z){
        if(z&1) res=(res*d)%mod;
        z>>=1;
        d=(d*d)%mod;
    }
    return res;
}
ll w[N];
void build(int u,int l, int r){
    tr[u]={l,r,w[r],0};
    if(l!=r){
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
ll query(int u,int l,int r,int L,int R){
    if(L>=l&&R<=r) return tr[u].sum;
    int mid=L+R>>1;
    ll sum=0;
    if(l<=mid) sum=(sum+query(u<<1,l,r,L,mid))%mod;
    if(r>mid)  sum=(sum+query(u<<1|1,l,r,mid+1,R))%mod;
    return sum;
}
signed main(){
    int t;scanf("%lld",&t);
    while(t--){
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&w[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
      int op,l,r;
      scanf("%lld%lld%lld",&op,&l,&r);
      if(op==2) printf("%lld\n",query(1,l,r,1,n)%mod*qsm(2,n*m)%mod);
    }

    }
    return 0;
}


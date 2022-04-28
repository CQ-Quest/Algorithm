#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
const int N=1e5+10;
typedef long long ll;
ll mod=998244353;
struct Segment{
    ll sum,add,mul,w;  //add为乘法标记，mul标记是否出现
}tr[N<<2];
ll qsm(ll d,ll z){
    d%=mod;
    ll res=1;
    while(z){
        if(z&1) res=(d*res)%mod;
        z>>=1;
        d=(d*d)%mod;
    }
    return res;
}
void pushup(int u){
    tr[u].sum=(tr[u<<1].sum+tr[u<<1|1].sum)%mod;
    tr[u].mul=min(tr[u<<1].mul,tr[u<<1|1].mul);
}
void pushdown(int u){
    auto &root=tr[u],&L=tr[u<<1],&R=tr[u<<1|1];
    if(root.add==1) return;
        L.add=(L.add*root.add)%mod,L.sum=(ll)L.sum*root.add%mod;
        R.add=(root.add*R.add)%mod,R.sum=(ll)R.sum*root.add%mod;
        root.add=1;
}
void build(int u,int l,int r){
    if(l==r){
        scanf("%lld",&tr[u].w);
        tr[u].sum=tr[u].w;
        tr[u].add=1,tr[u].mul=0;
        if((ll)lowbit(tr[u].sum)==tr[u].sum)
        tr[u].mul=1;  
    }
    else{
        tr[u].add=1;
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
void modify(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R&&tr[u].mul==1){
        tr[u].sum=(ll)(tr[u].sum*2)%mod;
        tr[u].add=(ll)(tr[u].add*2)%mod;
        return ;
    }
    if(l==r){
        tr[u].sum=(tr[u].sum+lowbit(tr[u].sum));
        if(tr[u].sum==(ll)lowbit(tr[u].sum)) tr[u].mul=1;
        return;
    }
    pushdown(u);
    int mid=l+r>>1;
    if(L<=mid) modify(u<<1,l,mid,L,R);
    if(R>mid) modify(u<<1|1,mid+1,r,L,R);
    pushup(u);
}
ll query(int u,int l,int r,int L,int R){
    if(l>=L&&r<=R) return tr[u].sum;
    pushdown(u);
    int mid=l+r>>1;
    ll sum=0;
    if(L<=mid) sum=(sum+query(u<<1,l,mid,L,R))%mod;
    if(R>mid) sum=(sum+query(u<<1|1,mid+1,r,L,R))%mod;
    return sum;
}
int main(){
    int t;scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        build(1,1,n);
        int m;
        scanf("%d",&m);
        while(m--){
            int op,l,r;
            scanf("%d%d%d",&op,&l,&r);
            if(op==1){
                modify(1,1,n,l,r);
            }
            else printf("%lld\n",query(1,1,n,l,r));
        }
    }
    return 0;
} 
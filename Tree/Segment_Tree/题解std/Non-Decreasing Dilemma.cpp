/*
1 x y 修改ax=y，x为下标
2 l r 区间[l,r]内存在多少个non-decreasing subarrays.

如果当前节点的左子树可以一直不降到右子树
假设左子树右边的不降长度为L.rmax，右子树左边的不降长度为R.lmax
那么我们每次从左子树取长度为一接到右子树的不降长度上，根节点的sub就会多一个；
以此类推，那么一共会多L.rmax * R.lmax个
*/
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int n,m;
int w[N];
typedef long long ll;
struct Segment{
    int l,r;
    ll lmax,rmax,len,sum;   //前缀，后缀
}tr[N<<2];
Segment pushup(Segment &L,Segment &R){
    Segment u;
    u.lmax=L.lmax,u.rmax=R.rmax;
    u.l=L.l,u.r=R.r;
    u.sum=L.sum+R.sum;
    u.len=L.len+R.len;
    if(L.rmax<=R.lmax){
        if(L.l==L.len)u.l=L.l+R.l;
        if(R.r==R.len)u.r=L.r+R.r;
        u.sum=L.sum+R.sum+(ll)R.l*L.r;
    }
    return u;
}
void pushup(int u){
    tr[u]=pushup(tr[u<<1],tr[u<<1|1]);
}
void build(int u,int l,int r){
    tr[u]={1,1,w[r],w[r],1,1};
    if(l!=r){
        tr[u]={l,r};
        int mid=l+r>>1;
     build(u<<1,l,mid),build(u<<1|1,mid+1,r);
     pushup(u);
    }
}
void modify(int u,int l,int r,int x,int v){
    if(l==r){
      tr[u].lmax=v;
      tr[u].rmax=v;
        return;
    }
    int mid=l+r>>1;
    if(x<=mid) modify(u<<1,l,mid,x,v);
    else modify(u<<1|1,mid+1,r,x,v);
    pushup(u);
}
Segment query(int u,int l,int r,int L,int R){
    if(r<L||l>R) {Segment u; return u;}
    if(l>=L&&r<=R) return tr[u];
    int mid=l+r>>1;
    Segment al=query(u<<1,l,mid,L,R);
    Segment ar=query(u<<1|1,mid+1,r,L,R);
    if(R<=mid) return al;
    else if(L>mid) return ar;
    else return pushup(al,ar);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op,l,r;
        scanf("%d%d%d",&op,&l,&r);
        if(op==1){
            modify(1,1,n,l,r);
        }
        else printf("%lld\n",query(1,1,n,l,r).sum);
    }
    return 0;
}
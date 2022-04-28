/*
Frequent values POJ - 3368 
求区间内众数的个数

sum用来记录这段区间出现最多的次数的个数，
lmax用来记录最左边那个数在这段区间连续的个数，
rmax用来记录最右边那个数在这段区间连续的个数
*/

#include<cstdio>
#include<cmath>
#include<algorithm>
const int N=1e5+10;
using namespace std;
 int n,m;
 int w[N];
struct node
{
    int l,r;
    int sum;
    int lmax,rmax;    
 
}tr[N<<2];
node pushup(node &L,node &R){
    node root;
    root.l=L.l,root.r=R.r;
    if(L.l==R.l) root.lmax=L.lmax+R.lmax;
    else root.lmax=L.lmax;
    
    if(L.r==R.r) root.rmax=L.rmax+R.rmax;
    else root.rmax=R.rmax;
     
     root.sum=max(L.sum,R.sum);
    if(L.r==R.l) root.sum=max(root.sum,L.rmax+R.lmax);
    return root;
}
void pushup(int u){
    tr[u]=pushup(tr[u<<1],tr[u<<1|1]);
}

void build(int u,int l,int r){
    if(l==r) tr[u]={w[l],w[r],1,1,1};
    else{
        int mid=l+r>>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }
}
node query(int u,int l,int r,int L,int R){
    if(r<L||R<l) {node x;return x;}
    if(l>=L&&r<=R) return tr[u];
    int mid=l+r>>1;
    node al=query(u<<1,l,mid,L,R);
    node ar=query(u<<1|1,mid+1,r,L,R);
    if(R<=mid) return al;
    if(L>mid) return ar;
    return pushup(al,ar);
}
 
int main(){
    while(~scanf("%d",&n)&&n){
      scanf("%d",&m);
      for(int i=1;i<=n;i++) scanf("%d",&w[i]);
      build(1,1,n);
      for(int i=1;i<=m;i++){
          int l,r;
          scanf("%d%d",&l,&r);
          printf("%d\n",query(1,1,n,l,r).sum);
      }
    }
    return 0;
}
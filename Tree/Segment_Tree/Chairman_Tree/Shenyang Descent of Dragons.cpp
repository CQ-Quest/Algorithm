//动态主席树,涉及版本更新
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+3;
struct Chairman{
    int l,r;
    int cnt;
}tr[N*40];
int idx,root[N];
int n,m;
int build(int l, int r) //l,r表示左右儿子
{
    int p = ++idx;
    if (l == r) return p;
    
    int mid = l + r >> 1;
    tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
    return p;
}
int insert(int p, int l, int r)  //初始值为0，无需插入其他值
{
    int q = ++idx;
    tr[q] = tr[p];
    if(l==r){
        tr[q].cnt=1;return q;
    }
    int mid = l + r >> 1;
    
        tr[q].l = insert(tr[p].l, l, mid);
        tr[q].r = insert(tr[q].r, mid + 1, r);
    tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
    return q;
}
int query(int q, int p, int l, int r, int L,int R) //l,r为左右儿子
{
   if(l>=L&&r<=R) return tr[q].cnt-tr[p].cnt;
     int sum=0;
    int mid=l+r>>1;
    if(L<=mid) sum+=query(tr[q].l, tr[p].l, l, mid, L,R);
    if(R>mid)  sum+=query(tr[q].r, tr[p].r, mid + 1, r, L,R);
   return sum;
}
void modify(int p,int &q,int &root,int l,int r,int L,int R){  //q,root可移动
    int A = tr[root].cnt - tr[p].cnt;
    if (!A) return ;
    int B = tr[q].cnt - tr[root].cnt;
    if (!B) {  //只要有东西，就拿到q上去, 没拿的，即不变。
        if (l >= L && r <= R) {
            q = root, root = p; return ;
        }
         
        int TL = tr[q].l, TR = tr[q].r; 
        tr[++idx].l = tr[root].l, tr[idx].r = tr[root].r;
          q = root, root = idx; //此时root的cnt不变，因为不知道下面有几个可以不用更改的值
        tr[q].l = TL, tr[q].r = TR; //此时，只需要将需要改变的节点放置到相应的位置上，q肯定是要等于rt的
        // root不等于q，因为这个节点的值并不全是root的东西，但这个节点的东西是q的。
 
    }
    int mid = l + r >> 1;
    if (L <= mid) modify(tr[p].l, tr[q].l, tr[root].l, l, mid, L, R);
    if (R > mid)  modify(tr[p].r, tr[q].r, tr[root].r, mid + 1, r, L, R);
    
    tr[q].cnt=tr[tr[q].l].cnt+tr[tr[q].r].cnt;
    tr[root].cnt=tr[tr[root].l].cnt+tr[tr[root].r].cnt;
}
int main(){
   scanf("%d%d",&n,&m);
    root[0]=build(1,n);
    root[1] = insert(root[0], 1, n); //注意插入操作
    for (int i = 2; i <= m + 1; i++) root[i] = root[1];
    int t=m;
    while(m--){
        int op,L,R,d;
        scanf("%d%d%d",&op,&L,&R);
        if(op==1){
          scanf("%d",&d);d++;
         modify(root[d-1],root[d+1],root[d],1,n,L,R);
        }
        else{
            int l=1,r=t+1;
            int ans = 1;
            while (l <= r) {
                int mid = l + r >> 1;
                int sum = query(root[mid - 1], root[r], 1, n, L, R);
                //询问mid到r中是否有数,有数则说明版本大的是有数的,版本扩大
                if (sum) ans = mid, l = mid + 1; 
                else r = mid - 1;
            }
            printf("%d\n", ans-1);
        }
    }
    return 0;
}
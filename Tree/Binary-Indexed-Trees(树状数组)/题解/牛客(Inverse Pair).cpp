//原数组加上1或者不加，使得逆序数最小,开vis数组标记即可 
#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int tree[maxn]={0},vis[maxn]={0},n,a[maxn];
typedef long long ll;
int lowbit(int x){
	return x&(-x);
}
void add(int x,int y){
	for(;x<=n;x+=lowbit(x)){
		tree[x]+=y;
	}
}
int getsum(int x){
	int ans=0;
	for(;x;x-=lowbit(x)) 
	ans+=tree[x];
	return ans;
} 
// bool cmp(node a,node b){
// 	if(a.val==b.val) return a.num<b.num;
// 	return a.val<b.val;
// }
int main()
{
    ll ans=0,cnt=0;
	int m=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)  scanf("%d",&a[i]),m=max(a[i],m);
    for(int i=1;i<=n;i++){
    	ans+=getsum(m)-getsum(a[i]);
    	add(a[i],1);
	}
    for(int i=1;i<=n;i++){
           if(vis[a[i]+1]==1) cnt++;
           else vis[a[i]]=1;
       }
       printf("%lld\n",ans-cnt);
   return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int tree[maxn],r[maxn],n;
typedef long long ll;
int lowbit(int x){
	return x&(-x);
}
struct node{
	int num,val;
}a[maxn];
void add(int x,int y){
	int ans=0;
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
bool cmp(node a,node b){
	if(a.val==b.val) return a.num<b.num;
	return a.val<b.val;
}
int main(){
	ios::sync_with_stdio(0);
	while(cin>>n){
		memset(tree,0,sizeof tree);
		memset(r,0,sizeof r); 
	for(int i=1;i<=n;i++){
		cin>>a[i].val;
		a[i].num=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		r[a[i].num]=i;
	}
	ll ans=0;
	for(int i=n;i>0;--i){
        ans+=getsum(r[i]);
        add(r[i],1);
	}
	cout<<ans<<endl;
}
	return 0;
}

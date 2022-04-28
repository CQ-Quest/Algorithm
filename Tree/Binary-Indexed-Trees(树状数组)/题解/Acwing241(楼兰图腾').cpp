/*从左向右依次遍历每个数a[i]，使用树状数组统计在i位置之前所有比a[i]大的数的个数、以及比a[i]小的数的个数。
统计完成后，将a[i]加入到树状数组。

从右向左依次遍历每个数a[i]，使用树状数组统计在i位置之后所有比a[i]大的数的个数、以及比a[i]小的数的个数。
统计完成后，将a[i]加入到树状数组。

时间复杂度 O(nlogn)*/ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200010; 
int a[maxn],n;
int c[maxn],G[maxn],L[maxn];
int lowbit(int x){
	return x& -x;
}
void add(int x,ll y){
	for(int i=x;i<=n;i+=lowbit(i))
	c[i]+=y;
}
ll getsum(int x){
	ll ans=0;
	for(int i=x;i;i-=lowbit(i))
	ans+=c[i];
	return ans;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int y=a[i];
		G[i]=getsum(n)-getsum(y);
		L[i]=getsum(y-1);
		add(y,1);
	}
	memset(c,0,sizeof c);
	ll res1=0,res2=0;
	for(int i=n;i;i--){
		int y=a[i];
		res1+=G[i]*(ll)(getsum(n)-getsum(y));
		res2+=L[i]*(ll)(getsum(y-1));
		add(y,1);
	}
	cout<<(ll)res1<<" "<<(ll)res2<<endl;
	return 0;
}

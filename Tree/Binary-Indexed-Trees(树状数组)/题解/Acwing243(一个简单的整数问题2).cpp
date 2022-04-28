/*维护两个树状数组即可
一个是差分数组d[i]的树状数组tr[i]，还有一个是i*d[i]的树状数组tri[i]*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long ll;
ll tr1[maxn],tr2[maxn];
int n,m,a[maxn]; 
int lowbit(int x){
	return x&(-x);
}
void add(ll tr[],int x,ll c){
	for(int i=x;i<=n;i+=lowbit(i))
	  tr[i]+=c;
}
ll getsum(ll tr[],int x){
	ll ans=0;
	for(int i=x;i;i-=lowbit(i))
	ans+=tr[i];
	return ans;
}
ll qzh(int x){
	return getsum(tr1,x)*(x+1)-getsum(tr2,x);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	    for(int i=1;i<=n;i++){
		ll b=a[i]-a[i-1];
		add(tr1,i,b);
		add(tr2,i,(ll)b*i);
	}
	char op;
	int l,r,d;
	while(m--){
	cin>>op>>l>>r;	
	if(op=='Q'){
	   cout<<(ll)qzh(r)-qzh(l-1)<<endl;	
	} 
	else{
	    cin>>d;
	add(tr1,l,d),add(tr2,l,(ll)l*d);
	add(tr1,r+1, -d),add(tr2,r+1,(ll)(r+1)* -d);
	}
}
	return 0;
}

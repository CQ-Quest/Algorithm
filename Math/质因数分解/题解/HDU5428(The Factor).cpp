#include<bits/stdc++.h>
using namespace std;
const int maxn=250;
typedef long long ll;
ll p[maxn];
ll a[110];
//int f(ll n){
//	int m=0;
//	for(ll i=2;i*i<=n;i++){
//		if(n%i==0){
//			p[++m]=i;
//			c[m]=0;
//			while(n%i==0)
//			n/=i,c[m]++;
//		}
//	}
//	if(n>1) p[++m]=n,c[m]=1;
//	return m;
//}
int main(){
	ios::sync_with_stdio(0); 
	int t;
	cin>>t;
	while(t--){
	   int n;
	   cin>>n;
	   int m=0;
	   memset(p,0,sizeof p);
	   for(int i=0;i<n;i++){
	   	cin>>a[i];
	   	ll b=a[i];
	   	for(int j=2;j*j<=b;j++){
	   		while(b%j==0)
	   		p[m++]=j,b/=j;
		   }
		   if(b>1) p[m++]=b;
	   }
	   sort(p,p+m);
	   if(m>=2) cout<<p[0]*p[1]<<endl;
	   else cout<<"-1"<<endl;
	}
	return 0;
}

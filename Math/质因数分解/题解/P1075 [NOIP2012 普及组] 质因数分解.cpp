#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
   ios::sync_with_stdio(0);
	ll n;
cin>>n;
 for(ll i=2;i<=sqrt(n);i++){
 	if(n%i==0){
 		if(n/i>i)
 		   cout<<n/i<<endl;
 		   else cout<<i<<endl;
	 }
 }
return 0;
}

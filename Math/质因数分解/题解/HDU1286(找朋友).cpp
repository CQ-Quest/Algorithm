#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int Eula(int n){
	int res=1;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			n/=i;
			res*=(i-1);
			while(n%i==0){
				n/=i;
				res*=i;
			}
		}
	}
	if(n>1) res*=n-1;
	return res;
}
int main(){
ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--){
	int n;
	cin>>n;
	cout<<Eula(n)<<endl;
}
return  0;
}

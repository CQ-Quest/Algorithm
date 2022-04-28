#include<bits/stdc++.h>
using namespace std;
const int maxn=200; 
int p[maxn];//记录因子，p【1】为最小因子 
int c[maxn];//因子个数 
int f(int n){
	int m=0;
	for(int i=2;i*i<=n;i++)
	if(n%i==0){
		p[++m]=i,c[m]=0;
		while(n%i==0)
		n/=i,c[m]++;
	}
	if(n>1)  {
	p[++m]=n,c[m]=1;
}
  return m;
} 
int main(){
    ios::sync_with_stdio(0);
	int t;
  while(cin>>t){
  	if(t==1) cout<<"1"<<endl;
  	else{
    f(t);
    int count=f(t);
    cout<<p[1];
    c[1]-=1;
	for(int i=1;i<=count;i++){
		while(c[i]--)
		cout<<"*"<<p[i];
	}	
  }
  cout<<endl;
}
  return 0; 
}

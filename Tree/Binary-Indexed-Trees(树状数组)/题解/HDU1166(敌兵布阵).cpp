#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
int a[maxn]={0},c[maxn]={0},n; 
int lowbit(int x){
	return x&(-x);
}
//void update(int i,int k){
//	while(i<=n){
//		c[i]+=k;
//		i+=lowbit(i);
//	}
//}

void add(int x,int y){  //单点加值 
	for(;x<=n;x+= x&(-x))
       c[x]+=y;
} 
//int getsum(int i){  //计算原数组1~i的前缀和 
//	int res=0;
//	while(i>0){
//		res+=c[i];
//		i-=lowbit(i);
//	}
//	return res;
//}
//树状数组查询前缀和
int getsum(int x){  //单点查值 
	int ans=0;
	for(;x;x-=x&(-x)) 
	ans+=c[x];
	return ans;
} 

//树状数组求逆序对
//void nx(int a[]){
//    for(int i=n;i;i--)
//	{
//		ans+=ask(a[i]);
//		update(a[i],1); 
//		}	
//} 
int main(){
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	int cnt=0;
	while(t--){
		memset(a,0,sizeof a);
		memset(c,0,sizeof c);
		cout<<"Case "<<++cnt<<":"<<endl;
		cin>>n;
		for(int i=1;i<=n;i++){
		cin>>a[i];
	   add(i,a[i]);
	}
		string s;
		int a,b;
		while(cin>>s&&s[0]!='E'){
		  cin>>a>>b;
		  if(s[0]=='Q'){
		  	int sum=getsum(b)-getsum(a-1);
		  	cout<<sum<<endl;
		  }
		  else if(s[0]=='A') add(a,b);
		  else if(s[0]=='S') add(a,-b);
		}
	 
	}
	return 0; 
}

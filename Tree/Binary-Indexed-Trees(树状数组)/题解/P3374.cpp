#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int c[maxn]={0},n,a[maxn],d[maxn];
void add(int x,int y){
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
int getsum(int x){
	int ans=0;
	for(;x;x-=x&(-x)) 
	ans+=c[x];
	return ans;
} 

int main(){
	ios::sync_with_stdio(0);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
		add(i,d[i]);
	}
	while(m--){
		int k;
		cin>>k;
		if(k==1){
			int q,w,e;
			cin>>q>>w>>e;
			add(q,e);
			add(w+1,-e);
		}
		else if(k==2){
			int q;
			cin>>q;
			cout<<getsum(q)<<endl;
		}
	}
	return 0;
} 

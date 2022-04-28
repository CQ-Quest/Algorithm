 #include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn]={0},c[maxn]={0},n,m; 
int lowbit(int x){
	return x&(-x);
}
void add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i))
	c[i]+=y;
}
int getsum(int x){
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
	ans+=c[i];
	return ans;
}

/*
二维树状数组
void add(int x,int y,int z){
int t=y;//注意这里需要使用一个变量保存y的值 
while(x<=n){
    y=t;
    while(y<=n) c[x][y]+=z,y+=lowbit(y);
    x+=lowbit(x); 
}
}
int getsum(int x,int y){
int ans=0,t=y;
while(x){
    y=t;
    while(y) ans+=c[x][y],y-=lowbit(y);
    x-=lowbit(x);
}
return ans;
}
*/

//区间最值
//void build(int n){
//     for(int i=1;i<=n;i++){
//          c[i]=a[i],int t=lowbit(i);
//          for(int j=1;j<t;j*=2) c[i]=max(c[i],c[i-j]);
//    }
//}	   
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) {
		int b=a[i]-a[i-1];
		add(i,b);
	}
	char op;
	int l,r,d;
	while(m--){
		cin>>op;
		if(op=='Q'){
			cin>>l;
			cout<<getsum(l)<<endl;
		}
		else {
			cin>>l>>r>>d;
			add(l,d);
			add(r+1,-d);
		}
	}
	return 0;
} 

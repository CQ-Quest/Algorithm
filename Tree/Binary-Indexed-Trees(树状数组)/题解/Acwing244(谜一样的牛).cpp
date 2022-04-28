/*���ȿ������һͷţ���������Ѿ�ͳ��������֮ǰ������ţ����ˣ���������xͷţ�ߣ������ĸ߶�һ����x+1x+1�����ǲ�ȡ�Ӻ���ǰ���ǵķ�ʽ��������Ϊ��Ŀ�����ˡ�ÿͷţ��֪���Լ�ǰ����Լ�����ţ�ĸ�������һ�������Ӻ���ǰ�����ٿ��Ǻܶ����⡣

����ÿͷţ�ĸ߶ȸ�����ͬ��ȡ������[1,n][1,n]����ˣ����ڵ����ڶ�ͷţ���ԣ���Ӧ���ڳ�ȥ����x+1x+1������[1,n][1,n]�У�ѡȡAn?1+1An?1+1С������������ţ�Դ����ơ�

���罨��һ��ȫ��Ԫ��Ϊ1�����У�ĳ��λ�õ���Ϊ1��������߶Ȼ���֪������ͷţ�ģ���ô������״����ά�������е�ǰ׺�ͣ���ĳ��λ�õ�ǰ׺�͵���Ai+1Ai+1����ʱ���±����Ҫ�ҵ�����ѡ��������󣬽���Ӧλ�õ�1��0.���Զ������λ�á�*/ 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],c[maxn]={0},n,ans[maxn]; 
int lowbit(int x){
	return x&(-x);
}

void add(int x,int u){
    for(int i=x;i<=n;i+=lowbit(i))
    c[i]+=u;
}
int getsum(int x){
    int ans=0;
    for(int i=x;i;i-=lowbit(i))
    ans+=c[i];
    return ans;
}
void modify(int x){
    for(int i=x;i<=n;i+=lowbit(i))
	c[i]--; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
      cin>>n;
	for(int i=2;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++) c[i]=lowbit(i);
	for(int i=n;i;i--){
		int k=a[i]+1;
		int l=1,r=n;
		while(l<r){
			int mid=(l+r)>>1;
			if(getsum(mid)>=k) r=mid;
			else l=mid+1;
		}
		ans[i]=r;
		add(r,-1);

	}
//      for(int i=n;i;i--){
//      	int k=a[i]+1;
//      	modify(a[i] = findKth(k)+1);
// 	 }
	for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
  return 0;
}

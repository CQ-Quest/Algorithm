/*首先考虑最后一头牛。由于它已经统计了在它之前的所有牛，因此，假如它比x头牛高，则它的高度一定是x+1x+1。我们采取从后往前考虑的方式，就是因为题目给出了“每头牛已知在自己前面比自己矮的牛的个数”这一条件，从后往前可以少考虑很多问题。

由于每头牛的高度各不相同且取遍区间[1,n][1,n]，因此，对于倒数第二头牛而言，它应该在除去上述x+1x+1的区间[1,n][1,n]中，选取An?1+1An?1+1小的数。其他的牛以此类推。

假如建立一个全部元素为1的数列，某个位置的数为1代表这个高度还不知道是哪头牛的，那么就用树状数组维护该数列的前缀和，若某个位置的前缀和等于Ai+1Ai+1，此时的下标就是要找的数。选择这个数后，将相应位置的1置0.可以二分这个位置。*/ 
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

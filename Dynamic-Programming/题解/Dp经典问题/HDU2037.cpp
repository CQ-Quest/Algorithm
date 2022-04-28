#include<bits/stdc++.h>
using namespace std;
const int maxn=2020;
int dp[maxn];
struct node{
	int s,e;
}a[500];
bool cmp(node a,node b){
	if(a.s==b.s) return a.e>b.e;
	return a.s<b.s;
}
int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		memset(dp,0,sizeof(dp));
		int temp=-1;
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].s,&a[i].e);
			temp=max(temp,a[i].s);
		}
		sort(a,a+n,cmp);
		int top=n-1,j=n-1;
        for(int i=temp;i>0;i--)
        {
            if(a[top].s<i)
            {
                dp[i]=dp[i+1];
                continue;
            }
            while(top>-1&&a[top].s==i)
            {
                top--;
                continue;
            }
            for(;j>top;j--)
            {
                dp[i]=max(max(dp[i],dp[i+1]),dp[a[j].e]+1);
            }
        }
        //for(int i=lastTime;i>0;i--)
        //printf("dp[%d]:%d\n",i,dp[i]);
        printf("%d\n",dp[1]);
    }
    return 0;
}

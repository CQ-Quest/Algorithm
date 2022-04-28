#include<iostream>
#include<cstring>
using namespace std;
int a[1000009],dp[100009];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		int max1 = 0;
		for(int i=0;i<n;++i)
		{
			dp[i]=1;
			for(int j=0;j<i;++j)
			{
				if(a[j]<a[i])
				{
					dp[i] = max(dp[j]+1,dp[i]);
				}
			}
			max1 = max(max1,dp[i]);
		}
		printf("%d\n",max1);
	}
	return 0;
}

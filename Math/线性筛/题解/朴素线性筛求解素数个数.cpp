#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,b,ans,f,i;
    while(scanf("%d",&n)!=EOF)
    {
	ans=0;
	while(n--)
	{
	    scanf("%d",&b);
	    f=0;
	    for(i=2; i<=sqrt(b*1.0); i++)// i*i<=b 会超时
		if(b%i==0)
		{
		    f=1;
		    break;
		}
	    if(!f)ans++;
	}
	printf("%d\n",ans);
    }
    return 0;
}

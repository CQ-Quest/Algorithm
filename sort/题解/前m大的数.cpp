# 哈希打表

#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
int a[maxn],b[maxn];
int main(){
	int m,n; 
	while(~scanf("%d %d",&n,&m)){
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		b[a[i]+a[j]]++;
		 int flag=1;
        int l=0;
        for(int i=10000;i>=0;i--)
        {
            while(b[i])
            {
                if(flag)
                {
                       printf("%d",i);
                       flag=0;
                }
                else printf(" %d",i);
                b[i]--;
                l++;
                if(l==m) break;
            }
            if(l==m) break;

        }
        printf("\n");
	}
	return 0;
}

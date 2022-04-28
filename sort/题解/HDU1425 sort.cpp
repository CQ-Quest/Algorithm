#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5e5;
typedef long long ll;
int b[1000002];
int main(){
	ll n,m;
	int t,i;
	while(~scanf("%lld %lld",&n,&m)){
		memset(b,0,sizeof(b));
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			b[t+maxn]++;
		}
		for(int i=1000000;i>=0&&m;i--){
			if(b[i]){
				printf("%d",i-maxn);
				m-=1;
				if(m)
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}

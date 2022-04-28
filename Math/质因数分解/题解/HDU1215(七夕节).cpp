///*求因数和*/
//while(~scanf("%lld",&a))
//    {
//        ll ans =0;
//        for(int i=1;i*i<=a;i++)
//        {
//            if(a%i==0)
//            {
//                if(i!=a/i)
//                    ans +=i+a/i; //知道一个因数用n除这个因数即可得到另一个因数，n =√n*√n,遍历这一半即可得到另一半不会遗漏。
//                else
//                    ans +=i;
//                ans %=mod;
//            }
//        }
//        printf("%lld\n",ans%mod);
//    }
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	while(n--){
		 int a;
		 cin>>a;
		ll ans=0;
		for(int i=1;i*i<=a;i++){
			if(a%i==0){
				ans+=i;
				if(i!=a/i&&i!=1)
					ans+=a/i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

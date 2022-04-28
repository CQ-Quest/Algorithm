# 埃式筛  
https://pic1.zhimg.com/80/v2-224a9aeda1e9bf60898f8a3f3cbb182f_720w.png

    埃拉托斯特尼筛法（太长了~）  
    简称：埃氏筛，时间复杂度O(nloglogn)  
    Key code:  

      const int maxn = 100007;  
      bool cheak[maxn];//素数为false   
      int prime[maxn];//存第i个素数的值   
      int cnt;//素数个数   
      void Prime()  
      {  
        for(int i = 2; i <= maxn; i++)  
        {  
          if(!cheak[i])  
          {  
            prime[++cnt] = i;  
            for(int j = i*i; j <= maxn; j += i)  
            cheak[j] = true;  
          }  
        }  
      }  


# 欧式筛
欧几里得筛法~即   欧式筛，复杂度O(n)   
Key code:  

	void Prime()  
	{  
		for(int i = 2; i <= MAXN; i++)  
		{  
			if(!cheak[i])  
		        prime[++cnt] = i;  
			for(int j=1;j<=cnt&&i*prime[j]<=MAXN;j++)  
			{  
				cheak[i*prime[j]] =true;  
				if(i%prime[j] == 0)  
				break;  
			}  
			}  
		}  
	}  

# 大区间筛法
	typedef long long ll;
	bool cheak[maxn];
	bool cheak_small[maxn];
	//对区间[a,b)内的整数执行筛法。isprime[i - a]=true <=> i是素数
	void Prime(ll a,ll b){
		for(ll i=0;i*i<b;i++)  cheak_small[i]=true;
		for(ll i=0;i<b-a;i++) cheak[i]=true;
		for(ll i=2;i<b-a;i++){
			for(ll j=2*i;j*j<b;j+=i) cheak_small[i]=true;
			for(ll j=max(2ll,(a+i-1)/i)*i;j<b;j+=i) cheak[j-a]=false;
			//(a+i-1)/i为[a,b)区间内的第一个数至少为i的多少倍
		}
	}
	int main(){
		ll a,b;
		scanf("%lld %lld",&a,&b); 
			Prime(a,b);
			int cnt=0;
			for(ll j=0; j<b-a; j++)
		{
		    if(cheak[j])cnt++;
		}
		if(a==1)cnt--;
		printf("%d\n",cnt);
		return 0;
	}

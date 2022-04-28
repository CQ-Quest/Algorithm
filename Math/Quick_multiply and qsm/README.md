#快速乘
	
	补充：”取模“运算法则
	(a+b)%c=((a%c)+(b%c))%c
	(a*b)%c=((a%c)*(b%c))%c
	(a-b)%c=((a%c)-(b%c))%c


	思想：快速计算a*b%mod的结果，主要目的是换乘法为加法，防止数据溢出，提高算法效率。
	  实际上，暴力求解方法对于大数据早已远远不能适用，超时很常见~
	  Key code:

	typedef long long ll;
	ll quick_mul(ll a,ll b,ll mod){
		ll s=0;
		while(b){
		if(b&1){                   //b%2=1
			s=(s+a)%mod;
		}
		a=(a+a)%mod;
		b>>=1;                       // b/=2;
	}
	    return s; 
	}


	注：时间复杂度均O（logn）

#快速幂
	
	快速幂适用范围：当计算a^b时，模拟乘法会超时，故应快速计算a^b%mod的结果，通过取模防止数据爆炸溢出，
	      从而提高算法效率，也就是说，时间复杂度大大降低。

	本质：减少一般乘法运算中的重复部分，
	       如计算3^9=3*3*3*3*3*3*3*3*3
	   分步骤：第一步3*3*3*3*3*3*3*3*3
		   第二步3*3*3*3*3*3*3*3*3
		   第三步3*3*3*3*3*3*3*3*3
	   三步完成，时间复杂度接近0（log n）


	Key code:

	   typedef long long ll;
	ll fastpower(l b,l p,l c){    //b是底数，p为指数，c为余数
	ll result=1;
	if(b==0) return 0;
	while(p>0){
	if(p&1)                       //   p%2==1 
	result=(result*b)%c;   
	p>>=1;                        //  p/=2
	b=(b*b)%c; 
	}
	return result;
	}

	注：时间复杂度为O（logn）

# 01背包：拿与不拿问题  
题目    

有N件物品和一个容量为V的背包。第i件物品的费用是w[i]，价值是v[i],   
求将哪些物品装入背包可使价值总和最大。

 基本思路    
 
 打表


	        重量		价值		   dp					    容量					
              wi	         ci  	       <0	1	2	3	4	5	6	7	8	9	10>
     i=0	  0		  0	       <0	0	0	0	0	0	0	0	0	0	0>
      1	  2		  1		   <0 	0	1	1	1	1	1	1	1	1	1>
      2	  3		  3		   <0 	0	1	3	3	4	4	4	4	4	4>
      3	  4		  5		   <0 	0	1	3	5	5	6	8	8	9	9>
      4	  7	          9	      <0	0	1	3	5	5	6	9	9	10      12> 
      
      
      dp[i][j]表示商品价值，i为物品数，j表示容量，dp[2][u]~dp[n][u];  
      
        当j<w[i],不足以放下，不拿   dp[i][j]=dp[i-1][j];
          j>=w[i]时：(1)不拿： 上一物品价值 dp[i-1][j]
                     (2)拿：dp[i-1][j-w[i]]+c[i];      (dp[1][0]+3 , 0+3)=>max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
                     
            ***判定：  
            if(j<w[i])  dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
            
 反无效原则：当前状态只与上一个有关
  
     一维,空间复杂度O(n)
     for(j=m;j>=1;j--)   //从后往前推
     if(j>=w[i])  dp[j]=max(dp[j],dp[j-w[i]]+c[i]);     
     
	   Code:  
		const int maxn=4000;
		int dp[maxn][maxn];
		int w[maxn],c[maxn];
		int main() {
			int N,V;
		    cin>>N>>V;
		    for(int i=1;i<=N;i++){
			cin>>w[i]>>c[i];
		    }
		    for(int i = 1;i<=N;i++)
				for(int j = 0;j<=V;j++){ 
					if(j>=w[i]){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
			    }
					else
						dp[i][j] = dp[i-1][j];
			} 
		    cout<<dp[N][V]<<endl;
		    return 0;
		}
		
         一维优化：
	const int maxn=3000;
	int dp[maxn],w[maxn],c[200];
	int main(){
		int N,V;
		cin>>N>>V;
		for(int i=1;i<=N;i++)
		cin>>w[i]>>c[i];
		for(int i=1;i<=N;i++)
		for(int j=V;j>=w[i];j--)  //滚动数组
		dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
		cout<<dp[N]<<endl;
		return 0; 
	}

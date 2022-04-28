#试除法

    算法复杂度O(sqrt(n))
    int p[20];  //p[]记录因子，p[1]是最小因子。一个int数的质因子最多有10几个
    int c[40];  //c[i]记录第i个因子的个数。一个因子的个数最多有30几个

    void factorization(int n){
        int m = 0;
        for(int i = 2; i*i <= n; i++)
            if(n%i == 0){
               p[++m] = i, c[m] = 0;
               while(n%i == 0)            //把n中重复的因子去掉
                  n/=i, c[m]++;    
            }
        if(n>1)                           //没有被除尽，是素数
           p[++m] = n, c[m] = 1;  
    }

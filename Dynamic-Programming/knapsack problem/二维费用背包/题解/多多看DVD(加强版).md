# 多多看DVD(加强版)

http://www.rqnoj.cn/problem/95  

      //M是第一个限制条件，每个的费用均为1,满包
      //L是第二个限制条件， 每个的费用为t[i]
      #include<iostream>
      #include<cstring>
      #include<algorithm>
      using namespace std;
      const int INF=0x7fffffff;
      const int maxn=105,maxm=105,maxl=1005;
      int N,M,L;
      int t[maxn],w[maxn];
      int ans=0;
      int f[maxl][maxn];

      int main()
      {
          cin>>N>>M>>L;
          for(int i=1;i<=N;i++)
              cin>>t[i]>>w[i];
          for(int i=0;i<=L;i++)
          for(int j=0;j<=M;j++)
              f[i][j]=-INF;
          for(int i=0;i<=L;i++)
              f[i][0]=0;
          //01背包逆向，完全背包正向
          for(int i=1;i<=N;i++)
          for(int j=L;j>=t[i];j--)
          for(int k=M;k>=1;k--)
              f[j][k]=max(f[j][k],f[j-t[i]][k-1]+w[i]);
          ans=f[L][M];
          if(ans<0)  ans=0;
          cout<<ans<<endl;
          return 0;
      }

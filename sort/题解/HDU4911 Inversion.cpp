# 归并排序逆序数
        #include<bits/stdc++.h>
        using namespace std;
        typedef long long ll;
        const int maxn=1e5+10;
        ll a[maxn],b[maxn];
        int cnt,sum;
        void Merge(ll l,ll mid,ll r){
              ll i=l,j=mid+1,t=0;
              while(i<=mid&&j<=r)
              {
            if(a[i]>a[j])
            {
                b[t++]=a[j++];
                cnt+=mid-i+1;
            }
            else
            {
                b[t++]=a[i++];
            }
              }
              while(i<=mid) 
            b[t++]=a[i++];
              while(j<=r) 
            b[t++]=a[j++];
              for(i=0;i<t;i++) 
              a[l+i]=b[i];
          }

        void Mergesort(ll l,ll r)
          {
              if(l<r)
              {
            ll mid=(l+r)/2;
            Mergesort(l,mid);
            Mergesort(mid+1,r);
            Merge(l,mid,r);
              }
          }
        int main(){
           int n;

           while(scanf("%d",&n)!=EOF){
                cnt=0;
              for(int i=0;i<n;i++)
                scanf("%lld",&a[i]);
              Mergesort(0,n-1);
              printf("%d\n",cnt);

           }
           return 0;
        }

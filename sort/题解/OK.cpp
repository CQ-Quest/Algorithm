#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define U 1000002
int a[U];
int main(){
	int i,n,ok;
    while(cin>>n&&n!=0){
        memset(a,0,sizeof(a));
        ok=0;
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(i = 0;i<n;i++){
            if(a[i] == a[i+1] && i+1<=n){
              ok++;
              a[i]=0;
			  a[i+1]=0;
              i+=1;
            }
        }
        sort(a,a+n);
        for( i = 0;i<n;i++){
            if(a[i+2]-a[i+1] == 1 && a[i+1]-a[i] == 1  && i+2<=n){
              ok++;
              i+=2;
            }
      }
        cout<<ok<<endl;
    }
    return 0;
}

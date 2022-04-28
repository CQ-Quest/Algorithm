#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp(int a,int b){
	return abs(a)>abs(b);
} 
int main(){
	int a[101];
	int n;
	while(cin>>n&&n){ 
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n-1;i++)
	cout<<a[i]<<" ";
	cout<<a[n-1]<<endl;
}
    return 0;
}

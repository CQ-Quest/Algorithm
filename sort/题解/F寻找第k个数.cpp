#include<iostream>
using namespace std;
void Quicksort(int a[],int l,int r){
   int i,j;
   i=l;
   j=r;
   a[0]=a[i];
   while(i<j){
   	while(i<j&&a[j]>a[0])  j--;
   	if(i<j)    a[i++]=a[j];
   	while(i<j&&a[i]<a[0])  i++;
   	if(i<j)    a[j--]=a[i];
   } 
   a[i]=a[0];
   if(l<r){
   	Quicksort(a,l,i-1);
   	Quicksort(a,i+1,r);
   }
}
int main(){
   	int k,n;
   	int a[100000];
   	while(cin>>n>>k){
   		for(int j=1;j<=n;j++){
   			cin>>a[j];
		   }
		   Quicksort(a,1,n);
		   cout<<a[k]<<endl; 
	   }
	   return 0;
   }

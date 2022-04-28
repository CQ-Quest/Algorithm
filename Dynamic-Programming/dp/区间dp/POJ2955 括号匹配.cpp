#include<iostream>
#include<cstring>
#include<string>
using namespace std;
const int maxn=200; 
int dp[maxn][maxn];
bool match(char a,char b){
	if((a=='('&&b==')')||(a=='['&&b==']'))
	return 1;
	return 0;
}
int main(){
	string s;
	while(cin>>s&&s[0]!='e'){
	memset(dp,0,sizeof(dp));
	int len=s.size();
	for(int j=1;j<=len;j++){
		for(int i=j-1;i>=0;i--){
			if(match(s[i],s[j]))
			dp[i][j]=max(dp[i][j],dp[i+1][j-1]+1);
		for(int k=i;k<j;k++){
			dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]);
		}
	}
}
    cout<<2*dp[0][len-1]<<endl; 
}
   return 0;
}

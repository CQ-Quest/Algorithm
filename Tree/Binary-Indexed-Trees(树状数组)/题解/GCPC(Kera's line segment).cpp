//区间差值操作(最大值-最小值) 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
const int maxn=3002;
int n, m;
int mina[maxn][maxn], maxa[maxn][maxn];
int lowbit(int x){
	return x&(-x);
}
void add (int l, int r, int x) {
    l = 3001 - l;
    for(int i = l; i <= 3000; i += lowbit(i))
        for(int j = r; j <= 3000; j += lowbit(j)) {
            mina[i][j] = min(mina[i][j], x);
            maxa[i][j] = max(maxa[i][j], x);
    }
}
int getsum (int l, int r) {
    l = 3001 - l;
    int MAX = 0, MIN = INF;
    for(int i = l; i; i -= lowbit(i))
        for(int j = r; j; j -= lowbit(j)) {
            MAX = max(MAX, maxa[i][j]);
            MIN = min(MIN, mina[i][j]);
        }
    return MAX - MIN;
}
int main () {
	ios::sync_with_stdio(0);
    for(int i = 1; i <= 3000; ++ i)
        for(int j = 1; j <= 3000; ++ j) 
            mina[i][j] = INF;
            
    cin>>n>>m; 
    for(int i = 1; i <= n; ++ i) {
    	int x,y,z;
        cin>>x>>y>>z;
        add(x, y, z);
    }
    int ans=0;
    while(m--){
        int op;
		cin>>op;
		int x,y,z;
        if(op == 1) {
            cin>>x>>y>>z;
            x ^= ans;
            y ^= ans;
            add(x, y, z);
        }
        else {
            cin>>x>>y;
            x ^= ans;
            y ^= ans;
            ans=getsum(x,y);
            cout<<(ll)getsum(x, y)<<endl;
        }
    }
    return 0;
}

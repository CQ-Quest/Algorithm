#include<bits/stdc++.h>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int res;
int g[6][6];
bool st[13];

bool check(int x, int y, int t){
    for (int i = 0; i < 4; i ++ ){
        for(int j=0;j<4;j++)
        {
        	int a=x+dx[i];
        	int b=y+dy[j];
        if (abs(g[a][b] - t ) == 1) 
		return false;
    }
}
    return true;
}
void dfs(int u){
    if (u == 11) {
        res ++;
        return;
    }
    
    for (int i = 2; i <= 11; i ++ ){
        if (!st[i]){
            int x=1+u/4;
			int y=u-u/4*4+1;
            if (check(x, y, i)){
                st[i] = true;
                g[x][y] = i;
                dfs(u + 1);
                g[x][y] = 0;
                st[i] = false;
            }
        }
    }
}
int main(){
	std::ios::sync_with_stdio(false);
    dfs(1);
    cout << res << endl;
    return 0;
}

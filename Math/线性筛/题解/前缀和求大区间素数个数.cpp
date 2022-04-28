const int maxn = 1e7 + 5;

int pre[maxn];
int vis[maxn];//非素数记为1；  

void init() {
    vis[1] = 1;
    for (int i = 2; i <= maxn; i++) {
	if (!vis[i]) {
	    pre[i] = pre[i - 1] + 1;      //前缀数组 
	    for (int j = i << 1; j <= maxn; j += i)
		vis[j] = 1;//所有素数的倍数都不是素数
	}
	else
	    pre[i] = pre[i - 1];
    }
}

int main() {
    init();
    int T;  
	scanf("%d",&T); 
    while (T--) {
	int a, b;   
	scanf("%d %d",&a,&b);
	printf("%d\n", pre[b] - pre[a - 1]);
    }
}

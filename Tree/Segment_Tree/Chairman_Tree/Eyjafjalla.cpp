/*
牛客训练营9 Eyjafjalla
如果根节点符合要求的话，那么子树中所有在范围内的节点，
必然是连续的，即问题转换成了，求x节点子树内，所有符合条件的节点个数
首先需要向上求出来，最远的符合条件的节点

从某个点出发，找到小于等于r的最远祖先，
然后从该祖先开始向子树搜索满足大于等于l的节点个数
*/
#include<bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N=1e5+10;
int n, m;
vector<int> nums;
struct Node {
	int l, r;
	int cnt;
} tr[N * 60];
int root[N], idx;
int h[N<<1], ne[N<<1], e[N<<1],t;
int in[N], out[N], cnt;
int fa[N][21], mx[N][21];
int w[N];

void add(int x, int y) {
	ne[t] = h[x], e[t] = y, h[x] = t++;
}

int find(int x) {
	return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

int build(int l, int r) {
	int p = ++idx;
    if(l == r) return p;
    int mid = l + r >> 1;
    tr[p].l = build(l,mid),tr[p].r= build(mid + 1,r);
    return p;
}

int insert(int p, int l, int r, int x) {
	int q = ++idx;
	tr[q] = tr[p];
	if (l == r) {
		tr[q].cnt++;
		return q;
	}
	int mid = l + r >> 1;
	if (x <= mid)
        tr[q].l = insert(tr[p].l, l, mid, x);
	else 
        tr[q].r = insert(tr[p].r, mid + 1, r, x);
	tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
	return q;
}

void dfs(int u, int father) {
	in[u] = ++cnt;
	fa[u][0] = father;
	root[cnt] = insert(root[cnt - 1], 0, nums.size() - 1, find(w[u]));
	if (u != 1) mx[u][0] = w[father];
	else mx[u][0] = INF;
	for (int k = 1; k <= 20; k++) {
		fa[u][k] = fa[fa[u][k - 1]][k - 1];
		mx[u][k] = max(mx[u][k - 1], mx[fa[u][k - 1]][k - 1]);
	}
	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if (j == father) continue;
		dfs(j, u);
	}
	out[u] = cnt;
}

int get(int x, int k) { //找出温度小于k的x的祖先节点
	for (int i = 20; i >= 0; i--) {
		if (fa[x][i] && mx[x][i] <= k) x = fa[x][i];
	}
	return x;
}


int query(int u, int l, int r, int L, int R) {
	if (nums[l] >= L && nums[r] <= R) {
		return tr[u].cnt;
	}
	int mid = l + r >> 1;
	int ans = 0;
	if (L <= nums[mid]) ans = query(tr[u].l, l, mid, L, R);
	if (R >= nums[mid + 1]) ans += query(tr[u].r, mid + 1, r, L, R);
	return ans;
}
void init(){
    memset(h, -1, sizeof h);
    idx=0,cnt=0,t=0;
}
int main() {
	scanf("%d",&n);
    init();
	for (int i = 2; i <=n; i++) {
		int u,v;scanf("%d%d",&u,&v);
        add(u,v),add(v,u);
	}
	for (int i = 1; i <= n; i++) scanf("%d",&w[i]), nums.push_back(w[i]);
	nums.push_back(INF);
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	root[0] = build(0, nums.size() - 1);
	dfs(1, 0);
	scanf("%d",&m);
	while (m--) {
		int x, l, r;
		scanf("%d%d%d",&x,&l,&r);
		if (w[x] < l || w[x] > r) {
			puts("0");
			continue;
		}
		x = get(x, r);
        int ans1 = query(root[in[x] - 1], 0, nums.size() - 1, l, r);
		int ans2 = query(root[out[x]], 0, nums.size() - 1, l, r);
		printf("%d\n",ans2 - ans1);
	}
	return 0;
}
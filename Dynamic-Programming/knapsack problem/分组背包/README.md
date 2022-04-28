# 分组背包问题
	题目
	有N件物品，告诉你这N件物品的重量以及价值，将这些物品划分为K组，每组中的物品互相冲突，
	最多选一件，求解将哪些物品装入背包可使这些物品的费用综合不超过背包的容量，且价值总和最大。
	
	输入格式
	第一行有两个整数N，V,用空格隔开，分别表示物品组数和背包容量。接下来有N组数据:
	每组数据第一行有一个整数n，表示第1个物品组的物品数量;
	每组数据接下来有n行，每行有两个整数wi, vi,用空格隔开，分别表示第1个物品组的第j个物品的体积和价值;

	输出格式
	输出一个整数，表示最大价值。

	Code:
	#include <iostream>
	#include <algorithm>
	using namespace std;

	const int N = 110;
	int v[N][N], w[N][N];
	int f[N];
	int s[N];
	int n, m;

	int main() {
	    cin >> n >>m ;
	    for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++) {
		    cin >> w[i][j] >> v[i][j];
		}
	    }
    
    // 01背包+每组选一种
    /* 
       j逆序是因为      f[j] = max(f[j], f[j - w[i][k]] + v[i][k])
       等价变形是    f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i][k]] + v[i][k])
    */
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 0; j--) {
            for (int k = 1; k <= s[i]; k++) {
                if (j >= w[i][k])
                    f[j] = max(f[j], f[j - w[i][k]] + v[i][k]);
            }
        }
    }
    cout << f[m] << endl;
    return 0;
    }

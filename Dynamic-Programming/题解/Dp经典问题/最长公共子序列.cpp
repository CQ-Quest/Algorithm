#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 1010
using namespace std;

int dp[maxn][maxn];
char c[maxn] = { 0 };  //字符数组c存储公共子序列
int main()
{
	int i, j, len1, len2, k;
	char s1[maxn] = "xzyzzyx", s2[maxn] = "zxyyzxz";
	len1 = strlen(s1);
	len2 = strlen(s2);
	memset(dp, 0, sizeof(dp));
	for (i = 1;i <= len1;i++)
	{
		for (j = 1;j <= len2;j++)
		{
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	k = 0;
	for (i = len1, j = len2;i >= 1 && j >= 1;)
	{
		if (s1[i - 1] == s2[j - 1])
		{
			c[k++] = s1[i - 1];
			i--;
			j--;
		}
		else if (dp[i][j - 1] > dp[i - 1][j])
			j--;
		else
			i--;
	}
	printf("最长公共子序列为：");
	for (i = k - 1;i >= 0;--i)
		printf("%c", c[i]);
	printf("\n长度为%d\n", dp[len1][len2]);
	printf("\n");
}

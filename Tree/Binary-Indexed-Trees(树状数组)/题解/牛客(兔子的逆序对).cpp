//��ת����[l,r][l,r]ԭ����x�������֮������Ը�����Ϊans-x+(r-l+1)*(r-l)/2-xans?x+(r?l+1)?(r?l)/2?x��
//������ԭ������ԣ�����˳��Եĸ������Ƿ�ת�������Ը���������ж�����������ż�ԡ�
#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n, m, a[N], b[N];
int lowbit(int x){
	return x& -x;
}
void add(int x,int y){
	for(int i=x;i<=n;i+=lowbit(i))
	b[i]+=y;
}
int getsum(int x){
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
	ans+=b[i];
	return ans;
}
int main()
{
    int ans=0;
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=n; i; --i)
    {
        ans = (ans+getsum(a[i]-1))&1;
        add(a[i],1);
    }
    scanf("%d",&m);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int temp=(r-l+1)*(r-l)/2;
        if(temp&1) ans^=1,printf(ans?"dislike":"like");
        else printf(ans?"dislike":"like");
       printf("\n");
    }
    return 0;
}

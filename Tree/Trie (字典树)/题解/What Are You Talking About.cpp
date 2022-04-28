#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int cur=1;
struct Tree
{
    int dict[28];
    char s[10];///存火星文对应的翻译
    void  Init()
    {
        memset(dict,-1,sizeof(dict));
        s[0]='@';
    }
} T[maxn];
char s[3010],word[20];
void create()
{
    int cnt=0;
    int len=strlen(word);
    for(int i=0; i<len; i++)
    {
 
        int pos=word[i]-'a'; 
        if(T[cnt].dict[pos]==-1)
        {
            T[cur].Init();
            T[cnt].dict[pos]=cur++;
        }
        cnt=T[cnt].dict[pos];
    }
    len=strlen(s);
    for(int i=0; i<len; i++)///单词结尾附上对应的翻译
        T[cnt].s[i]=s[i];
}
void Translate(char *str)
{
    int len=strlen(str);
    int cnt=0,pos;
    for(int i=0; i<len; i++)
    {
        pos=str[i]-'a'; 
        if(T[cnt].dict[pos]!=-1)
            cnt=T[cnt].dict[pos];
        else
        {
            printf("%s",str);
            return ;
        }
    }
    if(T[cnt].s[0]=='@')///没有这个处理和判断遇到同样前缀的单词要wa，比如fnn对应没有翻译,但是fnnvk有对应的翻译
        printf("%s",str);
    else
    printf("%s",T[cnt].s);
    return ;
}
int main(){
    T[0].Init();///第一个节点要初始化
    while(~scanf("%s",s))
    {
        if(s[0]=='E') break;
        else if(s[0]=='S') continue;
        else
        {
            scanf("%s",word);
            create();
        }
    }
    getchar();
    while(gets(s))
    {
        if(s[0]=='E') break;
        else if(s[0]=='S') continue;
        else
        {int cnt=0;
            int len=strlen(s);
            char temp[20]={""}; ///临时字符串存要翻译的字符
            for(int i=0; i<len; i++)
            {
                if(s[i]>='a'&&s[i]<='z')
                {
                    temp[cnt++]=s[i];
 
                }
                else
                {   
                    Translate(temp);
                     cnt=0;
                   memset(temp,0,sizeof(temp));///翻译完了必须清空
                    printf("%c",s[i]);///原样输出标点空格
                }
            }
            puts("");
        }
    }
    return 0;
}

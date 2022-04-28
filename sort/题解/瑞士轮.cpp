#include<bits/stdc++.h>
using namespace std;
 const int maxn=1e5+10;
struct node{
    int num;
    int score;
    int power;
}players[maxn*2],winner[maxn],loser[maxn];
 
int N,R,Q,total;
 
bool cmp(node a,node b){
    if(a.score==b.score){
        return a.num<b.num;
    }
    return a.score>b.score;
}
 
void pk(){
    for(int i=1;i<=N;i++){
        if(players[2*i-1].power>players[2*i].power){
            players[2*i-1].score++;
            winner[i]=players[2*i-1];
            loser[i]=players[2*i];
        }
        else{
            players[2*i].score++;
            winner[i]=players[2*i];
            loser[i]=players[2*i-1];
        }  
    }
}
 
void guibing(){
    int i,j,k;
    for(i=1,j=1,k=1;i<=N && j<=N;){
        if(cmp(winner[i],loser[j])){
            players[k++]=winner[i++];
        }
        else{
            players[k++]=loser[j++];
        }
    }
    while(i<=N){
        players[k++]=winner[i++];
    }
    while(j<=N){
        players[k++]=loser[j++];
    }
}
 
int main(){
    scanf("%d %d %d",&N,&R,&Q);
    total=2*N;
    for(int i=1;i<=total;i++){
        scanf("%d",&players[i].score);
        players[i].num=i;
    }
    for(int i=1;i<=total;i++){
        scanf("%d",&players[i].power);
    }
     
    sort(players+1,players+total+1,cmp);
    for(int i=1;i<=R;i++){
        pk();
        guibing();     
    }
    printf("%d\n",players[Q].num);
    return 0;
}

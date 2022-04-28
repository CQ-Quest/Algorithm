#include<bits/stdc++.h>
using namespace std;
int d[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int main(){
    do{
        int s1, s2, s3;
        if (d[4]){
            s1 = d[0] * 1000 + d[1] * 100 + d[2] * 10 + d[3];
            s2 = d[4] * 1000 + d[5] * 100 + d[6] * 10 + d[1];
            s3 = d[4] * 10000+ d[5] * 1000 + d[2] * 100 + d[1] * 10+ d[7];
        }
        if (s1 + s2 == s3){
            cout << s2 << endl;
            break;
        }
    }  
    while (next_permutation(d, d + 10));
    
    return 0;
} 

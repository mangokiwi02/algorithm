#include <iostream>
#include <algorithm>
using namespace std;
string x,y;
int dp[1004][1004];
int check(int a,int b){
    if(a == x.size()) return y.size() - b;
    if(b == y.size()) return x.size() - a;
    if(dp[a][b] != -1e9) return dp[a][b];
    if(x[a] == y[b]){
        dp[a][b] = check(a+1,b+1);
    }else{
        dp[a][b] = min({check(a+1,b+1),check(a+1,b),check(a,b+1)})+1;
    }
    return dp[a][b];
}
int main() {
    cin >> x >> y;
    for(int i =0; i<x.size(); i++){
        for(int j =0; j<y.size(); j++){
            dp[i][j] = -1e9;
        }
    }
    int ans = check(0,0);
    cout << ans;
    return 0;
}
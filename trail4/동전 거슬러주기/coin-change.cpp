#include <iostream>
using namespace std;

int dp[10004];
int n,m;
int coin[10004];
void init(){
    dp[0] = 0;
    for(int i=1; i<= m;i++){
        dp[i] = -1;
    }
}
int check(int a){
    if(a == 0) return 0;
    if(dp[a] != -1) return dp[a];
    int coins = 1e9;
    for(int j=0;j<n;j++){
        if(a >= coin[j]){
            if(dp[a] - coin[j] == 1e9) continue;
            coins = min(check(a-coin[j])+1,coins);
        }
    }
    dp[a] = coins;
    return dp[a];
}
int main() {
    cin >> n >> m;
    init();
    for(int i =0; i<n;i++){
        cin >> coin[i];
    }
    int ans = check(m);
    if(ans == 1e9) cout << -1;
    else cout << ans;
    return 0;
}
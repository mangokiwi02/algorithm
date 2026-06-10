#include <iostream>
using namespace std;
int dp[10004];
int n,m;
int coin[10004]; 

void init(){
    dp[0] = 0;
    for(int i =1; i<=m;i++){
        dp[i] = -2; 
    }
}

int check(int a){
    if(a == 0) return 0;
    if(dp[a] != -2) return dp[a];
    int mx_coin = -1;
    for(int i = 0; i< n;i++){
        if(a >= coin[i]){
            int past = check(a-coin[i]);
            if(past != -1){
                mx_coin = max(mx_coin,past + 1 );
            }
        }
    }
    dp[a] = mx_coin;
    return dp[a];
}

int main() {
    cin >> n >> m;
    init();
    for(int i =0 ; i< n;i++){
        cin >> coin[i];
    }
    int ans = check(m);
    if(ans == -1) cout << -1;
    else cout << ans;
    return 0;
}
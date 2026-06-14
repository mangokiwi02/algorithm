#include <iostream>

using namespace std;
int dp[1004];
int n;
int coins[3] = {1,2,5};

int check(int a){
    if(a == 0) return 1;
    if(a < 0) return 0;
    if(dp[a] != -1) return dp[a];
    int past = 0;
    for(int i =0 ; i< 3;i++){
        past = (past + check(a - coins[i]))%10007;
    }
    dp[a] = past;
    return dp[a];
}
int main() {
    cin >> n;
    for(int i =1 ; i<=n; i++){
        dp[i] = -1;
    }
    dp[0] = 1;  
    int ans = check(n);
    cout << ans;

    return 0;
}

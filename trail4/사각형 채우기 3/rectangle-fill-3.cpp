#include <iostream>

using namespace std;
const long long MOD = 1000000007;
long long dp[1004] = {0};
int n;
const long long check(long long n){
    if(n == 0) return 1;
    if(n == 1) return 2;
    if(dp[n]!=0) return dp[n];
    for(int i = 1; i<=n ; i++){
        if(i == 1) dp[n] = (dp[n] + (check(n-i) * 2) % MOD) % MOD;
        else if(i == 2) dp[n] = (dp[n] + (check(n-i) * 3) % MOD) % MOD;
        else dp[n] = (dp[n] + (check(n-i) * 2) % MOD) % MOD;
    }
    return dp[n];
}
int main(){
    cin >> n;
    long long ans = 0;
    ans = check(n);
    cout << ans;
}
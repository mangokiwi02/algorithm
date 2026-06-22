#include <iostream>
using namespace std;
int n;
const int MOD = 1000000007;
long long dp[1004][1004];
long long check(int a, int len){
    if(a < 0 || a>9) return 0;
    if(len == n) return 1;
    if(dp[a][len] != -1 ) return dp[a][len];
    long long mx = 0; // 이 설정값의 의미
    mx =(check(a+1,len+1)+mx)%MOD;
    mx = (check(a-1,len+1)+mx)%MOD;
    dp[a][len] = mx;
    return dp[a][len];
}
int main() {
    cin >> n;
    for(int i = 0 ;i<=9;i++){
        for(int j =0 ; j<=n;j++){
            dp[i][j] = -1;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= 9; i++){
        ans = (ans + check(i, 1)) % MOD;
    }
    cout << ans;
    return 0;
}
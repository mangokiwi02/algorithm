#include <iostream>
using namespace std;
int n;
int dp[1004] = {0};
int check(int a){
    if(a == 1) return 1;
    if(a == 2) return 3;
    if(dp[a] != 0) return dp[a];
    dp[a] =(check(a-1) + 2 * check(a-2)) % 10007;
    return dp[a];
}
int main() {
    cin >> n;
    int ans =0;
    ans = check(n);
    cout << ans;
    return 0;
}
#include <iostream>
using namespace std;
int dp[104][10004];
int arr[10004];
int n,m;
int check(int idx, int number){
    if(number == 0) return 0;
    if(idx == n) return 1e9; 
    if(dp[idx][number] != -2) return dp[idx][number];
    int mx = check(idx+1, number); 
    if(number >= arr[idx]){
        int past = check(idx + 1, number - arr[idx]);
        if(past != 1e9){
            mx = min(mx, past+1);
        } 
    }
    dp[idx][number] = mx;
    return dp[idx][number]; 
}
int main() {
    cin >> n >> m; 
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<n;i++){
        for(int j =0; j<=m;j++){
            dp[i][j] = -2;
        }
    }
    int ans = check(0,m);
    if(ans == 1e9) cout << -1;
    else cout << ans;
    return 0;
}
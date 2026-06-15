#include <iostream>
using namespace std;
int n;
int arr[100004];
int dp[100004];

int check(int a){
    if(a == 0) return  arr[0]; 
    if(dp[a] != -1e9) return dp[a];
    dp[a] = max(check(a-1) + arr[a], arr[a]);
    return dp[a];
}
int main() {
    cin >> n;
    for(int i =0 ; i< n;i++){
        cin >> arr[i];
    }
    for(int i = 0;i<n;i++){
        dp[i] = -1e9;
    }
    dp[0] = 2*arr[0];
    int ans = -1e9;
    for(int i =0 ; i<n;i++){
        ans = max(ans,check(i));
    }
    cout << ans;
    return 0;
}
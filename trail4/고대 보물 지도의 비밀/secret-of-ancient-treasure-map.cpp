#include <iostream>
using namespace std;
// t를 음수의 개수로
int dp[100004][14];
int n, k;
int arr[100000];

int check(int a, int t){
    if(a < 0) return -1e9;
    if(t< 0) return -1e9; // 불가능한 경우의 수
    if(dp[a][t] != -1e9) return dp[a][t]; 
    int mx = -1e9;
    if(arr[a] < 0){
        mx = max(check(a-1,t-1)+arr[a],mx);
        if(t == 1){
            mx = max(mx, arr[a]);
        }
    }else{
        mx = max(check(a-1,t)+arr[a],mx);
        if(t == 0){
            mx = max(mx, arr[a]);
        }
    }
    dp[a][t] = mx;
    return dp[a][t];
}
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for(int i =0; i<n;i++){
        for(int j =0; j<=k;j++){
            dp[i][j] = -1e9;
        }
    }
    int ans = -1e9;
    for(int i =0; i<n;i++){
        for(int j=0; j<=k;j++){
             ans = max(ans,check(i,j));
        }
    }
    cout << ans;

    return 0;
}

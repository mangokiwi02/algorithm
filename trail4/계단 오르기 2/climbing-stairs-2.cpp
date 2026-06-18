#include <iostream>
using namespace std;
// 1계단만 오르는 것은 3번만!! 
int dp[1004][4]; 
int arr[1004];
int n;

int check(int a,int t){
    if(a == -1) return 0;
    if(a<-1) return -1e9;
    if(dp[a][t] != -1e9) return dp[a][t];
    int mx = -1e9;
    mx = max(check(a-2,t)+arr[a],mx); 
    if(t>0){
        mx = max(check(a-1,t-1)+arr[a],mx);
    }
    dp[a][t] = mx;
    return dp[a][t];
}
int main() {
    cin >> n;
    for(int i =0; i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<1004;i++){
        for(int j=0; j< 4;j++){
            dp[i][j] = -1e9;
        }
    }
    int ans = check(n-1,3);
    cout << ans;
    return 0;
}
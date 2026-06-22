#include <iostream>
using namespace std;
// 왼쪽 : 0, 가운데 : 1, 오른쪽 : 2
int dp[4][1004];
int arr[1004];
int brr[1004];
int crr[1004];
int n;
int check(int a,int lev){
    if(lev == n) return 0;
    if(dp[a][lev] != -1e9) return dp[a][lev];
    int mx = -1e9;
    for(int i=0;i<3;i++){
        if(a != i){ // 다른 방으로 들어가야함
            int past = check(i,lev+1);
            if(i == 0){
                mx = max(past+arr[lev],mx);
            }else if(i == 1){
                mx = max(past+brr[lev],mx);
            }else{
                mx = max(past+crr[lev],mx);
            }
        }
    }
    dp[a][lev] = mx;
    return dp[a][lev];
    }
int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i] >> brr[i] >> crr[i];
    }
    for(int i =0; i<3;i++){
        for(int j = 0;j<n;j++){
            dp[i][j] = -1e9;
        }
    }
    int ans = -1;
    for(int i =0; i<3;i++){
        ans = max(ans,check(i,0));
    }
    cout << ans;
    return 0;
}
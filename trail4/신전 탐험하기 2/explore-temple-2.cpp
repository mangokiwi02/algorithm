#include <iostream>
using namespace std;
// 왼쪽 : 0, 가운데 : 1, 오른쪽 : 2
int dp[4][1004][4];
int arr[1004];
int brr[1004];
int crr[1004];
int n;
int check(int a,int lev,int st){
    if(lev == n && st == a) return -1e9; 
    if(lev == n) return 0;
    if(dp[a][lev][st] != -1e9) return dp[a][lev][st];
    int mx = -1e9;
    for(int i=0;i<3;i++){
        if(a != i){ // 다른 방으로 들어가야함
            int past = check(i,lev+1,st);
            if(i == 0){
                mx = max(past+arr[lev],mx);
            }else if(i == 1){
                mx = max(past+brr[lev],mx);
            }else{
                mx = max(past+crr[lev],mx);
            }
        }
    }
    dp[a][lev][st] = mx;
    return dp[a][lev][st];
    }
int main() {
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i] >> brr[i] >> crr[i];
    }
    for(int i =0; i<3;i++){
        for(int j = 0;j<n;j++){
            for(int k =0;k<3;k++){
                dp[i][j][k] = -1e9;
            }
        }
    }
    int ans = -1;
    for(int i = 0; i < 3; i++){
        int sta = 0;
        if(i == 0) sta = arr[0];
        else if(i == 1) sta = brr[0];
        else sta = crr[0];
        ans = max(ans, sta + check(i, 1, i));
    }
    cout << ans;
    return 0;
}
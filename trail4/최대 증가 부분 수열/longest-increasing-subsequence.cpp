#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[1004];
int dp[1004] = {0};

int check(int a){ // a는 현재 인덱스 값
    if(dp[a]!=0) return dp[a];
    dp[a] = 1;
    for(int i = 0 ; i< a; i++){
        if(arr[i] < arr[a]){
            dp[a] = max(check(i) + 1,dp[a]);
        }
    }
    return dp[a];
}
int main() {
    cin >> n;
    int ans  =0;
    for(int i =0; i< n;i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        ans = max(ans, check(i));
    }
    cout << ans;
    return 0;
}
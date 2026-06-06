#include <iostream>
using namespace std;

int dp[1004] = {0};
int arr[1004] ;
int n;

int check(int a){
    if(dp[a]!= 0) return dp[a];
    dp[a] = 1;
    for(int i=0;i<a;i++){
        if(arr[i] > arr[a]){
            dp[a] = max(dp[a],check(i)+1);
        }
    }
    return dp[a];
}
int main() {
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans,check(i));
    }
    cout << ans;
    return 0;
}
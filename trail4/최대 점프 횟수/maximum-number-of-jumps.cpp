#include <iostream>
using namespace std;

int n;
int arr[1004];
int dp[1004];

int check(int a){
    if(a == n-1) return 0;
    if(arr[a] == -1) return dp[a];
    if(dp[a]!= -1e9) return dp[a];
    int mx = 0;
    for(int i = a+1; i<=a+arr[a]; i++ ){
        int past = check(i);
        if(past!= -1e9) mx = max(past+1,mx);
    }
    dp[a] = mx;
    return dp[a];
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<n;i++){
        dp[i] = -1e9;
    }
    int ans = check(0);
    cout << ans;
}
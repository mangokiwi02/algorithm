#include <iostream>
using namespace std;

int n; 
int arr[104][104];
int dp[104][104]; 

void initialize(){
    dp[0][0] = arr[0][0];
    for(int i = 1; i < n; i++){
        dp[i][0] = min(dp[i-1][0],arr[i][0]);
    }
    
    for(int j = 1; j < n; j++){
        dp[0][j] = min(dp[0][j-1],arr[0][j]);
    }
}
void check(){
    for(int i=1; i<n;i++){
        for(int j=1; j<n;j++){
            dp[i][j] = min(max(dp[i-1][j] , dp[i][j-1]),arr[i][j]);
        }
    }
    
}
int main() {
    cin >> n; 
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin >> arr[i][j]; 
        }
    }
    initialize();
    check();
    cout << dp[n-1][n-1];
    return 0;
}
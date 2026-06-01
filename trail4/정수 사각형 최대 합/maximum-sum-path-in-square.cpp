#include <iostream>

using namespace std;

int n;
int grid[100][100];
int dp[104][104];

void innitialize(){
    dp[0][0] = grid[0][0];
    for(int i =1; i< n;i++){
        dp[i][0] = grid[i][0] + dp[i-1][0];
    }
    for(int i =1; i< n;i++){
        dp[0][i] = grid[0][i]+dp[0][i-1];
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    innitialize();
    for(int i =1; i< n; i++){
        for(int j =1; j<n; j++){
            dp[i][j] = max(dp[i][j-1]+grid[i][j],dp[i-1][j] + grid[i][j]);
        }
    }
    int ans = -1;
    cout << dp[n-1][n-1];
    return 0;
}

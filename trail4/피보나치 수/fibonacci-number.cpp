#include <iostream>
using namespace std;

int dp[1004] = {0};

int check(int n){
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(dp[n] != 0) return dp[n];
    dp[n] = check(n-1) + check(n-2);
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << check(n);
    return 0;
}
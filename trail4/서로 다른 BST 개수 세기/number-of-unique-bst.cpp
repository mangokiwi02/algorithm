#include <iostream>
using namespace std;

int dp[1004] = {0}; 
int check(int n){
    if(n == 0) return 1;
    if(n == 1) return 1; 
    if(n == 2) return 2;
    if(dp[n]!=0) return dp[n];
    for(int i =0; i<n ;i++){
        dp[n]+= check(n-1-i) * check(i);
    }
    return dp[n];
}
int main() {
    int n;
    cin >> n;
    cout << check(n);
    return 0;
}
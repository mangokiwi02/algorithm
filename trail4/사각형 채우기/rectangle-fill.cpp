#include <iostream>
using namespace std;
int memo[10004] = {0};
int step(int n){
    if(n == 1) return 1;
    if(n == 2) return 2;
    if(memo[n] != 0) return memo[n];
    memo[n] = (step(n-1) + step(n-2))%10007;
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    cout << step(n);
    return 0;
}
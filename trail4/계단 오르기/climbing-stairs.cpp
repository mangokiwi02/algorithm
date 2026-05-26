#include <iostream>
using namespace std;

int memo[100004] = {0};

int step(int n){
    if(n == 3 || n == 2) return 1;
    if(n<=1) return 0;
    if(memo[n]!=0) return memo[n];
    memo[n] = (step(n-2) + step(n-3))%10007;
    return memo[n];
}

int main() {
    int n;
    cin >> n;
    cout << step(n);
    return 0;
}
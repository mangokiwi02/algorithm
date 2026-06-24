#include <iostream>
using namespace std;
char arr[1004];
char brr[1004]; 
int dp[1004][1004];
string x,y;
int HIGH = max(x.size(),y.size());
int check(int a, int b){
    if(a == x.size() || b == y.size() ) return 0;
    if(dp[a][b] != -1e9) return dp[a][b];
    if(arr[a] == brr[b]){
        dp[a][b] = check(a+1,b+1) + 1;
    }else{
        dp[a][b] = max(check(a+1,b),check(a,b+1));
    }
    return dp[a][b];
}
int main() {
    cin >> x >> y;
    for(int i=0; i< x.size();i++){
        arr[i] = x[i];
    } 
    for(int i =0 ;i<y.size(); i++){
        brr[i] = y[i];
    }
    for(int i =0;i< 1004;i++){
        for(int j =0 ; j< 1004; j++){
            dp[i][j] = -1e9;
        }
    }
    int ans = check(0,0);
    cout << ans;
    return 0;
}
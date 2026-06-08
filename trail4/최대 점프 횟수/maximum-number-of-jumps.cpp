#include <iostream>
using namespace std;

int dp[1004]; 
int arr[1004];
int n;
void init(){
    for(int i =0; i<n;i++){
        dp[i] = -2;
    }
}

int check(int a){
    if(a == 0) return 0;
    if(dp[a] != -2) return dp[a];
    int max_jump = -1;
    for(int i= 0 ; i< a;i++){
        if(i + arr[i] >= a ){
            if(check(i) != -1){
                max_jump = max(max_jump,check(i)+1);
            }
        }
    }
    dp[a] = max_jump;
    return dp[a];
}
int main() {
    cin >> n;
    init();
    for(int i =0; i<n;i++){
        cin >> arr[i];
    }
    int ans = 0;
    for(int i=0; i<n;i++){
        ans = max(ans,check(i));
    }
    cout << ans;
    return 0;
}
#include <iostream>
using namespace std;
int n;
int brr[1004];
int arr[1004]; // 남우
int dp[1004][1004];
int check(int a,int b){ // a가 남우 b가 상대방 인덱스 
    if(a == n || b == n) return 0;
    if(dp[a][b] != -1e9 ) return dp[a][b];
    int mx = check(a+1,b+1);
    if(arr[a] < brr[b]){ // 상대가 더 큰 경우
        mx = max(check(a+1,b) + arr[a],mx);
    }else if(arr[a] > brr[b]){
        mx = max(check(a,b+1),mx);
    }
    dp[a][b] = mx;
    return dp[a][b];
}
int main() {
    cin >> n;
    for(int i =0; i< n;i++){
        cin >> brr[i];
    }
    for(int i =0; i< n;i++){
        cin >> arr[i];
    }
    for(int i =0; i< n;i++){
        for(int j =0; j<n;j++){
            dp[i][j] = -1e9;
        }
    }
    int mx = check(0,0);
    cout << mx;
    return 0;
}
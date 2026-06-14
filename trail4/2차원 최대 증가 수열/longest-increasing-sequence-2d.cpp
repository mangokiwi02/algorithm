#include <iostream>
using namespace std;
int n,m;
int arr[54][54];
int dp[54][54];

int check(int a,int b){
    if(a == 0 && b == 0) return 1;
    if(dp[a][b] != -2) return dp[a][b];
    int mx = -1;
    for(int i = 0; i<= a-1;i++){
        for(int j =0; j<= b-1; j++){
            if(arr[i][j] < arr[a][b]){
                int past = check(i,j);
                if(past != -1){
                    mx = max(mx,past+1);
                }
            }
        }
    }
    dp[a][b] = mx;
    return dp[a][b];
}
int main() {
    cin >> n >> m;
    for(int i =0; i<n;i++){
        for(int j=0; j<m;j++){
            cin >> arr[i][j];
            dp[i][j] = -2;
        }
    }
    dp[0][0] = 1;
    int ans = 0;
    for(int i =0; i<n;i++){
        for(int j=0; j<m;j++){
            ans = max(ans,check(i,j));
        }
    }
    cout << ans;
    return 0;
}
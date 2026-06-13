#include <iostream>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int n;
long long grid[500][500];
long long dp[504][504];
int check(int a, int b){
    if(dp[a][b] != 0) return dp[a][b];
    int mx = 1; 
    for(int i=0 ; i<4;i++){
        int na = a - dx[i]; // 이전 배열의 x값
        int nb = b - dy[i];
        if(na < 0 || nb < 0 || na >= n || nb >= n){ // 불가능 한 경우 멈춰야 한다. 
            continue;
        }
        if(grid[na][nb] < grid[a][b]){
            int past = check(na,nb);
            mx = max(past + 1,mx);
        }
    }
    dp[a][b] = mx;
    return dp[a][b];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //long long dp[504][504] = {0};
            ans = max(ans, check(i,j));
        }
    }
    cout << ans;
    return 0;
}

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int arr[1004];
int dp[1004][1004];
int n,m;
vector<pair<int,int>> v(1004);
int check(int day,int cl){
    if(day == m) return 0;
    if(dp[day][cl] != -1e9) return dp[day][cl];
    int mx = -1e9;
    for(int i = 1;i<=n;i++){
        if(v[i].first <= day + 1 && day + 1 <= v[i].second){
            int past = check(day+1,i);
            if(past!=-1e9) mx = max(mx,past + abs(arr[cl] - arr[i]));
        }
    }
    dp[day][cl] = mx;
    return dp[day][cl];
}
int main() {
    cin >> n >> m;
    for(int i=1 ; i<= n; i++){
        cin >> v[i].first >> v[i].second >> arr[i];
    }
    for(int i = 0; i <= m; i++){
        for(int j = 0; j <= n; j++){
            dp[i][j] = -1e9;
        }
    }
    
    int ans = -1e9;
    for(int i = 1;i<=n;i++){
        if(v[i].first <= 1 && 1 <= v[i].second){
            ans = max(check(1,i),ans);
        }
    }
    cout <<  ans;
    return 0;
}
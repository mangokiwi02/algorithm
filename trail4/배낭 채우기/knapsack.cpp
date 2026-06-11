#include <iostream>
#include <vector>
using namespace std;

int dp[104][10004];
vector<pair<int,int>> v;
int n,m;
int check(int idx, int cur_weight){
    if(idx == n) return 0;
    if(dp[idx][cur_weight] != -2) return dp[idx][cur_weight];
    int weight = v[idx].first;
    int value = v[idx].second;
    // 배낭에 보석을 안 넣는 경우
    int max_value = check(idx+1,cur_weight);
    // 배낭에 보석을 넣는 경우 
    if(cur_weight>= weight){   
        int past = check(idx + 1, cur_weight-weight) + value;
        max_value = max(past,max_value); 
    }
    dp[idx][cur_weight] = max_value;
    return dp[idx][cur_weight];
}   
int main() {
    cin >> n >> m;
    for(int i=0; i< n;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    for(int i =0; i< n;i++){
        for(int j =0; j<= m;j++){
            dp[i][j] = -2;
        }
    }
    cout << check(0,m);
    return 0;
}
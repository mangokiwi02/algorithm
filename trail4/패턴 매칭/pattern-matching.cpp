#include <iostream>
using namespace std;
string fi,se;
int dp[1004][1004];

int check(int s,int p){
    if(se.size() == p){
        return fi.size() == s;
    }
    if(dp[s][p]!= -1) return dp[s][p];
    bool matched = (s < fi.size()) && (fi[s] == se[p] || se[p] == '.');
    if(p + 1 < se.size() && se[p + 1] == '*'){
        dp[s][p] = check(s, p + 2) || (matched && check(s + 1, p));
    }
    else {
        dp[s][p] = matched && check(s + 1, p + 1);
    }
    return dp[s][p];
}
int main() {
    cin >> fi >> se; 
    for(int i = 0; i < 1004; i++){
        for(int j = 0; j < 1004; j++){
            dp[i][j] = -1;
        }
    }
    int ans = check(0,0);
    if(ans == 1){
        cout << "true";
    }else{
        cout << "false";
    }
    return 0;
}
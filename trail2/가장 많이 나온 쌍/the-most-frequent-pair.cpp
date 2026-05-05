#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t,n; cin >> t >>n; 
    vector<pair<int,int>> v;
    for(int i =0;i<n;i++){
        int x,y; cin >> x >> y;
        if(x<y){
            v.push_back({y,x});
        }else{
            v.push_back({x,y});
        }
    }
    sort(v.begin(),v.end());
    bool is_first = true;
    int fi =0;
    int en =0;
    int ans = 1;
    int cnt = 1;
    for(auto ret : v){
        if(is_first){
            fi = ret.first;
            en = ret.second;
            is_first = false;
        }else{
            if(fi == ret.first && en == ret.second){
                cnt++; 
            }else{
                ans = max(ans,cnt);
                fi = ret.first;
                en = ret.second;
                cnt = 1;
            }
        }
    }
    ans = max(ans,cnt); 
    cout << ans;
    return 0;
}
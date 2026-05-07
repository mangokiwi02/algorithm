#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int check(int a, int b, int start, int end) {
    int real_start = max(a, start);
    int real_end = min(b, end);
    if (real_start <= real_end){
        return real_end - real_start+1;
    }return 0;
    
}

int main() {
    int t, a, b;
    cin >> t >> a >> b; 
    
    vector<pair<int, char>> v; 
    for(int i = 0; i < t; i++) {
        char c; int d;
        cin >> c >> d;
        v.push_back({d, c}); 
    }
    sort(v.begin(), v.end()); 
    
    int cnt = 0; 
    int INF = 2e9; 
    
    // if (v[0].second == 'S') {
    //     cnt += check(-INF, v[0].first,a,b);
    // }
    
    for(int i = 1; i < t; i++) {
        int prev_pos = v[i-1].first;  
        char prev_ch = v[i-1].second; 
        int cur_pos = v[i].first;     
        char cur_ch = v[i].second;    
        int l = prev_pos+1;
        int r = cur_pos;
        if (prev_ch == 'S' && cur_ch == 'S') {
            cnt += check(l, r, a, b);
            
        } else if (prev_ch == 'S' && cur_ch == 'N') {
            int mid = (prev_pos + cur_pos) / 2;
            cnt += check(l, mid, a, b);
            
        } else if (prev_ch == 'N' && cur_ch == 'S') {
            int mid = (prev_pos + cur_pos + 1) / 2; 
            cnt += check(mid, r, a, b);
        } else continue;
    }
    
    if (v[t-1].second == 'S') {
        cnt += check(v[t-1].first, INF,a,b);
    }
    
    cout << cnt << "\n";
    return 0;
}
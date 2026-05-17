#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    char arr[104] = {0};
    int max_pos = 0;
    for(int i=0; i<n;i++){
        int a; char c;
        cin >> a>> c;
        arr[a] = c;
        max_pos = max(max_pos, a);
    }
    int ans = 0;
    int prev_g = -1;
    int prev_h = -1;
    bool gcheck = false;
    bool hcheck = false;
    // g로만 
    for(int i=0; i<=max_pos;i++){
        if(arr[i] == 'G'){
            if(!gcheck){
                prev_g = i; gcheck = true;
                continue;
            }
            int cnt = i-prev_g;
            ans = max(ans,cnt);
        }
        if(arr[i] == 'H'){
            gcheck = false; prev_g = -1;
        }
    }
    // h로만 
    for(int i=0; i<=max_pos;i++){
        if(arr[i] == 'H'){
            if(!hcheck){
                prev_h = i; hcheck = true;
                continue;
            }
            int cnt = i-prev_h;
            ans = max(ans,cnt);
        }
        if(arr[i] == 'G'){
            hcheck = false; prev_h = -1;
        }
    }
    // 둘의 수가 같을 때
    for(int i=0; i<=max_pos; i++){
        if(arr[i] == 0 ) continue; 
        int g_cnt = 0;
        int h_cnt = 0; 
        if(arr[i] == 'G') g_cnt ++; 
        if(arr[i] == 'H') h_cnt ++;
        for(int j = i+1; j<=max_pos; j++){
            if(arr[j] == 'G') g_cnt ++; 
            if(arr[j] == 'H') h_cnt ++;
            if(arr[j]!=0 && g_cnt == h_cnt){
                ans = max(ans,j-i);
            }
        }
    }
    cout << ans;
    return 0;
}
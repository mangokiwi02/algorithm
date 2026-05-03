#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    // int n;
    // cin >> n;
    // int arr[1004]; 
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    // }
    // int ans = 1e9;
    // for(int i=0;i<n;i++){ // 2배할 경우
    //     for(int j =0; j<n;j++){ // 제거할 인덱스
    //         //if(j == i) continue; // 이 부분은 제거를 해야하나...  
    //         int prev = 0;
    //         bool is_first = true;
    //         int diff = 0;
    //         for(int t =0;t<n;t++){
    //             int cur = arr[t];
    //             if(t == i) cur = cur*2;
    //             if(t == j) continue;
    //             if(is_first){
    //                 prev = cur;
    //                 is_first = false;
    //             }else{
    //                 diff += abs(cur-prev);
    //                 prev = cur;
    //             }
    //         }
    //         ans = min(diff,ans);
    //     }
    // }
    // cout << ans;
    // return 0;
    // 벡터 방식 
    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int ans = 1e9;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            vector<int> temp = v;
            temp[i]*=2;
            temp.erase(temp.begin()+j);
            int diff=0;
            int prev =0;
            bool is_first = true;
            for(int ret : temp){
                if(is_first){
                    prev = ret;
                    is_first = false;
                }
                else{
                    diff+= abs(prev - ret);
                    prev = ret;
                }
            }
            ans = min(diff,ans);
        }
        
    }
    cout << ans;
}
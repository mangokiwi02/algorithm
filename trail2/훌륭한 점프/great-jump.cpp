#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

//int arr[1004];
//int n,k;
// bool can_jump(int mid){
//     int curr = 0;
//     if(arr[curr]>mid) return false; 
//     while(curr < n-1){
//         bool jumped = false;
//         for(int jump = k;jump>=1 ;jump--){
//             int next = curr + jump; // 다음 예측값 
//             if(next <n && arr[next] <= mid){
//                 curr = next;
//                 jumped = true;
//                 break;
//             }
//         }
//         if(!jumped) return false;
//     }
//     return true;
// }
int main() {
    int n, k; 
    cin >> n >> k;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vector<int> dp(n + 1, 1e9); 
    dp[1] = arr[1];
    for(int i = 2; i <= n; i++){
        for(int jump = 1; jump <= k; jump++){
            int prev = i - jump; // 이전 돌의 위치
            
            if(prev >= 1){ 
                int current_route_boss = max(dp[prev], arr[i]);
                dp[i] = min(dp[i], current_route_boss);
            }
        }
    }
    cout << dp[n] << "\n";
    
    return 0;

    // int left = 1;      
    // int right = 104; 
    // int ans = right;  

    // while (left <= right) {
    //     int mid = (left + right) / 2;
    
    
    //     if (can_jump(mid)) {
    //         ans = mid;         
    //         right = mid - 1;   
    //     } else {
    //         left = mid + 1;    
    //     }
    // }

    // cout << ans << "\n";
    return 0;
}
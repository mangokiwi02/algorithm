#include <iostream>
using namespace std;

int arr[1004];
int n,k;
bool can_jump(int mid){
    int curr = 0;
    if(arr[curr]>mid) return false; 
    while(curr < n-1){
        bool jumped = false;
        for(int jump = k;jump>=1 ;jump--){
            int next = curr + jump; // 다음 예측값 
            if(next <n && arr[next] <= mid){
                curr = next;
                jumped = true;
                break;
            }
        }
        if(!jumped) return false;
    }
    return true;
}
int main() {
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int left = 1;      
    int right = 104; 
    int ans = right;  

    while (left <= right) {
        int mid = (left + right) / 2;
    
    
        if (can_jump(mid)) {
            ans = mid;         
            right = mid - 1;   
        } else {
            left = mid + 1;    
        }
    }

    cout << ans << "\n";
    return 0;
}
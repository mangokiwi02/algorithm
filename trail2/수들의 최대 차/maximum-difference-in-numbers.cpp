#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    int arr[10004];
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int ans = 0;
    //방벙1_처음 수를 기준으로 탐색 
    for(int i=0;i<n;i++){
        int cnt =0;
        for(int j=i;j<n;j++){
            if(arr[j] - arr[i] <=k){
                cnt++;
            }else break;
        }
        ans = max(cnt,ans);
    }
    cout << ans;
    return 0;
}
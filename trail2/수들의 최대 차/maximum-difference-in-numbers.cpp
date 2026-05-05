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
    // for(int i=0;i<n;i++){
    //     int cnt =0;
    //     for(int j=i;j<n;j++){
    //         if(arr[j] - arr[i] <=k){
    //             cnt++;
    //         }else break;
    //     }
    //     ans = max(cnt,ans);
    // }
    // 방법2_ 윈도우를 조절 
    // for(int i=2; i<n;i++){ // 윈도우 크기 
    //     for(int j=0;j<n-i;j++){
    //         if(arr[j+i-1] - arr[j] <=k ){
    //             ans = max(ans,i);
    //         }
    //     }
    // }
    //방법3_ 투포인터 방식(ai 참고) 
    int r = 0;
    for(int l=0;l<n;l++){
        while(r<n && arr[r] - arr[l]<=k){ // 이 부분이 중요
            r++;
        }
        ans = max(ans,r-l);
    }
    cout << ans;
    return 0;
}
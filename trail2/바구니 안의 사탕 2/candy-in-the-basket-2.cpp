#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int arr[104] = {0};
    for(int i =0;i<n;i++){
        int a; int b;
        cin >> a >> b; 
        arr[b] += a; // 이 부분 변경 // 같은 위치에 바구니가 등장할 수 있으므로 누적해야 한다. 
    }
    int ans = 0;
    for(int i = 0;i<=100;i++){ 
        int sum = 0;
        for(int j = i-m; j <= i+m; j++){
            if(j >= 0 && j<=100){
            sum += arr[j];
            }
        }
        ans = max(ans,sum);
    }
    cout << ans;
    return 0;
}
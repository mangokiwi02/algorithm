#include <iostream>
using namespace std;
// 처음 수를 정하면 나머지는 자동으로 값이 나오지만
// 기존 수에 포함되는지 for문을 통해서 확인 필요
int main() {
    int n; cin >> n;
    int arr[1004];
    int max_v = -1;
    for(int i =0; i<n-1;i++){
        cin >> arr[i];
    }
    int ans[1004];
    for(int i=1; i<arr[0];i++){ // 처음 수를 정한다
        int tmp = i; // 처음수
        int brr[1004] = {0}; // 만들려는 배열 
        bool is_check = true;
        brr[0] = tmp;
        for(int j=0;j<n-1;j++){
            brr[j+1] = arr[j] - brr[j];
            // 검사하는 로직이 필수 
            for(int k=0; k<j+1;k++){
                if(brr[j+1] ==brr[k] || brr[k]<=0 || brr[k]>n){
                    is_check = false;
                    break;
                }
            }
            if(!is_check) break;
        }
        if(is_check){// 정답이라면
            for(int t =0; t<n;t++){
                ans[t] = brr[t];
            }
        }
    }
    for(int t =0; t<n;t++){
        cout << ans[t] <<" "; 
    }
    return 0;
}
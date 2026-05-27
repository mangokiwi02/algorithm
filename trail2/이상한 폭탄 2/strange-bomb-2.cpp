#include <iostream>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int arr[104]; 
    for(int i =0; i<n;i++){
        cin >> arr[i];
    }
    int ans = -1;
    for(int i =0; i<n;i++){
        int tmp = arr[i]; 
        bool check = false;
        int max_size = i+k;
        if(max_size >= n-1) max_size = n-1;
        for(int j = i+1; j<= max_size; j++){
            if(tmp == arr[j]){
                check = true; // 폭발할 폭탄
                break;
            }
        }
        if(check){ // 폭발할 폭탄이라면 계산해야 한다.!! 
            ans = max(ans,tmp);
        }
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >>n;
    int a[1004]; vector<pair<int,int>> v(n);
    for(int i=0; i<n;i++){
        cin >> a[i];
        cin >> v[i].first;
        cin >> v[i].second;
    }
    int ans =0;
    for(int i=1; i<=9; i++){
        for(int j = 1; j<=9;j++){
            for(int k=1; k<=9;k++){ // i랑 j랑 k는 이미 정해진 수 
                bool check = true;
                if(i==j || j==k || i==k) continue;
                for(int t=0; t<n;t++){
                    int f_cnt=0; int s_cnt=0;
                    int arr[3]; 
                    arr[0] = a[t]/100;
                    arr[1] = (a[t]/10)%10;
                    arr[2] = a[t]%10;
                    // 1번 카운트 
                    if(arr[0] == i) f_cnt++;
                    if(arr[1] == j) f_cnt++;
                    if(arr[2] == k) f_cnt++;
                    // 2번 카운트 
                    if(i == arr[1] || i == arr[2]) s_cnt++;
                    if(j == arr[0] || j == arr[2]) s_cnt++;
                    if(k == arr[0] || k == arr[1]) s_cnt++;
                    if(f_cnt!=v[t].first || s_cnt!=v[t].second){
                        check = false;
                        break;
                    }
                }
                if(check){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;
// 일단 3개 수를 더했을 때 각 자리수의 합을 구하고 10이 넘어가지 않아야 캐리이다.
int main() {
    int n;
    cin >> n;
    int arr[104];
    for(int i =0; i<n;i++){
        cin >> arr[i];
    }
    int mx = -1;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            for(int k=0; k<n;k++){
                bool check = true;
                int cnt = 0;
                if(i == j || j == k || i == k) continue;
                int a = arr[i]; int b = arr[j]; int c = arr[k];
                while(true){
                    if(a<= 0 && b<=0 && c<=0 ) break;
                    int fi = a%10;
                    int se = b%10;
                    int th = c%10;
                    if(fi+se+th >=10){ // carry 조건
                        check = false;
                    }
                    a/=10;
                    b/=10;
                    c/=10;
                }
                if(check){
                    cnt = arr[i] + arr[j] + arr[k];
                    mx = max(mx,cnt);
                }
            }
        }
    }
    cout << mx;
    return 0;
}
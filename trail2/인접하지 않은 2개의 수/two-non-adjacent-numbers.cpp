#include <iostream>
#include <algorithm>
using namespace std;

int n;
int numbers[100];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int mx = 0;
    for(int i =0; i< n;i++){
        int tmp = numbers[i];
        for(int j = 0;j<n;j++){
            if(j == i + 1 || j == i - 1 || j == i){
                continue;
            }
            int cnt = tmp + numbers[j];
            mx = max(cnt,mx);
        }
    }
    cout << mx;

    return 0;
}
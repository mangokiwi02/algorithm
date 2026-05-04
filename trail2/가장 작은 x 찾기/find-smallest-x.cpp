#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    int a[1004];
    int b[1004];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    for(int i =1;i<10000;i++){
        bool is_true = true;
        long long tmp = 2*i;
        for(int j=0; j<n;j++){
            if(a[j] <= tmp && tmp<= b[j]){
                tmp =tmp *2;
            }else{
                is_true = false;
                break;
            }

        }
        if(is_true){
            cout << i;
            return 0;
        }
    }
    return 0;
}
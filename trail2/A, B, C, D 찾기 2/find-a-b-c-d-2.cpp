#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // for 4중인데, 생각해보니 a,b가 제일 작겠고 c랑 d는 잘.... 
    int arr[17] = {0};
    int A,B,C,D;
    for(int i = 0;i<15;i++){
        cin >> arr[i];
    }
    sort(arr,arr+15); 
    A = arr[0];
    B = arr[1];
    for(int i=2;i<15;i++){
        C = arr[i]; // 가정
        D = arr[14] -A-B-C;// 마지막 인덱스가 제일 클 수 밖에 없다. 
        if(C > D) continue ;
        bool is_same = true;
        int temp_arr[15] = {
            A, B, C, D,
            A + B, B + C, C + D, D + A, A + C, B + D,
            A + B + C, A + B + D, A + C + D, B + C + D,
            A + B + C + D
        };
        sort(temp_arr,temp_arr + 15);
        for(int j =0;j<15;j++){
            if(temp_arr[j] != arr[j]){
                is_same = false;
                break;
            }
        }
        if(is_same){
            cout<< A<<" "<<B <<" "<<C<<" "<<D; 
            return 0;
        }
    }
    return 0;
}
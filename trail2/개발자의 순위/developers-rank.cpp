#include <iostream>

using namespace std;

int N, B;
int P[1000];

int main() {
    cin >> N >> B;
    int arr[30][30];
    for(int i =0; i<N;i++){
        for(int j =0; j<B;j++){
            cin >> arr[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1;i<= B;i++){
        for(int j=1; j<=B; j++){
            if(i == j) continue;
            bool check = true;
            for(int k =0; k<N;k++){
                int fi = 0;
                int se = 0;
                for(int t =0; t<B;t++){
                    if(arr[k][t] == i) fi = t;
                    if(arr[k][t] == j) se = t; 
                }   
                if(fi <= se) check = false; 
            }
            if(check) cnt++;
        }
    }
    cout << cnt;

    return 0;
}
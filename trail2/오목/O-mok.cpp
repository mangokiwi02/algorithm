#include <iostream>
using namespace std;

int main() {
    int arr[19][19];
    for(int i =0; i<19;i++){
        for(int j=0; j<19;j++){
            cin >> arr[i][j];
        }
    }
    // 흰색돌의 경우 
    bool is_true = false;
    for(int i =0; i<19;i++){
        for(int j=0; j<19;j++){
            if(arr[i][j] == 1){
                int i_cnt=1;int j_cnt =1;int k_cnt = 1;int p_cnt=1;
                for(int k=1;k<=5;k++){
                    if(arr[i+k][j] == 1){
                        i_cnt++;
                        continue;
                    }else{
                        break;
                    }
                }
                for(int k=1;k<=5;k++){
                    if(arr[i][j+k] == 1){
                        j_cnt++;
                        continue;
                    }else{
                        break;
                    }
                }
                for(int k=1;k<=5;k++){
                    if(arr[i+k][j+k] == 1){
                        k_cnt++;
                        continue;
                    }else{
                        break;
                    }
                }
                for(int k=1;k<=4;k++){
                    if(arr[i-k][j+k] == 2){
                        p_cnt++;
                        continue;
                    }else{
                        break;
                    }
                }
                if(i_cnt == 5){
                    cout << 1 <<"\n";
                    cout << i+3<< " " << j+1;
                    is_true = true;
                }
                if(j_cnt == 5){
                    cout << 1 <<"\n";
                    cout << i+1 << " " << j+3;
                    is_true = true;
                }
                if(k_cnt == 5){
                    cout << 1 <<"\n";
                    cout << i+3 << " " << j+3;
                    is_true = true;
                }
                if(p_cnt == 5){
                    cout << 1<<"\n";
                    cout << i-1 << " " << j+3;
                    is_true = true;
                }
            }
        }
    }
    // 검은돌의 경우
    for(int i =0; i<19;i++){
        for(int j=0; j<19;j++){
            if(arr[i][j] == 2){
                int i_cnt=1;int j_cnt =1;int k_cnt = 1;int p_cnt=1;
                for(int k=1;k<=5;k++){
                    if(arr[i+k][j] == 2){
                        i_cnt++;
                        continue;
                    }else{
                        break;
                    }
                }
                for(int k=1;k<=5;k++){
                    if(arr[i][j+k] == 2){
                        j_cnt++;
                        continue;
                    }else{
                        break;
                    }
                }
                for(int k=1;k<=4;k++){
                    if(arr[i+k][j+k] == 2){
                        k_cnt++;
                        continue;
                    }else{
                        break;
                    }
                }
                for(int k=1;k<=4;k++){
                    if(arr[i-k][j+k] == 2){
                        p_cnt++;
                        continue;
                    }else{
                        break;
                    }
                }
                if(i_cnt == 5){
                    cout << 2 <<"\n";
                    cout << i+3 << " " << j+1;
                    is_true = true;
                }
                if(j_cnt == 5){
                    cout << 2 <<"\n";
                    cout << i+1 << " " << j+3;
                    is_true = true;
                }
                if(k_cnt == 5){
                    cout << 2 <<"\n";
                    cout << i+3 << " " << j+3;
                    is_true = true;
                }
                if(p_cnt == 5){
                    cout << 2 <<"\n";
                    cout << i-1 << " " << j+3;
                    is_true = true;
                }
            }
        }
    }
    if(!is_true){
        cout << 0;
    }
    return 0;
}
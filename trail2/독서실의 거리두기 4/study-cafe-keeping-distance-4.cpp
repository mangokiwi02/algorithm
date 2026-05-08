#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string seat;
int arr[104];
int main() {
    cin >> N;
    cin >> seat;
    for(int i=0; i<N;i++){
        arr[i] = seat[i] - '0';
    }
    int final_ans = 0; 
    for(int i = 0; i < N; i++) {
        if(arr[i] == 1) continue; 
        for(int j = i + 1; j < N; j++) {
            if(arr[j] == 1) continue; 
            arr[i] = 1;
            arr[j] = 1;
            int min_dist = 10000; 
            int prev = -1;
            for(int k = 0; k < N; k++) {
                if(arr[k] == 1) {
                    if(prev != -1) {
                        int dist = k - prev;
                        min_dist = min(min_dist, dist); 
                    }
                    prev = k;
                }
            }
            final_ans = max(final_ans, min_dist);
            arr[i] = 0;
            arr[j] = 0;
        }
    }
    
    cout << final_ans << "\n";

    return 0;
}
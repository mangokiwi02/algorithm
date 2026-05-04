#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s; 
    int arr[24];
    for(int i =0; i<s.length();i++){
        arr[i] = s[i] - '0';
    }
    int final_ans = 0; 
    for(int i =0; i<s.length();i++){
        if(arr[i] == 0){
            int min_diff = 1e9;
            arr[i] = 1; // 1로 변경 
            int prev = 0;
            bool is_first = true;
            for(int j=0;j<s.length();j++){
                if(arr[j] == 1){
                    if(is_first){
                        prev = j;
                        is_first = false;
                    }else{
                        int diff = j -prev;
                        min_diff = min(diff,min_diff);
                        prev = j;
                    }
                } 
            }
            final_ans = max(final_ans,min_diff);
            arr[i] = 0; // 백트랙킹 같은 느낌으로 해줘야 한다. 
        }
    }
    cout << final_ans;
    return 0;
}
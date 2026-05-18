#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n; 
    cin >> n;
    string s; 
    cin >> s;
    int arr[104];
    for(int i =0; i<s.size();i++){
        arr[i] = s[i]-'0';
    }
    int ans = 0;
    for(int i=0; i<s.size();i++){
        for(int k =0;k<s.size();k++){
            if(arr[i] == 0 && arr[k] == 0){
                if(i == k) continue;
                arr[i] = 1; 
                arr[k] = 1;
                bool is_first = true;
                int prev = 0;
                int cnt = 1e9;
                for(int j=0;j<s.size();j++){
                    if(arr[j] == 1){
                        if(is_first){
                            is_first = false;
                            prev = j;
                        }else{
                            cnt = min(cnt,j-prev);
                            prev = j;
                        }
                    }
                }
                arr[i] = 0;
                arr[k] = 0;
                ans = max(ans,cnt);
            }
        }
    }
    cout << ans;
}
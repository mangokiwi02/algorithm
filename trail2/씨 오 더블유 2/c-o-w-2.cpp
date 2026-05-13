#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main() {
    cin >> n;
    cin >> str;
    int c_cnt = 0;
    int o_cnt = 0;
    int w_cnt = 0;
    for(int i=0;i<str.size();i++){
        if(str[i] == 'C'){
            c_cnt++;
        }else if(str[i] == 'O'){
            o_cnt+=c_cnt;
        }else{
            w_cnt+=o_cnt; 
        }
    }
    
    cout << w_cnt; 

    return 0;
}
#include <iostream>
#include <stack>
using namespace std;

int main() {
    string v;
    cin >> v;
    stack<int> s;
    bool check = true;
    for(int i =0; i<v.size(); i++){
        if(v[i] == '('){
            s.push(0);
        }else{
            if(s.empty()){
                check = false;
                break;
            }
            s.pop();
        }
    }
    if(!s.empty()) check = false;
    if(!check) cout << "No";
    else cout << "Yes";
    return 0;
}
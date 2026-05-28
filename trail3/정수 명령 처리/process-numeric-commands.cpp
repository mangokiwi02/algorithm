#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    for(int i=0; i<n;i++){
        string s;
        cin >> s;
        if(s == "push"){
            int x; 
            cin >> x;
            v.push_back(x);
        }else if(s == "size"){
            cout << v.size() << "\n";
        }else if(s == "empty"){
            if(v.empty()){
                cout << 1 << "\n";
            }else cout << 0 << "\n";
        }else if(s == "pop"){
            cout << v[v.size()-1] << "\n";
            v.pop_back();
        }else{
            cout << v[v.size()-1] << "\n";
        }
    }
    
    return 0;
}
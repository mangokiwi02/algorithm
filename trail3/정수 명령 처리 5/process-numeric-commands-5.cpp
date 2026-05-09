#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v; 
    for(int i =0; i<n;i++){
        string s; cin >> s;
        if(s== "push_back"){
            int a; cin>>a;
            v.push_back(a);
        }else if(s == "get"){
            int a; cin >>a;
            cout << v[a-1] << "\n";
        }else if(s == "size"){
            cout << v.size() << "\n";
        }else{
            v.pop_back();
        }
    }
    return 0;
}
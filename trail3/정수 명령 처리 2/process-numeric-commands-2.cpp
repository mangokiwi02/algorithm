#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n; cin >> n; 
    queue<int> q;
    for(int i =0; i<n;i++){
        string s; cin >> s; 
        if(s == "push"){
            int n; cin >> n; 
            q.push(n); 
        }
        if(s == "front"){
            cout << q.front() <<"\n";
        }
        if(s == "pop"){
            cout << q.front() << "\n";
            q.pop();
        }
        if(s == "size"){
            cout << q.size() << "\n";
        }
        if(s == "empty"){
            if(q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
    return 0;
}
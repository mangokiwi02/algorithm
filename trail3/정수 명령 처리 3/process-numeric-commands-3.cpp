#include <iostream>
#include <string>
#include <deque>
using namespace std;

int N;

int main() {
    cin >> N;
    deque<int> d;
    for (int i = 0; i < N; i++) {
        string s; cin >> s; 
        if(s == "push_back"){
            int a; cin >> a;
            d.push_back(a);
        }else if(s == "push_front"){
            int a; cin >> a;
            d.push_front(a);
        }else if(s == "pop_front"){
            int front = d.front();
            d.pop_front();
            cout << front << "\n";
        }else if(s == "pop_back"){
            int back = d.back();
            d.pop_back();
            cout << back << "\n";
        }else if(s == "size"){
            cout << d.size() << "\n";
        }else if(s == "empty"){
            if(d.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }else if(s == "front"){
            int front = d.front();
            cout << front << "\n";
        }else{
            int back = d.back();
            cout << back << "\n";
        }
    }   

    

    return 0;
}

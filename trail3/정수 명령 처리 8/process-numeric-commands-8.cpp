#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >>n;
    deque<int> dec;
    for(int i=0; i<n;i++){
        string s; cin >> s;
        if(s == "push_front"){
            int a; cin >> a;
            dec.push_front(a);
        }else if(s == "push_back"){
            int a; cin >> a;
            dec.push_back(a);
        }else if(s == "pop_front"){
            cout<< dec[0] <<"\n";
            dec.pop_front();
        }else if(s == "pop_back"){
            cout<< dec[dec.size()-1] <<"\n";
            dec.pop_back();
        }else if(s == "size"){
            cout << dec.size()<<"\n";
        }else if(s == "empty"){
            if(dec.empty()){
                cout<<"1" <<"\n";
            }else cout<<"0" <<"\n";
        }else if(s == "front"){
            cout<< dec[0] <<"\n";
        }else{
            cout<< dec[dec.size()-1] <<"\n";
        }
    }
    return 0;
}
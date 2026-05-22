#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> v(6);
    for(int i =0; i<6;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int temp1 = v[0] + v[5];
    int temp2 = v[1] + v[4];
    int temp3 = v[2] + v[3];
    int mx = max({temp1,temp2,temp3});
    int mn = min({temp1,temp2,temp3});
    cout << mx - mn;
    return 0;
}
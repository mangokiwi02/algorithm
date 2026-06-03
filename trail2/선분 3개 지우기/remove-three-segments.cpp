#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<pair<int,int>> v;
    int n; cin >> n; 
    for(int i =0; i<n;i++){
        int a;int b;
        cin >> a >> b; 
        v.push_back({a,b});
    }
    int ans =0;
    for(int i=0; i<n;i++){
        for(int j =i+1; j<n;j++){
            for(int k =j+1; k<n;k++){
                if( i==j || i == k || j == k) continue;
                int visit[104] = {0};
                bool check = true;
                for(int t = 0; t<n;t++){
                    if(t == i || t == j || t== k) continue;
                    int st = v[t].first;
                    int en = v[t].second;
                    for(int g = st; g<=en;g++){
                        if(visit[g] == 1){
                            check = false;
                            break;
                        }
                        visit[g] = 1;
                    }
                }
            if(check) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}
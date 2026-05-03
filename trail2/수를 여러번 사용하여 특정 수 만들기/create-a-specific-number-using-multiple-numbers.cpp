#include <iostream>
using namespace std;

int main() {
    int a,b,c;
    cin >>a>>b>>c;
    int ans=-1;
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            int tmp = a*i+b*j;
            if(tmp <= c){
                ans = max(tmp,ans);
            }
        }
    }
    cout << ans;
    return 0;
}
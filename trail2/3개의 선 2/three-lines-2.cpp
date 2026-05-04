#include <iostream>
using namespace std;
// 선을 긋는 방식으로 
struct Point {
    int x;
    int y;
};
int main() {
    int n; cin >>n;
    Point arr[24];
    for(int i =0;i<n;i++){
        cin >> arr[i].x;
        cin >> arr[i].y;
    }

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){

                for(int d1=0;d1<=1;d1++){
                    for(int d2=0;d2<=1;d2++){
                        for(int d3=0;d3<=1;d3++){
                            bool all_cover = true;
                            for(int p=0;p<n;p++){
                                bool cover= false;
                                // 첫번째 선이 잘 덮고 있는지
                                if(d1==0 && arr[p].y == arr[i].y) cover = true;
                                if(d1==1 && arr[p].x == arr[i].x) cover = true;

                                if(d2==0 && arr[p].y == arr[j].y) cover = true;
                                if(d2==1 && arr[p].x == arr[j].x) cover = true;

                                if(d3==0 && arr[p].y == arr[k].y) cover = true;
                                if(d3==1 && arr[p].x == arr[k].x) cover = true;

                                if(!cover){
                                    all_cover = false;
                                    break;
                                }
                            }
                            if(all_cover) {
                                cout << 1 ; 
                                return 0;          
                            }
                        }
                    }
                }
            }
        }
    }
    cout << 0;
    return 0;
}
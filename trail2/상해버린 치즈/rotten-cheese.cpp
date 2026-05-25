#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 음.. 치즈가 상한거를 가정해야 하나? 
int main() {
    int n, m, d, s_cnt; 
    cin >> n >> m >> d >> s_cnt; 
    
    int eat_p[1004], eat_c[1004], eat_t[1004];
    for(int i = 0; i < d; i++){
        cin >> eat_p[i] >> eat_c[i] >> eat_t[i]; 
    }

    int sick_p[1004], sick_t[1004];
    for(int j = 0; j < s_cnt; j++){
        cin >> sick_p[j] >> sick_t[j];
    }
    
    int max_medicine = 0; 
    
    for(int cheese = 1; cheese <= m; cheese++){
        bool is_possible = true; 
        
        for(int j = 0; j < s_cnt; j++){
            int target_person = sick_p[j];
            int sick_time = sick_t[j];
            bool ate_in_time = false; 
            for(int i = 0; i < d; i++){
                if(eat_p[i] == target_person && eat_c[i] == cheese && eat_t[i] < sick_time){
                    ate_in_time = true; 
                    break; 
                }
            }
            if(ate_in_time == false){
                is_possible = false; 
                break; 
            }
        }
        
        if(is_possible == true){
            int medicine_cnt = 0;
            for(int person = 1; person <= n; person++){
                for(int i = 0; i < d; i++){
                    if(eat_p[i] == person && eat_c[i] == cheese){
                        medicine_cnt++; 
                        break; 
                    }
                }
            }
            max_medicine = max(max_medicine, medicine_cnt);
        }
    }
    cout << max_medicine << "\n";
    
    return 0;
}
#include <iostream>

using namespace std;

int n, m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int main() {
    cin >> n >> m;
    int dir =0; // 방향에 대한 변수, 처음에는 무조건 시작
    int arr[104][104];
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = 0; // 0으로 초기화
        }
    }
    int tmp = 1;
    // for문 내부에서는 i,j라는 변수 자체를 쓰면 안된다. 
    int st_x = 0;
    int st_y = 0;
    arr[st_x][st_y] = tmp;
    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 && j == 0) continue;
            tmp++;
            int nx = st_x + dx[dir];
            int ny = st_y + dy[dir];
            if(nx < 0 || nx >= n || ny <0 || ny >= m || arr[nx][ny]!=0){
               dir = (dir+1)%4; 
               nx = st_x + dx[dir]; 
               ny = st_y + dy[dir];
            } 
            arr[nx][ny] = tmp;
            st_x = nx;
            st_y = ny;
        }
    }
    for(int i =0; i<n;i++){
        for(int j =0; j< m;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}


// 초기화 부분도 arr[i][j] = {0} 이런식으로 초기화하고, 이중 포문이 아닌 단일 for문으로 
// 2 ~ n*m 까지 도는 로직으로 구현하는 것이 깔끔하다. 
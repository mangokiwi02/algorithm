#include <iostream>

using namespace std;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int n, m;
char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
int main() {
    cin >> n >> m;
    int st_x = 0;
    int st_y = 0;
    char arr[104][104] = {0};
    int dir = 0;
    arr[st_x][st_y] = 'A';
    for(int i =1; i< n*m;i++){
        int nx = st_x + dx[dir];
        int ny = st_y + dy[dir];
        if(nx <0 || nx>=n || ny <0 || ny>=m || !arr[nx][ny]==0){
            dir = (dir+1)%4;
            nx = st_x + dx[dir];
            ny = st_y + dy[dir];
        }
        arr[nx][ny] = alphabet[(i%26)];
        st_x = nx;
        st_y = ny;
    }
    for(int i =0; i<n; i++){
        for(int j = 0; j<m;j++){
            cout << arr[i][j] <<" "; 
        }
        cout << "\n";
    }
    return 0;
}

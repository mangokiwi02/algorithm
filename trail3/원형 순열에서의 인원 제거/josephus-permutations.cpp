#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;
    queue<int> q;
    int arr[5004];
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    for(int i=0; i<n;i++){
        for(int j=1; j<k;j++){
            int front = q.front();
            q.pop();
            q.push(front);
        }
        int t = q.front();
        q.pop();
        arr[i] = t;
    }
    for(int i=0; i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
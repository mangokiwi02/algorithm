#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> arr;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}
	int k;
	cin >> k;
	sort(arr.begin(), arr.end());
	vector<bool> b(k,false);
	for (int i = 0; i < k; i++) {
		int test; cin >> test;
		int left = 0;
		int right = m - 1;
		while (left <= right) {
			int mid = left + (right - left) / 2;
			if (arr[mid] == test) b[i] = true;
			if (arr[mid] < test) left = mid + 1;
			if (arr[mid] > test) right = mid - 1;
		}
		
	}
	for (bool ret : b) {
		if(ret == true) cout << "기억해" << endl;
		else cout << "기억못해" << endl;
	}
}
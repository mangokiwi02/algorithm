#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
// 부족해지면 기준 금액 인출 만약 인출횟수가 너무 적다면  
using namespace std;
int n, m;
vector<int> v;
bool check(int mid) {
	int cnt = 1;
	int money = mid;
	for (int i = 0; i < v.size(); i++) {
		
		if (money < v[i]) {
			cnt++;
			money = mid;
		}
		money -= v[i];
	}
	return cnt <= m;
}
int ans = 1e9;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.push_back(x);
	}
	int left = *max_element(v.begin(), v.end());
	int right = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			right = mid - 1;
			ans = min(ans, mid);
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << endl;
}
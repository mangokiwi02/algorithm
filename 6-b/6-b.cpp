#include <iostream>
#include <vector>

using namespace std;
int n, m;
vector<int> v;
bool check(int size) {
	int cnt = 1, sum = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] > size) return false; 
		if (sum + v[i] > size) {
			cnt++;
			sum = v[i];
		}
		else {
			sum += v[i];
		}
	}
	return cnt <= m;
}
int main() {
	
	cin >> n >> m;
	
	
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		v.push_back(x); 
	}
	int le = 0;
	int ri = 1e9;
	int ans = 1e9;
	while (le <= ri) {
		int mid = (le + ri) / 2;
		if (check(mid)) {
			ans = min(ans, mid);
			ri = mid - 1;
		}
		else {
			le = mid + 1;
		}
	}
	cout << ans;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n, k;
vector<int> v;
bool check(int mid) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += v[i] / mid;
		if (v[i] % mid != 0) cnt++;
	}
	return n >= cnt;
}
int main() {
	cin >> n >> k;
	int left = 1; int mx = 0;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		v.push_back(x);
		mx = max(mx, v[i]);
	}
	int right = mx; 
	int ret = n;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(mid)) {
			ret = min(ret, mid);
			right = mid - 1;
		}
		else left = mid + 1;
	}
	cout << ret << endl; 
}
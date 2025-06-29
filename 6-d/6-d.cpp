#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t>0) {
		int a, b;
		cin >> a >> b;
		vector<int> first;
		vector<int> second;
		int ans=0;
		for (int i = 0; i < a; i++) {
			int x; cin >> x;
			first.push_back(x);
		}
		for (int j = 0; j < b; j++) {
			int x; cin >> x;
			second.push_back(x);
		}
		sort(first.begin(), first.end());
		sort(second.begin(), second.end());
		for (int i = 0; i < a; i++) {
			auto x = lower_bound(second.begin(), second.end(), first[i]);
			ans += x - second.begin();
		}
		cout << ans<<endl;
		t--;
	}
}

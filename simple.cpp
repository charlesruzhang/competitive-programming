#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	// Sum of k mod i = Sum of i - sum of k div i;
	long long ans = 1ll * n * k;
	int B = sqrt(k);
	for (int i = 1; i <= B; i++) {
		if (i > n) break;
		ans -= (k / i) * i;
	}
	int prev = n;
	for (int i = 0; i <= B; i++) {
		int small = max(B + 1, k / (i + 1) + 1);
		int large = prev;
		if (small > large) continue;
		ans -= 1ll * i * (large - small + 1) * (large + small) / 2;
		prev = k / (i + 1);
	}
	cout << ans << endl;
}
int main() {
	solve();
	return 0;
}
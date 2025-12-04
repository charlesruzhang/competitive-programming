#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;

	int B = sqrt(k);

	long long ans = 1ll * n * k;
	for (int i = 1; i <= B; i++) {
		if (i > n) break;
		ans -= k / i * i;
	}
	int prev = n;
	for (int j = 0; j <= B; j++) {
		int l = max(B + 1, k / (j + 1) + 1);
		int r = prev;
		if (l > r) continue;
		ans -= 1ll * j * (r + l) * (r - l + 1) / 2;
		prev = k / (j + 1);
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}
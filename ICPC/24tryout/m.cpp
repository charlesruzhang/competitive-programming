#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using vvi = vector<vi>;

void solve() {
	int n;
	cin >> n;
	vi a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= i;
 	}
 	sort(a.begin(), a.end());
 	int target = a[n / 2];
 	ll ans = 0;
 	for (int i = 0; i < n; i++) {
 		ans += abs(a[i] - target);
 	}
 	cout << ans << endl;
}


int main() {
	solve();
	return 0;
}
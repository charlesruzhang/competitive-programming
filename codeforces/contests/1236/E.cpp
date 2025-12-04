// By Auchenai01
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll MOD = 998244353;
const ll MAXX = 1e16;
const int INF = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(m);
    for (int i = 0; i < m; i++) {
    	cin >> a[i];
    	a[i]--;
    }
    if (n == 1) {
    	cout << 0 << endl;
    	return;
    }
    vi arr(n + m);
	for (int i = m; i < n + m; i++) {
		arr[i] = 1;
	}
	for (int i = m - 1; i >= 0; i--) {
		int obs = a[i] + i;
		int x = arr[obs];
		arr[obs-1] += x;
		arr[obs] = 0;
	}
	ll tot = 0;
	for (int i = 0; i < m + n; i++) {
		//cout << i << " " << arr[i] << endl;
		tot += 1ll * arr[i] * min(n - 1, i + 1);
	}
	vi arr2(n + m);
	for (int i = 0; i < n; i++) {
		arr2[i] = 1;
	}
	for (int i = m - 1; i >= 0; i--) {
		int obs = a[i] + (m - i);
		int x = arr2[obs];
		arr2[obs+1] += x;
		arr2[obs] = 0;
	}
	for (int i = m + n - 1; i >= 0; i--) {
		//cout << i << " " << arr2[i] << endl;
		tot -= 1ll * arr2[i] * max(0, i - m - 1);
	}
	tot += n;
	cout << tot << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

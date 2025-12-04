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
void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    vi v(101);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	v[a[i]]++;
    }
    for (int i = 1; i <= m; i++) {
    	if (!v[i]) {
    		cout << 0 << endl;
    		return;
    	}
    }
    for (int i = n - 1; i >= 0; i--) {
    	v[a[i]]--;
    	if (v[a[i]] == 0) {
    		cout << n - i << endl;
    		return;
    	}
    }
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

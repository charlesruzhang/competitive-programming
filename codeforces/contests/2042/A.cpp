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
void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	tot += a[i];
    	if (tot == k) {
    		cout << 0 << endl;
    		return;
    	}
    	if (tot > k) {
    		tot -= a[i];
    		cout << k - tot << endl;
    		return;
    	}
    }
    cout << k - tot << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

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
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    __int128 cur = 1;
    ll target = 1;
    for (int i = 0; i < k; i++) {
    	target *= 10;
    }
    for (int i = 0; i < n; i++) {
    	cur *= a[i];
    	if (cur >= target) {
    		cur = 1;
    	}
    }
    cout << (ll) cur << endl;
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

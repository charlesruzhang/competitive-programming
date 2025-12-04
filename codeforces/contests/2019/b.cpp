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
    int n, q; 
    cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    map<ll, ll> ma;
    for (int i = 0; i < n ; i++) {
    	ma[i * 1ll * (n - i)] += a[i] - a[i-1] - 1;
    	ma[i * 1ll * (n - i - 1) + (n - 1)] += 1;
    }
    while (q--) {
    	ll k;
    	cin >> k;
    	cout << ma[k] << " ";
    }
    cout << endl;
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

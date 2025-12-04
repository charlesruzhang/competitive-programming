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
    int n, m;
    cin >> n >> m;
    vl a(n);
    vl diff;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if (n == m) {
    	cout << 0 << endl;
    	return;
    }
    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
    	diff.push_back(a[i] - a[i-1]);
    }
    ll tot = a.back() - a[0];
    sort(diff.begin(), diff.end(), greater<>());
    for (int i = 0; i < m - 1; i++) {
    	tot -= diff[i];

    }
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

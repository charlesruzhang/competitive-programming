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
    int n, j ,k;
    cin >> n >> j >> k;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    if (k >= 2) {
    	cout << "YES" << endl;
    	return;
    }
    if (a[j-1] == *max_element(a.begin(), a.end())) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
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

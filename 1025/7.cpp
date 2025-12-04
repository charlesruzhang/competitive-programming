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
    int n, p;
    cin >> n >> p;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l = 0;
    int r = 1e9;
    for (int i = 0; i < n; i++) {
    	int x = (p - 1 + i >= n) ? 2e9 : a[p-1+i];
    	r = min(r, x - 1 - i);
    	l = max(l, a[i] - i);
    }
    //cout << l << " " << r << endl;
    if (l > r) {
    	cout << 0 << endl;
    } else {
    	cout << r - l + 1 << endl;
    	for (int i = l; i <= r; i++) {
    		cout << i << " ";
    	}
    	cout << endl;
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

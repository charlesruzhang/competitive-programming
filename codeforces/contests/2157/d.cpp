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
    int n, l, r;
    cin >> n >> l >> r;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n / 2; i++) {
    	ans += -(a[i] - a[n - i - 1]);
    	if (r < a[i]) {
    		ans += 2ll * (a[i] - r);
    	} else if (l > a[n - i - 1]) {
    		ans += 2ll * (l - a[n - i - 1]);
    	}
    }
    if (n % 2 == 1) {
    	int x = a[n / 2];
    	if (x <= l) {
    		ans += l - x;
    	} else if (x >= r) {
    		ans += x - r;
    	}
    }
    cout << ans << endl;
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

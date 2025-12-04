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
const ll MAXX = 2e12;
void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vl a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll l = 1;
    ll r = MAXX;
    ll rem = 0;
    while (l < r) {
    	ll m = (l + r + 1) / 2;
    	ll summ = 0;
    	for (int i = 0; i < n; i++) {
    		summ += min(a[i], m);
    	}
    	if (n <= (k + summ) / m) {
    		l = m;
    	} else {
    		r = m - 1;
    	}
    }
    ll summ = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] > l) rem++;
    	summ += min(a[i], l);
    }
    rem += (k - n * l + summ);
    cout << (l-1) * n + 1 + rem << endl;
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

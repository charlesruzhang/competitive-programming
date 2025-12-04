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
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vi x(n);
    iota(x.begin(), x.end(), 0);
    sort(x.begin(), x.end(), [&](int l, int r) {
    	return a[l] < a[r];
    });
    ll diff = 0;
    for (int i = 0; i < n; i++) {
    	diff += abs(a[i] - b[i]);
    }
    for (int i = 0; i < n - 1; i++) {
    	if (b[x[i]] >= b[x[i+1]]) {
    		cout << diff << endl;
    		return;
    	}
    }
    ll minn = 1e18;
    for (int i = 1; i < n; i++) {
    	int l = x[i-1];
    	int r = x[i];
    	ll prev = abs(b[l] - a[l]) + abs(b[r] - a[r]);
    	ll now = abs(b[r] - a[l]) + abs(b[l] - a[r]);
    	minn = min(minn, now - prev);
    }
    cout << diff + minn << endl;
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


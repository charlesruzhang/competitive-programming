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
ll query(char c, int k) {
	cout << "? " << c << " " << k << endl;
	ll res;
	cin >> res;
	return res;
}
void solve() {
    int n;
    cin >> n;
    vi x(n), y(n);
    vector<pll> a, b;
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    	a.push_back({0ll + x[i] + y[i], i});
    	b.push_back({0ll + x[i] - y[i], i});
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    int INF = 1e9;
    query('U', INF);
    query('U', INF);
    query('R', INF);
    ll first = query('R', INF);
    query('D', INF); query('D', INF); query('D', INF);
    ll second = query('D', INF);
    ll add = a[0].first + first;
    ll sub = b[0].first + second - 4ll*INF;
    cout << "! " << (add + sub) / 2 - 2ll * INF << " " << (add - sub) / 2 - 2ll * INF << endl; 
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

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
    int n, m;
    cin >> n >> m;
    int mx = 0, my = 0;
    for (int i = 0; i < m; i++) {
    	int x, y;
    	cin >> x >> y;
    	mx = max(mx, x);
    	my = max(my, y);
    }
    if (mx + my > n) {
    	cout << "IMPOSSIBLE" << endl;
    	return;
    }
    for (int i = 0; i < mx; i++) {
    	cout << 'R';
    }
    for (int i = 0; i < my; i++) {
    	cout << 'W';
    }
    for (int i = 0; i < n - my - mx; i++) {
    	cout << 'R';
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

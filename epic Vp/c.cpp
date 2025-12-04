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
    int n;
    cin >> n;
    vi x(n), y(n);
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    }
    int xs,ys,xt,yt;
    cin >> xs >> ys >> xt >> yt;
    ll D = 1ll * (xt - xs) * (xt - xs) + 1ll * (yt - ys) * (yt - ys);
    for (int i = 0; i < n; i++) {
    	ll Y = 1ll * (x[i] - xt) * (x[i] - xt) + 1ll * (y[i] - yt) * (y[i] - yt);
    	if (D >= Y) {
    		cout << "NO" << endl;
    		return;
    	}
    }
    cout << "YES" << endl;
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

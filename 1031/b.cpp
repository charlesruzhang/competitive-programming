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
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int z1 = x2 - x1;
    int z2 = y2 - y1;
    if (z1 == 0 && abs(z2) % b != 0) {
    	cout << "NO" << endl;
    	return;
    }
    if (z2 == 0 && abs(z1) % a != 0) {
    	cout << "NO" << endl;
    	return;
    }
    if (abs(z1) % a != 0 && abs(z2) % b != 0) {
    	cout << "NO" << endl;
    	return;
    } else {
    	cout << "YES" << endl;
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

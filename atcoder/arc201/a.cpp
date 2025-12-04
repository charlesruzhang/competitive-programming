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
    ll L = 0, R = 0, L2 = 0, R2 = 0;
    for (int i = 0; i < n; i++) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	int yy = y - min(y, z);
    	int l = min(x, yy);
    	int r = min(x, y);
    	L += l;
    	R += r;
    	int r2 = min(z, y);
    	int y2 = y - min(y, x);
    	int l2 = min(z, y2);
    	L2 += l2;
    	R2 += r2;
    }
    assert(L + R2 == L2 + R);
    if (R < L2) {
    	cout << R << endl;
    } else if (R2 < L) {
    	cout << R2 << endl;
    } else {
    	cout << (L + R2) / 2 << endl;
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

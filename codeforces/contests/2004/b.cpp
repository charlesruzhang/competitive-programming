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
    int l, r;
    cin >> l >> r;
    int L, R;
    cin >> L >> R;
    if (l > R) {
    	cout << 1 << endl;
    } else if (L > r) {
    	cout << 1 << endl;
    } else {
    	int z = (min(r, R) - max(l, L));
    	if (max(r, R) != min(r, R)) z++;
    	if (max(l, L) != min(l, L)) z++;
    	cout << z << endl;
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

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
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    ll dist = 1ll * (z - x) * (z - x) + 1ll * (w - y) * (w - y);
    ll tot = 0;
    ll tot2 = 0;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	tot += a[i];
    }
    tot2 = 2 * (*max_element(a.begin(), a.end())) - tot;
    tot = tot * tot;

    if (tot >= dist && (tot2 <= 0 || tot2 * tot2 <= dist)) {
    	cout << "Yes" << endl;
    } else {
    	cout << "No" << endl;
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

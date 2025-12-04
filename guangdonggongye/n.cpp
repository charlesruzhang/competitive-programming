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
const ll MOD = 1e9+7;
const ll MAXX = 1e16;
const int INF = 1e9 + 7;
void solve() {
    int n;
    cin >> n;
    vector<pii> V;
    int maxx = 0;
    ll tot = 0;
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	if (x == 0) {
    		maxx = max(maxx, y);
    	} else if (x == 1) {
    		tot += y;
    	} else {
    		V.push_back({x, y});
    	}
    }
    ll now = maxx + tot;
    sort(V.begin(), V.end(), [&] (pii a, pii b) {
    	auto [x1, y1] = a;
    	auto [x2, y2] = b;
    	return 1ll * y1 * (x2 - 1) > 1ll * y2 * (x1 - 1);
    });
    for (int i = 0; i < V.size(); i++) {
    	auto [x, y] = V[i];
    	now = (now * x + y) % MOD;
    }
    cout << now << endl;
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

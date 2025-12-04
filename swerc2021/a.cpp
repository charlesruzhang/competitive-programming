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
    int n;
    cin >> n;
    vi best(11, -1);
    for (int i = 0; i < n; i++) {
    	int x, y;
    	cin >> x >> y;
    	best[y] = max(best[y], x);
    }
    int tot = 0;
    for (int i = 1; i < 11; i++) {
    	if (best[i] == -1) {
    		cout << "MOREPROBLEMS" << endl;
    		return;
    	}
    	tot += best[i];
    }
    cout << tot << endl;
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

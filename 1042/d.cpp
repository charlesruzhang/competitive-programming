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
    vvi e(n);
    for (int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u].push_back(v);
    	e[v].push_back(u);
    }
    vi leaf(n);
    int tot = 0;
    for (int i = 0; i < n; i++) {
    	if (e[i].size() == 1) {
    		leaf[i] = 1;
    		tot++;
    	}
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
 		int cnt = 0;
    	for (int j : e[i]) {
    		if (leaf[j]) {
    			cnt++;
    		}
    	}
    	if (leaf[i]) cnt++;
    	ans = min(ans, tot - cnt);
    }
    cout << ans << endl;
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

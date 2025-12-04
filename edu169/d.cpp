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
    int q;
    cin >> q;
    map<char, int> ma;
    ma['B'] = 1;
    ma['G'] = 2;
    ma['Y'] = 3;
    ma['R'] = 4;
    
    map<pii, set<int>> mb;
    vector<pii> z(n);
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	int z1 = ma[s[0]] - 1;
    	int z2 = ma[s[1]] - 1;
    	if (z1 > z2) swap(z1, z2);
    	mb[{z1, z2}].insert(i);
    	z[i] = {z1, z2};
    }
    while (q--) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	if (u > v) swap(u, v);
    	auto [x1, y1] = z[u];
    	auto [x2, y2] = z[v];
    	if (x1 == x2 || x2 == y1 || y2 == x1 || y2 == y1) {
    		cout << v - u << endl;
    		continue;
    	}
    	int ans = 1e9;
    	for (int i = 0; i <= 3; i++) {
    		for (int j = i + 1; j <= 3; j++) {
    			if ((i == x1 && j == y1) || (i == x2 && j == y2)) continue;
    			auto it = mb[{i, j}].lower_bound(u);
    			if (it != mb[{i, j}].end()) {
    				ans = min(ans, abs(*it - u) + abs(*it - v));
    			}
    			if (it != mb[{i, j}].begin()) {
    				--it;
    				ans = min(ans, abs(*it - u) + abs(*it - v));
    			}
    		}
    	}
    	if (ans != 1e9) cout << ans << endl;
    	else cout << -1 << endl;
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

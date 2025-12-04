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
    int n, k;
    cin >> n >> k;
    string t;
    cin >> t;
    vi l(k), r(k);
    set<pii> s;
    for (int i = 0; i < k; i++) {
    	cin >> l[i];
    	s.insert({l[i], i});
    }

    for (int i = 0; i < k; i++) {
    	cin >> r[i];
    }

    int q;
    cin >> q;
    vector<set<int>> vs(k);
    while (q--) {
    	int x;
    	cin >> x;
    	auto it = s.upper_bound({x, n});
    	--it;
    	auto [z, y] = *it;
    	int xp = l[y] + r[y] - x;
    	x = max(x, xp);
    	if (vs[y].find(x) != vs[y].end()) {
    		vs[y].erase(x);
    	} else {
    		vs[y].insert(x);
    	}
    }
    vector<char> ans(n+1);
    for (int i = 1; i <= n; i++) {
    	ans[i] = t[i-1];
    }
    for (int i = 0; i < k; i++) {
    	int mi = (l[i] + r[i] + 1) / 2;
    	int cur = 1 - vs[i].size() % 2;
    	int prev = mi;
    	auto it = vs[i].begin();
    	while (it != vs[i].end()) {
    		cur ^= 1;
    		int z = *it;
	    	if (cur) {
	    		for (int j = prev; j <= z; j++) {
	    			swap(ans[j], ans[l[i] + r[i] - j]);
	    		}
    		}
    		prev = z + 1;
    		++it;
    	}
    }
    for (int i = 1; i <= n; i++) {
    	cout << ans[i];
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

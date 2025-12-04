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

    	e[v].push_back(u);
    	e[u].push_back(v);
    }
    vi leaf(n);
    for (int i = 1; i < n; i++) {
    	if (e[i].size() == 1) {
    		leaf[i] = 1;
    	}
    }
    string s;
    cin >> s;
    int u = 0;
    int z = 0, o = 0, un = 0;
    for (int i = 0; i < n; i++) {
    	if (leaf[i]) {
    		if (s[i] == '0') {
    			z++;
    		} else if (s[i] == '1') {
    			o++;
    		} else {
    			un++;
    		}
    	} else if (s[i] == '?' && i) {
    		u++;
    	}
    }
    if (s[0] == '?') {
    	if (z == o) {
    		if (u % 2) {
    			cout << o + (un + 1) / 2 << endl;
    		} else {
    			cout << o + un / 2 << endl;
    		}
    		return;
    	}
    	if (z > o) {
    		swap(z, o);
    	}
    	o += un / 2;
    	cout << o << endl;
    	return;
    } else {
    	if (s[0] == '1') {
    		swap(z, o);
    	}
    	o += (un + 1) / 2;
    	cout << o << endl;
    	return;
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

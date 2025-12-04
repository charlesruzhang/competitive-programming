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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vi V, W;
    int cV = 0, cW = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'A') {
    		V.push_back(0);
    	} else if (s[i] == 'C') {
    		V.push_back(1);
    	} else {
    		cV ^= 1;
    	}
    	if (V.size() >= 2) {
    		if (V.back() == V[V.size() - 2]) {
    			V.pop_back();
    			V.pop_back();
    		}
    	}
    }
    for (int i = 0; i < m; i++) {
    	if (t[i] == 'A') {
    		W.push_back(0);
    	} else if (t[i] == 'C') {
    		W.push_back(1);
    	} else {
    		cW ^= 1;
    	}
    	if (W.size() >= 2) {
    		if (W.back() == W[W.size() - 2]) {
    			W.pop_back();
    			W.pop_back();
    		}
    	}
    }
    if (cV != cW || V != W) {
    	cout << "NO" << endl;
    	return;
    }
    cout << "YES" << endl;
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

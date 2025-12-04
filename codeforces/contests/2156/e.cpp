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
    vi a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	s.insert(a[i]);
    }
    map<int, int> ma;
    int timer = 0;
    for (int x : s) {
    	ma[x] = timer++;
    }
    int l = -1e9;
    int r = 1e9;
    auto check = [&] (int m) {
    	int T = -1;
    	set<pii> S;
    	set<int> U;
    	int first = 1;
    	vvi VV(n);
    	for (int i = n - 1; i >= 0; i--) {
    		int z = a[i];
    		vi& V = VV[i];
    		auto it = S.lower_bound({z + m + 1, -1});
    		while (it != S.end()) {
    			if (V.size() >= 3) break;
    			V.push_back((*it).second);
    			++it;
    		}
    		S.insert({z, i});
    	}
    	//cout << m << " " << T << endl;

    	set<pii, greater<>> S2;
    	for (int i = 0; i < n; i++) {
    		int z = a[i];
    		vi& V = VV[i];
    		auto it = S2.lower_bound({z - m - 1, INF});
    		while (it != S2.end()) {
    			if (V.size() >= 3) break;
    			V.push_back((*it).second);
    			++it;
    		}
    		S2.insert({z, i});
    	}
    	for (int i = 0; i < n; i++) {
    		assert(VV[i].size() <= 3);
    		if (VV[i].size() == 3) {
    			if (T != -1) {
    				return false;
    			}
    			T = i;
    		}
    		VV[i].push_back(i);
    	}
    	if (T != -1) {
    		for (int i = 0; i < n; i++) {
    			if (i == T) continue;
    			if (VV[i].size() == 3) {
    				int flag = 0;
    				for (int v : VV[i]) {
    					if (v == T) {
    						flag = 1;
    						break;
    					}
    				}
    				if (!flag) return false;
    			}
    		}
    		return true;
    	}
    	vi I;
    	for (int i = 0; i < n; i++) {
    		if (VV[i].size() == 3) {
    			if (first) {
    				for (int v: VV[i]) {
    					I.push_back(v);
    				}
    				first = 0;
    			} else {
    				vi II;
    				for (int u: I) {
    					int flag = 1;
    					for (int v: VV[i]) {
    						if (u == v) {
    							flag = 0;
    							break;
    						}
    					}
    					if (!flag) II.push_back(u);
    				}
    				if (II.size() == 0) {
    					return false;
    				}
    				swap(II, I);
    			}
    		}
    	}
    	return true;
    };
    while (l < r) {
    	int m = (l + r) >> 1;
    	bool b = check(m);
    	if (b) {
    		r = m;
    	} else {
    		l = m + 1;
    	}
    	//cout << "! " << m << " " << b << " " << l << " " << r << endl;
    }
    cout << l << endl;
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

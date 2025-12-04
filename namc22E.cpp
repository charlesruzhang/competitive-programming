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
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n + 1; i++) {
    	for (int j = 0; j < 3; j++) {
    		int x;
    		cin >> x;
    		if (x) v[i].push_back(x);
    	}
    }
    vector<pii> ans;
    for (int i = 0; i < n; i++) {
    	while (v[i].size() != 3) {
    		int y = v[n].back();
    		v[n].pop_back();
    		v[i].push_back(y);
    		ans.push_back({n, i});
    	}
    }
    int T = n;
    int X = n - 1;
    while (T) {
    	int z = v[X].back();
    	v[X].pop_back();
    	v[T].push_back(z);
    	ans.push_back({X, T});
    	int flag = 0;
    	for (int i = 0; i < X; i++) {
    		for (int j = 0; j < 3; j++) {
    			if (v[i][j] == z) {
    				for (int k = 2; k > j; k--) {
    					int w = v[i].back();
    					v[i].pop_back();
    					v[T].push_back(w);
    					ans.push_back({i, T});
    				}
    				v[i].pop_back();
    				v[X].push_back(z);
    				ans.push_back({i, X});
    				for (int k = 2; k > j; k--) {
    					int w = v[T].back();
    					v[T].pop_back();
    					v[i].push_back(w);
    					ans.push_back({T, i});
    				}
    				v[X].pop_back();
    				v[T].push_back(z);
    				ans.push_back({X, T});
    				int w = v[X].back();
    				v[X].pop_back();
    				v[i].push_back(w);
    				ans.push_back({X, i});
    				flag = 1;
    				break;
    			}
    		}
    		if (flag) break;
    	}
    	if (!flag) {
    		assert(v[X][0] == z || v[X][1] == z);
    		if (v[X][1] == z) {
    			v[X].pop_back();
    			v[T].push_back(z);
    			ans.push_back({X, T});
    		} else {
    			assert(false);
    			// assert(X != 0);
    			// int ww = v[X].back();
    			// v[X].pop_back();
    			// v[T].push_back(ww);
    			// ans.push_back({X, T});
    			// int w = v[X-1].back();
    			// v[X-1].pop_back();
    			// v[T].push_back(w);
    			// ans.push_back({X - 1, T});
    			// v[X].pop_back();
    			// v[X-1].push_back(z);
    			// ans.push_back({X - 1, X});

    			// for (int i = 0; i < 2; i++) {	
	    		// 	int w = v[T].back();
	    		// 	v[T].pop_back();
	    		// 	v[X].push_back(w);
	    		// 	ans.push_back({T, X});
    			// }

    			// v[X-1].pop_back();
    			// v[T].push_back(z);
    			// ans.push_back({X - 1, T});

    			// w = v[X].back();
    			// v[X].pop_back();
    			// v[X - 1].push_back(w);
    			// ans.push_back({X, X - 1});
    		}
    	}
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

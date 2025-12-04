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
    int t;
    cin >> t;
    vvi e(10000);
    for (int i = 0; i < 10000; i++) {
    	int u = i / 1000;
    	int v = (i / 100) % 10;
    	int w = (i / 10) % 10;
    	int x = i % 10;
    	for (int j = 0; j < 4; j++) {
    		for (int k = j; k < 4; k++) {
    			int up = (u + (j <= 0 && 0 <= k ? 1 : 0)) % 10;
    			int vp = (v + (j <= 1 && 1 <= k ? 1 : 0)) % 10;
    			int wp = (w + (j <= 2 && 2 <= k ? 1 : 0)) % 10;
    			int xp = (x + (j <= 3 && 3 <= k ? 1 : 0)) % 10;
    			int z = up * 1000 + vp * 100 + wp * 10 + xp * 1;
    			e[i].push_back(z);
    			e[z].push_back(i);
    		}
    	}
    }
    for (int i = 0; i < t; i++) {

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

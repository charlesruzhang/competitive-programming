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
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i =0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		a[i][j] = s[j] - '0';
    	}
    }
    auto T = [&] (vvi& a) {
    	int n = a.size();
    	int m = a[0].size();
    	vvi b(m, vi(n));
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			b[i][j] = a[j][i];
    		}
    	}
    	swap(a, b);
    };
    if (n > m) T(a), swap(n, m);
    vvi ans(n, vi(m));
    
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

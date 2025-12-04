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
    set<int> ans;
    ans.insert(1);
    ans.insert(2);
    int G = gcd(m, n - 2);
    int H = gcd(m - 2, n);
    int I = gcd(m - 1, n - 1);
    for (int i = 1; 1ll * i * i <= G; i++) {
    	if (G % i == 0) {
    		ans.insert(i);
    		if(1ll * i * i != G) ans.insert(G / i);
    	}
    }
    for (int i = 1; 1ll * i * i <= H; i++) {
    	if (H % i == 0) {
    		ans.insert(i);
    		if(1ll * i * i != H) ans.insert(H / i);
    	}
    }
    for (int i = 1; 1ll * i * i <= I; i++) {
    	if (I % i == 0) {
    		ans.insert(i);
    		if(1ll * i * i != I) ans.insert(I / i);
    	}
    }
    cout << ans.size() << " ";
    for (int x : ans) {
    	cout << x << " ";
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

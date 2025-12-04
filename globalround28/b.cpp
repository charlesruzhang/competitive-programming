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
    int cur = 1;
    vi p(n);
    for (int i = k - 1; i < n; i += k) {
    	p[i] = cur;
    	cur++;
    }
    for (int i = 0; i < n; i++) {
    	if (!p[i]) {
    		p[i] = cur;
    		cur++;
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << p[i] << " ";
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

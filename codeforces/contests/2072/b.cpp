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
    string s;
    cin >> s;
    int p = 0, q = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == '_') {
    		p++;
    	} else {
    		q++;
    	}
    }

    cout << (q / 2) * 1ll * (q - q / 2) * 1ll * p << endl; 
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

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
    string s;
    cin >> n >> s;
    vi valid(1 << n);
    valid[0] = 1;
    for (int i = 0; i < ((1 << n) - 1); i++) {
    	if (s[i] == '1') {
    		continue;
    	}
    	for (int j = 0; j < n; j++) {
    		if ((1 << j) & (i + 1)) {
    			valid[i + 1] |= valid[(i + 1) ^ (1 << j)];
    		}
    	}
    }
    if (valid[(1 << n) - 1]) {
    	cout << "Yes" << endl;
    } else {
    	cout << "No" << endl;
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

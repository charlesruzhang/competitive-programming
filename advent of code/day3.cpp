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
    string s;
    ll ans = 0;
    while (cin >> s) {
    	if (s == "!") {
    		break;
    	}
    	int n = s.size();
    	vl maxx(13);
    	for (int i = 0; i < n; i++) {
    		int x = s[i] - '0';
    		for (int j = 12; j >= 1; j--) {
    			maxx[j] = max(maxx[j], maxx[j - 1] * 10 + x);
    		}
    	}
    	ans += maxx[12];
    }
    cout << ans << endl;
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

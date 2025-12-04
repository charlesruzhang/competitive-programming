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
    string t;
    cin >> t;
    ll o0 = 1, o1 = 0, e0 = 0, e1 = 0;
    ll ans = 0;
    int now = 0;
    for (int i = 0; i < n; i++) {
    	int z = t[i] - '0';
    	now ^= z;
    	if (i % 2) {
    		if (now) {
    			ans += o1 + e0;
    			o1++;
    		} else {
    			ans += o0 + e1;
    			o0++;
    		}
    	} else {
    		if (now) {
    			ans += o0 + e1;
    			e1++;
    		} else {
    			ans += o1 + e0;
    			e0++;
    		}
    	}
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

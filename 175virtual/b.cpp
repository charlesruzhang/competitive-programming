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
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    int cur = x;
    int done = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'L') {
    		cur--;
    	} else {
    		cur++;
    	}
    	if (cur == 0) {
    		k -= i + 1;
    		done = 1;
    		break;
    	}
    }
    if (!done) {
    	cout << 0 << endl;
    	return;
    }
    cur = 0;
    int p = 0;
    done = 0;
    for (int i = 0; i < n; i++) {
    	if (s[i] == 'L') {
    		cur--;
    	} else {
    		cur++;
    	}
    	if (cur == 0) {
    		p = i + 1;
    		done = 1;
    		break;
    	}
    }
    if (!done) {
    	cout << 1 << endl;
    	return;
    }
    ll ans = 1;
    ans += k / p;
    cout << ans << endl;
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

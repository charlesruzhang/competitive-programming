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
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    stack<pair<ll, int>> st;
    vl pref(n+1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + a[i];
    }
    for (int i = 0; i < n; i++) {
    	while (!st.empty()) {
    		auto [z, idx] = st.top();
    		if (z <= a[i]) {
    			if (pref[i] - pref[idx] > 0) {
    				cout << "NO" << endl;
    				return;
    			}
    			st.pop();
    		} else {
    			if (pref[i+1] - pref[idx+1] > 0) {
    				cout << "NO" << endl;
    				return;
    			}
    			break;
    		}
    	}
    	st.push({a[i], i});
    }
    cout << "YES" << endl;
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

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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    set<int> s;
    int ans = 1;
    for (int i = 0; i < n; i++) {
    	if (x % a[i] == 0 && a[i] != 1) {
	    	set<int> t;
    		if (s.find(a[i]) != s.end()) {
	    		ans ++;
    		} else {
    			t = s;
	    		auto it = s.begin();
	    		while (it != s.end()) {
	    			if (*it % a[i] == 0) {
	    				t.insert(*it / a[i]);
	    			}
	    			++it;
	    		}
    		}
    		t.insert(x / a[i]);
    		swap(s,t);
    	}
    }
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

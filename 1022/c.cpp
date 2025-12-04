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
    vector<pii> a(n);
    set<int, greater<>> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i].first;
    	a[i].second = i;
    	s.insert(a[i].first);
    }
    auto it = s.begin();
    vector<int> valid(n);
    sort(a.begin(), a.end(), greater<>());
    it = s.begin();
    int cur = 0;
    int ans = 0;
    while (it != s.end()) {
    	int idx = cur;
    	while (idx < n - 1 && a[idx+1].first == *it) {
    		++idx;
    	}
    	int prev = -1;
    	int iprev = 0;
    	for (int i = cur; i <= idx; i++) {
    		int loc = a[i].second;

    		if (loc != prev - 1) {
    			iprev = 0;
    		}
    		if (loc + 1 == n || !valid[loc+1]) {
    			ans ++;
    			iprev = 1;
    		}
    		if (loc - 1 >= 0 && valid[loc-1]) {
    			ans -= iprev;
    		}
    		valid[loc] = 1;
    		prev = loc;
    	}
    	cur = idx + 1;
    	++it;
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

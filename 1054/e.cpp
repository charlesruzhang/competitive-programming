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
    int n, k, l , r;
    cin >> n >> k >> l >> r;
    map<int, int> s;
    set<int, greater<>> t;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    auto it2 = t.end();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	auto it = s.find(a[i]);
    	if (it != s.end()) {
    		int last = it -> second;
    		t.insert(i);
    		if (it2 != t.end() && (*it2 >= last)) --it2;
    		t.erase(last);
    	} else {
    		t.insert(i);
    		if (it2 != t.end() ) --it2;
    	}
    	s[a[i]] = i;
    	if (t.size() < k) continue;
    	else if (it2 == t.end()) {
    		--it2;
    	}
    	if (t.size() >= k) {
    		auto it3 = it2;
    		++it3;
    		int start = (it3 == t.end() ? 0 : *it3 + 1);
    		int bend = *it2;
    		int left = i - r + 1;
    		int right = i - l + 1;
    		//if (bend < left || start > right) continue;
    		int res = max(0, min(right, bend) - max(start, left) + 1);
    		ans += res;
    		// cout << "!!" << *it2 << endl;
    		// cout << i << " " << res << endl;
    		// cout << left << " " << right << " " << start << " " << bend << endl;
    	}
    	// if (it2 != t.end()) {
    	// 	cout << i << " " << *it2 << endl;
    	// }
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

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
    vector<set<int>> s(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	s[a[i]].insert(i);
    }
    int cur = 0;
    vi b;
    while (cur < n) {
    	int maxx = cur;
    	for (int i = 0; i <= n; i++) {
    		auto it = s[i].lower_bound(cur);
    		if (it == s[i].end()) {
    			b.push_back(i);
    			cur = maxx + 1;
    			break;
    		} else {
    			maxx = max(maxx, *it);
    		}
    	}
    }
    cout << b.size() << endl;
    for (int i = 0; i < b.size(); i++) {
    	cout << b[i] << " ";
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

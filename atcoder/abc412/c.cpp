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
void solve() {
    int n;
    cin >> n;
    vi a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	s.insert(a[i]);
    }
    int cur = a[0];
    int cnt = 0;
    while (2 * cur < a[n-1]) {
    	auto it = s.upper_bound(cur * 2);
    	--it;
    	if (cur == *it) {
    		cout << -1 << endl;
    		return;
    	}
    	cur = *it;
    	cnt++;
    }
    cout << cnt + 2 << endl;
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

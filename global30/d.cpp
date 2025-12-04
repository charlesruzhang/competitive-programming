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
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    if (s[0] != t[0]) {
        cout << -1 << endl;
        return;
    }
    vector<set<int>> v(26);
    for (int i = 0; i < n; i++) {
    	v[s[i] - 'a'].insert(i);
    }
    vi a(n);
    auto check = [&] (int m) {
    	a[0] = 0;
    	int prev = 0;
    	for (int i = 1; i < n; i++) {
    		int z = t[i] - 'a';
    		if (v[z].empty()) return false;
    		int x = max(prev, i - m);
    		auto it = v[z].lower_bound(x);
    		if (it == v[z].end() || (*it) > i) {
    			return false;
    		}
    		int y = *it;
    		a[i] = prev = y;
    	}
    	return true;
    };
    int l = 0;
    int r = k + 1;
    int kans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            kans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    if (kans == -1 || kans > k) {
    	cout << -1 << endl;
    	return;
    }
    check(kans);
    cout << kans << endl;
    for (int i = 1; i <= kans; i++) {
    	vector<char> ans(n);
    	for (int j = 0; j < n; j++) {
            int idx = max(a[j], j - i);
            ans[j] = s[idx];
        	cout << ans[j];
        }
        cout << '\n';
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

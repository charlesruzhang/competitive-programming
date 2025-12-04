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
    int l, p;
    cin >> l >> p;
    vi a(p);
    for (int i = 0; i < p; i++) {
    	cin >> a[i];
    }
    set<int> s;
    for (int i = -1; i < n; i++) {
    	s.insert(l / 2 + i * l);
    }
    vi cnt(n);
    int maxx = 0;
    for (int i = 0; i < p; i++) {
    	auto it = s.upper_bound(a[i] - l / 2);
    	int x, dex;
    	if (it == s.end()) {
    		x = l / 2 + (n - 1) * l;
    		dex = n - 1;
    	} else {
    		x = *it;
    		dex = (x - l / 2) / l;
    	}
    	maxx = max(maxx, abs(a[i] - x));
    	cnt[dex]++;
    }
    cout << maxx << endl;
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	ans = max(ans, cnt[i]);
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

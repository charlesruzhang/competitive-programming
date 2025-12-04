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
    vi a(n);
    vi cnt(n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }
    vi pref(n + 1);
    for (int i = 1; i <= n; i++) {
    	pref[i] = pref[i-1] + cnt[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
    	int tot = 0;
    	if (4 * i - 1 <= n) tot = pref[n] - pref[4 * i - 1];
    	for (int j = 1; j <= 3; j++) {
    		if (j * i <= n) tot += cnt[j * i];
    	}
    	if (tot >= n - k) {
    		ans = max(ans, i);
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

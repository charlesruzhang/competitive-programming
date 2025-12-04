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
    vi a(n);
    vi cnt(n+1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }
    int maxx = 0;
    int idx = -1;
    for (int i = 0; i <= n; i++) {
    	if (maxx < cnt[i]) {
    		maxx = cnt[i];
    		idx = i;
    	}
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++) {
    	if (idx == i) continue;
    	vi diff(2 * n + 1, n);
    	diff[n] = -1;
    	int cur = 0;
    	for (int j = 0; j < n; j++) {
    		if (a[j] == idx) {
    			cur++;
    		} else if (a[j] == i) {
    			cur--;
    		}
    		ans = max(ans, j - diff[cur+n]);
    		diff[cur+n] = min(diff[cur+n], j);
    	}
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

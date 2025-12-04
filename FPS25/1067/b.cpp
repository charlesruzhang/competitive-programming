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
    vi a(2*n);
    vi cnt(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    }
    int ans = 0;
    int tot = 0;
    int x = 0;
    for (int i = 1; i <= 2 * n; i++) {
    	if (cnt[i]) {
    		if (cnt[i] % 2) {
    			ans++;
    			x++;
    		} else {
    			ans+=2;
    		}
    		if (cnt[i] % 4 == 0) {
    			tot++;
    		}
    	}
    }
    if (tot % 2 == 1) {
    	if (x < 2) {
    		ans -= 2;
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

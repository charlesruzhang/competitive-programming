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
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    int cnt = 0;

    int ans = 0;
    for (int i = 0, j; i < n; i = j) {
    	if (a[i] == 0) {
    		cnt++;
    		if (cnt == k) {
    			cnt = 0;
    			ans++;
    			j = i + 2;
    		} else {
    			j = i + 1;
    		}
    	} else {
    		j = i + 1;
    		cnt = 0;
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

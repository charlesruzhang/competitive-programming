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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vi a(n);
    vi b(m);
    for (int i = 0; i < n;i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    sort(a.begin(), a.end(),greater<>());
    sort(b.begin(), b.end(), greater<>());
    vi count(n);
    int z = 0;
    int w = 0;
    for (int i = 0; i < m; i++) {
    	if (z >= n || a[z] < b[i]) {
    		cout << "impossible" << endl;
    		return;
    	}
    	if (w >= n || a[w] < b[i]) {
    		count[z]++;
    		if (count[z] == x) {
    			z++;
    		}
    	} else {
    		count[w]++;
    		if (count[w] == y) {
    			w++;
    		}
    	}
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	if (count[i] <= y) {
    		ans++;
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

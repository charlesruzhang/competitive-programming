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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n * m);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < m; j++) {
    		int l = max(0, i - k + 1);
    		int r = min(n - 1, i + k - 1);
    		int u = max(0, j - k + 1);
    		int d = min(m - 1, j + k - 1);
    		a[i * m + j] = (r - l - k + 2) * (d - u - k + 2);
    	}
    }
    sort(a.begin(), a.end(), greater<>());
    int w;
    cin >> w;
    vi b(w);
    for (int i = 0; i < w; i++) {
    	cin >> b[i];	
    }
    sort(b.begin(), b.end(), greater<>());
    ll tot = 0;
    for (int i = 0; i < w; i++) {
    	tot += 1ll * b[i] * a[i];
    }
    cout << tot << endl;
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

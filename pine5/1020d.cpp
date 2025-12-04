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
    vi b(k);
    for (int i = 0; i < k; i++) {
    	cin >> b[i];
    }
    int j = 0;
    vi L(k, -1);
    for (int i = 0; i < n; i++) {
    	if (j < k && a[i] >= b[j]) {
    		L[j] = i;
    		j++;
    	}
    }
    j = k - 1;
    vi R(k, -1);
    for (int i = n - 1; i >= 0; i--) {
    	if (j >= 0 && a[i] >= b[j]) {
    		R[j] = i;
    		j--;
    	}
    }
    if (L[k - 1] != -1) {
    	cout << 0 << endl;
    	return;
    }
    int ans = INF;
    for (int i = 0; i < k; i++) {
    	int x = i ? L[i - 1] : -INF;
    	int y = i != k - 1 ? R[i + 1] : INF;
    	if (x == -1 || y == -1) continue;
    	if (x < y) {
    		ans = min(b[i], ans);
    	}
    }
    if (ans != INF) cout << ans << endl;
    else cout << -1 << endl;
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

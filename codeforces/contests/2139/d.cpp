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
    vi b(n), a(n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vi cnt(n+1);
    for (int i = 0; i < n; i++) {
    	cnt[b[i]]++;
    }
    for (int i = 1; i <= n; i++) {
    	if (cnt[i] % i) {
    		cout << -1 << endl;
    		return;
    	}
    }
    vi last(n+1);
    vi c(n+1);
    int idx = 1;
    for (int i = 0; i < n; i++) {
    	int x = b[i];
    	if (c[x] == 0) {
    		a[i] = idx;
    		last[x] = idx;
    		idx++;
    		c[x]++;
    	} else {
    		a[i] = last[x];
    		c[x]++;
    	}
    	if (c[x] == x) {
    		c[x] = 0;
    	}
    }
    for (int i = 0; i < n; i++) {
    	cout << a[i] << " ";
    }
    cout << endl;
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

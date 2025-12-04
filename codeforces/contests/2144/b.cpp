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
    int l = n + 1;
    int r = 0;
    for (int i = 1; i <= n; i++) {
    	if (!cnt[i]) {
    		l = min(l, i);
    		r = max(r, i);
    	}
    }
    int L = n + 1;
    int R = -1;
    for (int i = 0; i < n; i++) {
    	if (a[i] == 0 && l == r) {
    		a[i] = l;
    	}
    	if (a[i] != i + 1) {
    		L = min(L, i);
    		R = max(R, i);
    	}
    }
    cout << max(0, R - L + 1) << endl;
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

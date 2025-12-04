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
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vl pref(n);
    for (int i = 1; i < n; i++) {
    	pref[i] = pref[i-1] + (a[i] < a[i-1] ? a[i-1] - a[i] : 0);	
    }
    vl suff(n);
    for (int i = n - 2; i >= 0; i--) {
    	suff[i] = suff[i+1] + (a[i] < a[i+1] ? a[i+1] - a[i] : 0);	
    }
    for (int i = 0; i < m; i++) {
    	int x, y;
    	cin >> x >> y;
    	x--; y--;
    	if (x > y) {
    		cout << suff[y] - suff[x] << endl;
    	} else {
    		cout << pref[y] - pref[x] << endl;
    	}
    }
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

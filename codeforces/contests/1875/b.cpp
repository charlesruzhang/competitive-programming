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
    vi a(n), b(m);
    for (int i = 0; i < n; i ++) {
    	cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    k--;
    int minn = 1e9+7;
    int idx = -1;
    for (int i = 0; i < n; i++) {
    	if (minn > a[i]) {
    		minn = a[i];
    		idx = i;
    	}
    }
    int maxx = -1;
    int idx2 = -1;
    for (int i = 0; i < m; i++) {
    	if (maxx < b[i]) {
    		maxx = b[i];
    		idx2 = i;
    	}
    }
    if (a[idx] < b[idx2]) swap(a[idx], b[idx2]);
    if (k % 2 == 1) {
    	int minn = 1e9+7;
	    int maxx = -1;
	    int idx = -1;
	    for (int i = 0; i < n; i++) {
	    	if (maxx < a[i]) {
	    		maxx = a[i];
	    		idx = i;
	    	}
	    }
	    int idx2 = -1;
	    for (int i = 0; i < m; i++) {
	    	if (minn > b[i]) {
	    		minn = b[i];
	    		idx2 = i;
	    	}
	    }
	    if (a[idx] > b[idx2]) swap(a[idx], b[idx2]);
    }
    ll summ = 0;
    for (int i = 0; i < n; i++) {
    	summ += a[i];
    }
    cout << summ << endl;
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

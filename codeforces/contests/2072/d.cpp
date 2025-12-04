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
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n;i++) {
    	cin >> a[i];
    }
    int ans = 0;
    int maxl = 0;
    int maxr = 0;
    for (int i = 0; i < n; i++) {
    	int t = a[i];
    	int init = 0;
    	int maxx = 0;
    	int r = i;
    	for (int j = i + 1; j < n; j++) {
    		if (t < a[j]) {
    			init--;
    		} else if (t > a[j]) {
    			init++;
    		}
    		if (maxx < init) {
    			r = j;
    			maxx = init;
    		}
    	}
    	if (ans < maxx) {
    		ans = maxx;
    		maxl = i;
    		maxr = r;
    	}
    }
    cout << maxl + 1 << " " << maxr + 1 << endl;
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

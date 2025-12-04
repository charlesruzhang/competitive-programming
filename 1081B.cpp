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
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vvi v(n+1);
    for (int i = 0; i < n; i++) {
    	v[n-a[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
    	if (v[i].size() % i) {
    		cout << "Impossible" << endl;
    		return;
    	}
    }
    cout << "Possible" << endl;
    int idx = 1;
    vi ans(n);
    for (int i = 1; i <= n; i++) {
    	for (int j = 0; j < (v[i].size() / i); j++) {
    		for (int k = j * i; k < (j + 1) * i; k++) {
    			ans[v[i][k]] = idx;
    		}
    		idx++;
		}	
    }
    for (int i = 0; i < n; i++) {
    	cout << ans[i] << " ";
    }
    cout << endl;
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

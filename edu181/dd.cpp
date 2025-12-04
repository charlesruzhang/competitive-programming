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
    vl a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    int i = 0;
    int j = n - 1;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll tot = 0;
    while (i < n && j >= 0) {
    	if (a[i] + b[j] < m) {
    		tot += a[i];
    		i++;
    	} else {
    		tot += (a[i] + b[j]) % m;
    		i++;
    		j--;
    	}
    }
	for (int z = j; z >= 0; z--) {
		tot += b[z];	
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

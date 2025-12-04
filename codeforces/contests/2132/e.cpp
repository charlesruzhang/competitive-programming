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
    int n, m, q;
    cin >> n >> m >> q;
    vi a(n), b(m);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());
    vi ca(n+m+1), cb(n+m+1);
    int i = 0, j = 0;
    for (int k = 0; k < m + n; k++) {
    	if (i == n) {
    		ca[k+1] = ca[k];
    		cb[k+1] = cb[k] + 1;
    	} else if (j == m) {
    		ca[k+1] = ca[k] + 1;
    		cb[k+1] = cb[k];	
    	} else if (a[i] >= b[j]) {
    		ca[k+1] = ca[k] + 1;
    		cb[k+1] = cb[k];	
    		i++;
    	} else {
    		ca[k+1] = ca[k];
    		cb[k+1] = cb[k] + 1;	
    		j++;
    	}
    }
    vl pref(n+1), preg(m+1);
    for (int i = 0; i < n; i++) {
    	pref[i+1] = pref[i] + a[i];
    }
    for (int i = 0; i < m; i++) {
    	preg[i+1] = preg[i] + b[i];
    }
    while (q--) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	int l = ca[z];
    	int r = cb[z];
    	if (l <= x && r <= y) {
    		cout << pref[l] + preg[r] << endl;
    		continue;
    	}
    	if (l > x) {
    		cout << pref[x] + preg[z - x] << endl;
    	} else {
    		cout << pref[z - y] + preg[y] << endl;
    	}
    }
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

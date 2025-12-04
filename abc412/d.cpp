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
    int n, m;
    cin >> n >> m;
    vvi e(n, vi(n));
    for (int i = 0; i < m; i++) {
    	int u, v;
    	cin >> u >> v;
    	u--; v--;
    	e[u][v] = e[v][u] = 1;
    }
    vi a(n);
    for (int i = 0; i < n; i++) {
    	a[i] = i;
    }
    int minn = 1e9;
    do {
    	vi b = a;
    	b.push_back(b[0]);
    	int tot = m;
    	int cnt = 0;
    	for (int i = 0; i < n; i++) {
    		int u = b[i+1];
    		int v = b[i];
    		if (e[u][v]) {
    			tot--;
    		} else {
    			cnt++;
    		}
    	}
    	cnt += tot;
    	minn = min(minn, cnt);

    	if (n >= 6) {
	    	tot = m;
	    	cnt = 0;
    		for (int i = 0; i < 2; i++) {
    			if (e[b[i+1]][b[i]]) {
    				tot--;
    			} else {
    				cnt++;
    			}
    		}
    		if (e[b[0]][b[2]]) {
    			tot--;
    		} else {
    			cnt++;
    		}

    		for (int i = 3; i < n - 1; i++) {
    			if (e[b[i+1]][b[i]]) {
    				tot--;
    			} else {
    				cnt++;
    			}
    		}
    		if (e[b[3]][b[n-1]]) {
    			tot--;
    		} else {
    			cnt++;
    		}
    		cnt += tot;
    		minn = min(minn, cnt);
    	}

    	if (n >= 8) {
	    	tot = m;
	    	cnt = 0;
    		for (int i = 0; i < 3; i++) {
    			if (e[b[i+1]][b[i]]) {
    				tot--;
    			} else {
    				cnt++;
    			}
    		}
    		if (e[b[0]][b[3]]) {
    			tot--;
    		} else {
    			cnt++;
    		}

    		for (int i = 4; i < n - 1; i++) {
    			if (e[b[i+1]][b[i]]) {
    				tot--;
    			} else {
    				cnt++;
    			}
    		}
    		if (e[b[4]][b[n-1]]) {
    			tot--;
    		} else {
    			cnt++;
    		}
    		cnt += tot;
    		minn = min(minn, cnt);
    	}
    } while (next_permutation(a.begin(), a.end()));

    cout << minn << endl;
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

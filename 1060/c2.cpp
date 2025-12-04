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
vi cnt(2e5+1);
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi b(n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    vvi facts(n);
    ll flag = MAXX;
    for (int i = 0; i < n; i++) {
    	int x = a[i];
    	for (int j = 2; j * j <= x; j++) {
    		int cnt = 0;
    		while (x % j == 0) {
    			x /= j;
    			cnt++;
    		}
    		if (cnt) {
    			facts[i].push_back(j);
    		}
    	}
    	if (x > 1) {
    		facts[i].push_back(x);
    	}
    	for (int y : facts[i]) {
    		cnt[y]++;
    		if (y > 1 && cnt[y] >= 2) {
    			flag = 0;
    		}
    	}
    }
    for (int i = 0; i < n; i++) {
    	int x = a[i] + 1;
    	vi V;
    	for (int j = 1; j * j <= x; j++) {
    		if (x % j == 0) {
    			V.push_back(j);
    			if (j * j != x) V.push_back(x / j);
    		}
    	}
    	for (int y : V) {
    		if (y > 1 && cnt[y] >= 1) {
    			flag = min(flag, (ll)b[i]);
    		}
    	}
    }

    vi c(n);
    for (int i = 0; i < n; i++) {
    	c[i] = (a[i] % 2 ? b[i] : 0);
    }
    sort(c.begin(), c.end());
    ll minn = min(flag, (ll)c[0] + c[1]);
    vi p(n);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) {
    	return b[x] < b[y];
    });
    int z = p[0];
    int m2 = INF;
    for (int i = 0; i < n; i++) {
    	if (i == z) continue;
    	for (int x : facts[i]) {
    		int y = x - a[z] % x;
    		m2 = min(m2, y);
    	}
    }
    minn = min(minn, 1ll * m2 * b[p[0]]);
    for (int i = 0; i < n; i++) {
    	for (int y : facts[i]) {
    		cnt[y]--;
    	}
    }
    cout << minn << endl;
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

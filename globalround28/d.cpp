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
    vi a(n-1), b(m);
    int x;
    cin >> x;
    for (int i = 1; i < n; i++) {
    	cin >> a[i-1];
    }
    for (int i = 0; i < m; i++) {
    	cin >> b[i];
    }
    sort(a.begin(), a.end(), greater<>());
    sort(b.begin(), b.end());
    int idx = -1;
    for (int i = 0; i < m; i++) {
    	if (b[i] > x) {
    		idx = i;
    		break;
    	}
    }
    if (idx == -1) {
    	for (int i = 1; i <= m; i++) {
    		cout << (m / i) << " ";
    	}
    	cout << endl;
    	return;
    }
    vi larger(m);
    int id = 0;
    for (int i = m - 1; i >= 0; i--) {
    	while (id < n - 1 && a[id] >= b[i]) {
    		id++;
    	}
    	larger[i] = id;
    }
    for (int i = 1; i <= m; i++) {
    	int z = m % i;
    	int first = 1;
    	ll tot = 0;
    	int cnt = 0;
    	int maxx = m - 1;
    	for (int j = i - 1; j < m; j+=i) {
    		cnt++;
    		if (j >= idx && first)  {
    			//j += z;
    			first = 0;
    			maxx -= j - idx;
    			tot += 1 + larger[maxx];
    			continue;
    		}
    		if (j < idx) {
    			tot ++;
    		} else {
    			maxx -= i;
    			tot += 1 + larger[maxx];
    		}
    	}
    	assert(cnt == m / i);
    	cout << tot << " ";
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

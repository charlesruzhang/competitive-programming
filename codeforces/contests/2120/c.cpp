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
    ll m;
    cin >> n >> m;
    set<pair<ll, int>> tot;
    for (int i = 1; i <= n; i++) {
    	tot.insert({1ll * i * (n - i + 1) + 1ll * i * (i - 1) / 2, i});
    }
    if (m == n) {
    	cout << 1 << endl;
    	for (int i = 1; i < n; i++) {
    		cout << i << " " << i + 1 << endl;
    	}
    	return;
    }
    auto it = tot.lower_bound({m, -1});
    if (it == tot.end() || it == tot.begin()) {
    	cout << -1 << endl;
    	return;
    }
    m = (*it).first - m;
    vi seq(n);
    int z = (*it).second;
    seq[0] = z;
    for (int i = 1; i <= n - z; i++) {
    	seq[i] = z + i;
    }
    for (int i = n - z + 1; i < n; i++) {
    	seq[i] = n - i;
    }
    //cout << "m = " << m << endl;
    int idx = n - z + 1;
    while (m > 0) {
    	ll Z = idx - 1;
    	if (m <= Z) {
    		swap(seq[idx], seq[idx - m]);
    		break;
    	}
    	m -= Z;
    	swap(seq[idx], seq[1]);
    	idx++;
    }
    cout << z << endl;
    for (int i = 1; i < n; i++) {
    	cout << seq[i-1] << " " << seq[i] << endl;
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

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
    int n, m, q;
    cin >> n >> m >> q;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi vec;
    for (int i = 1; i * i <= m; i++) {
    	if (m % i == 0) {
    		vec.push_back(i);
    		if (i * i != m) vec.push_back(m / i);
    	}
    }
    sort(vec.begin(), vec.end());
    vi Z(vec.size());
    for (int i = 0 ; i < vec.size(); i++) {
    	for (int j = 1; j < n; j++) {
    		if ((a[j] % vec[i]) < (a[j-1] % vec[i])) {
    			Z[i]++;
    		}
    	}
    }
    map<int, int> ma;
    for (int i = 0; i < vec.size(); i++) {
    	ma[vec[i]] = i;
    }
    while (q--) {
    	int zzz;
    	cin >> zzz;
    	if (zzz == 1) {
    		int idx, x;
    		cin >> idx >> x;
    		idx--;
    		for (int i = 0; i < vec.size(); i++) {
    			if (idx && (a[idx] % vec[i]) < (a[idx-1] % vec[i])) {
    				Z[i]--;
    			}
    			if (idx != n - 1 && (a[idx] % vec[i]) > (a[idx+1] % vec[i])) {
    				Z[i]--;
    			}
    		}
    		a[idx] = x;
			for (int i = 0; i < vec.size(); i++) {
    			if (idx && (a[idx] % vec[i]) < (a[idx-1] % vec[i])) {
    				Z[i]++;
    			}
    			if (idx != n - 1 && (a[idx] % vec[i]) > (a[idx+1] % vec[i])) {
    				Z[i]++;
    			}
    		}
    	} else {
    		int k;
    		cin >> k;
    		int G = gcd(k, m);
    		int lim = m / G;
    		int idx = ma[G];
    		//cout << Z[idx] << " " << lim << endl;
    		if (Z[idx] >= lim) {
    			cout << "NO" << endl;
    		} else {
    			cout << "YES" << endl;
    		}
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

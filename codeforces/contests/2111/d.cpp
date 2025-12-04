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
    vi a(m);
    for (int i = 0; i < m; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    int idx = 0;
    for (int i = 0; i < n / 2; i++) {
    	for (int j = 0; j < 3; j++) {
    		cout << a[idx] << " " << a[m - idx - 1] << " ";
    	}
    	cout << endl;
    	for (int j = 0; j < 3; j++) {
    		cout << a[m - idx - 1] << " " << a[idx] << " ";
    	}
    	cout << endl;
    	idx++;
    }
    if (n % 2 == 1) {
    	for (int j = 0; j < 3; j++) {
    		cout << a[m - idx - 1] << " " << a[idx] << " ";
    	}
    	cout << endl;
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

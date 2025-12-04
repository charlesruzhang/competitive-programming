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
    int diff = a[1] - a[0];
    for (int i = 1; i < n; i++) {
    	if (a[i] - a[i-1] != diff) {
    		cout << "NO" << endl;
    		return;
    	}
    }
    if (diff > 0 && (a[0] - diff) >= 0 && (a[0] - diff) % (n + 1) == 0) {
    	cout << "YES" << endl; 
    } else if (diff < 0 && (a[n-1] + diff) >= 0 && (a[n-1] + diff) % (n + 1) == 0) {
    	cout << "YES" << endl;
    } else if (diff == 0 && (a[0] - diff) >= 0 && a[0] % (n + 1) == 0) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
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

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
int query(int i, int j) {
	cout << "? " << i + 1 << " " << j + 1 << endl;
	int res;
	cin >> res;
	return res;
}
void solve() {
    int n;
    cin >> n;
    vi r(n);
    for (int i = 1; i < n; i++) {
    	int res = query(0, i);
    	r[i] = res;
    }
    int z = query(1, 2);
    vi a(n);
    a[0] = (r[1] + r[2] - z) / 2;
    for (int i = 1; i < n; i++) {
    	a[i] = r[i] - a[0];
    }
    cout << "! ";
    for (int i = 0; i < n; i++) {
    	cout << a[i] << " ";
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

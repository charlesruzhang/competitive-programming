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
    vi b(n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    }
    ll tot = accumulate(b.begin(), b.end(), 0ll);
    ll x = (n * (n + 1)) / 2;
    ll summ = tot / x;
    if (summ * x != tot) {
    	cout << "NO" << endl;
    	return;
    } 
    b.push_back(b[0]);
    vi a(n+1);
    for (int i = 1; i <= n; i++) {
    	ll diff = b[i] - b[i-1];
    	a[i] = (summ - diff) / n;
    	if (a[i] * n != summ - diff || a[i] <= 0) {
    		cout << "NO" << endl;
    		return;
    	}
    }
    a[0] = a[n];
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
    	cout << a[i] << " ";
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

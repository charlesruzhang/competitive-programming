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
    vl b(2 * n);
    for (int i = 0; i < 2 * n; i++) {
    	cin >> b[i];
    }
    sort(b.begin(), b.end());
    ll summ = 0;
    for (int i = 0; i < n-1; i++) {
    	summ -= b[i];
    }
    for (int i = n-1; i < 2 * n; i++) {
    	summ += b[i];
    }
    vl a(2*n+1);
    for (int i = 0; i < n-1; i ++) {
    	a[2 * i + 1] = b[i];
    	a[2 * i] = b[i + n - 1];
    }
    a[2 * n - 2] = b[2 * n - 2];
    a[2 * n] = b[2 * n - 1];
    a[2 * n - 1] = summ;
    for (int i = 0; i < 2 * n + 1; i++) {
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

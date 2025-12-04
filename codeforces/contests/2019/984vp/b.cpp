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
    int n, k;
    cin >> n >> k;
    vi b(k), c(k);
    vl v(k+1);
    for (int i = 0; i < k; i++) {
    	cin >> b[i] >> c[i];
    	v[b[i]] += c[i];
    }
    sort(v.begin(), v.end(), greater<>());
    ll summ = 0;
    for (int i = 0; i <= min(k, n) - 1; i++) {
    	summ += v[i];
    }
    cout << summ << endl;
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

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
    vi a(n);
    for (int i = 0; i < n;i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<>());
    if (max(a[0] - 1, a[1]) - a[n-1] > k) {
        cout << "Jerry" << endl;
        return;
    }
    ll summ = accumulate(a.begin(), a.end(), 0ll);
    if (summ % 2) {
        cout << "Tom" << endl;
        return;
    } else {
        cout << "Jerry" << endl;
        return;
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

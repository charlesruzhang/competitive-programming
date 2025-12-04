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
    vector<pii> x(k);
    for (int i = 0; i < k; i++) {
        cin >> x[i].first;
        x[i].first--;
    }
    for (int i = 0; i < k; i++) {
        cin >> x[i].second;
    }
    sort(x.begin(), x.end());
    vi lbest(k+1), rbest(k+1);
    vi minn(k+1);
    int idx = -1;
    auto f = [&] (int z, int i) {
        if (z < 0 || z >= n) return 2000000000;
        return x[z].second + abs(x[z].first - i);
    };
    for (int i = 0; i < k; i++) {
        if (idx == -1 || f(idx, x[i].first) > f(i, x[i].first)) {
            idx = i;
        }
        lbest[i+1] = idx;
    }
    idx = -1;
    for (int i = k-1; i >= 0; i--) {
        if (idx == -1 || f(idx, x[i].first) > f(i, x[i].first)) {
            idx = i;
        }
        rbest[i] = idx;
    }
    vi ans(n);
    vi skip(n);
    for (int i = 0; i < k; i++) {
        skip[x[i].first] = 1;
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        ans[i] = min(f(lbest[j], i), f(rbest[j], i));
        if (skip[i]) j++;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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

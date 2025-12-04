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
const int INF = 1e9 + 7;
bitset<200000 + 1> a, maskK;
void solve() {
    int n, k;
    cin >> n >> k;
    vi p(n, -1);
    vvi children(n);
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        p[i] = x - 1;
        children[p[i]].push_back(i);
    }
    int d = 0;
    vi dep(n);
    function <void(int)> dfs = [&] (int u) {
        dep[u] = d;
        for (int v : children[u]) {
            d++;
            dfs(v);
            d--;
        }
    };
    dfs(0);
    int minn = INF;
    vi cnt(n+1);
    for (int i = 0; i < n; i++) {
        if (children[i].size() == 0) {
            minn = min(minn, dep[i]);
        }
        cnt[dep[i]]++;
    }
    vi pref(n+1);
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + cnt[i];
    }
    if (k > n / 2) {
        k = n - k;
    }
    a.reset(); a.set(0);
    maskK.reset();
    for (int i = 0; i <= k; i++) {
        maskK.set(i);
    }
    int ans = 0;
    for (int i = 0; i <= minn; i++) {
        a |= (a << cnt[i]);
        int l = max(0, pref[i+1] - (n - k));
        if (l <= k) {
            auto tmp = a & maskK;
            if (l) tmp >>= l;
            if (tmp.any()) {
                ans = max(ans, i);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        a.reset(i);
    }
    for (int i = 0; i <= k; i++) {
        maskK.reset(i);
    }
    cout << ans + 1 << endl;

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

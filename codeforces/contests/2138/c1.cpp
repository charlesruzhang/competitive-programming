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

    if (k == 0 || k == n) {
        cout << minn + 1 << endl;
        return;
    }
    vi pref(n+1);
    for (int i = 0; i < n; i++) {
        pref[i+1] = pref[i] + cnt[i];
    }
    int l = 0;
    int r = minn;
    if (k > n / 2) {
        k = n - k;
    }
    while (l < r) {
        int m = (l + r + 1) / 2;
        vi a(n);
        a[0] = 1;
        int flag = 0;
        for (int j = m; j >= 0; j--) {
            for (int z = n - 1; z >= cnt[j]; z--) {
                a[z] |= a[z-cnt[j]];
                if (z <= k && pref[m+1] - z <= n - k && a[z]) {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    cout << l + 1 << endl;

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

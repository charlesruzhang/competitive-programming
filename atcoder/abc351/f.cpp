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
        ll ans = 0;
        function <void(vi&, vi&)> merge = [&] (vi& x, vi& y) {
            int i = 0;
            ll cum = 0;
            for (int j = 0; j < y.size(); j++) {
                if (y[j] < x[i]) continue;
                while ((i + 1) < x.size() && x[i+1] < y[j]) {
                    cum += 1ll * (x[i+1] - x[i]) * (i + 1);
                    i++;
                }
                ans += 1ll * (y[j] - x[i]) * (i + 1) + cum;
            }
            int tot = 0;
            vi res(x.size() + y.size());
            i = 0;
            int j = 0;
            while (tot < x.size() + y.size()) {
                int f = (i < x.size()) ? x[i] : 1e9;
                int g = (j < y.size()) ? y[j] : 1e9;
                if (f < g) {
                    res[tot] = f;
                    i++;
                } else {
                    res[tot] = g;
                    j++;
                }
                tot++;
            }
            swap(res, x);
        };
        function <vi(int, int)> comp = [&](int l, int r) {
            if (l == r) {
                vi v;
                v.push_back(a[l]);
                return v;
            }
            int m = (l + r) / 2;
            vector<int> x = comp(l, m);
            vector<int> y = comp(m + 1, r);
            merge(x, y);
            return x;
        };
        comp(0, n-1);
        cout << ans << endl;
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

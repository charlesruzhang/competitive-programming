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
template<typename T>
struct Fenw {
    int n;
    vector<T> fenw;
    
    Fenw(int n) : n(n), fenw(n, 0) {}

    void update(int i, T delta) {
        for (; i < n; i = i | (i + 1))
            fenw[i] += delta;
    }

    T query(int i) {
        T sum = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            sum += fenw[i];
        return sum;
    }

    T range_query(int l, int r) {
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
void solve() {
    int n;
    cin >> n;
    vi a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    ll tot = 0;
    Fenw<ll> F(2e6 + 1);
    Fenw<ll> G(2e6 + 1);
    int X = 1e6;
    vi v;
    vi w;
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            tot += c[i];
        }
        if (!a[i] && b[i]) {
            F.update(c[i] + X, 1);
            G.update(c[i] + X, c[i]);
            w.push_back(c[i]);
        } else if (a[i] && !b[i]) {
            F.update(-c[i] + X, 1);
            G.update(-c[i] + X, -c[i]);
            w.push_back(-c[i]);
        } else if (a[i] && b[i]) {
            v.push_back(c[i]);
        }
    }
    sort(v.begin(), v.end(), greater<>());
    int idx = 0;
    vector<pll> vv;
    while (idx < v.size()) {
        int x = v[idx];
        ll cnt = F.range_query(X - x, X + x);
        ll minus = cnt * x;
        ll add = 2 * tot + G.range_query(0, X + x) + G.range_query(0, X - x - 1) - x;
        ++idx;
        vv.push_back({minus - add + 2 * x, x});
    }
    sort(vv.begin(), vv.end(), greater<>());
    ll tot2 = 0;
    for (int i = 0; i < vv.size(); i++) {
        if (vv[i].first > -tot2) {
            tot2 += 2 * vv[i].second;
            w.push_back(vv[i].second);
            w.push_back(-vv[i].second);
        } else {
            break;
        }
    }
    sort(w.begin(), w.end());
    ll ans = 0;
    ll now = tot;
    for (int i = 0; i < w.size(); i++) {
        now += w[i];
        ans += now;
    }
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

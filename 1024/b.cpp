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
    vi a(n);
    vector<vector<pii>> c(2);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i % 2].push_back({a[i], i / 2});
    }
    ll tot = 0;
    for (int i = 0; i < 2; i++) {
        Fenw<int> F(n+1);
        for (int j = 0; j < c[i].size(); j++) {
            tot += F.range_query(c[i][j].first+1, n);
            F.update(c[i][j].first, 1);
        }
    }
    for (int i = 0; i < 2; i++) {
        sort(c[i].begin(), c[i].end());
    }

    vi ans(n);
    int rev = 0;
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i >= c[j].size()) continue;
            ans[i * 2 + j] = c[j][i].first;
        }
    }
    if (tot % 2) {
        swap(ans[n-1], ans[n-3]);
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

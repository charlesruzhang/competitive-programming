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
    vi a(n), b(n);
    vector<pii> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i] >> b[i];
    	v.push_back({b[i], i});
    }
    sort(v.begin(), v.end());
    map<int, int> ma;
    for (int i = 0; i < n; i++) {
    	ma[v[i].first] = i + 1;
    }
    vi p(n);
    for (int i = 0; i < n; i++) {
    	p[i] = i;
    }
    sort(p.begin(), p.end(), [&](int x, int y) {
    	return a[x] > a[y];
    });
    Fenw<int> F(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	ans += F.range_query(0, ma[b[p[i]]]);
    	F.update(ma[b[p[i]]], 1);
    }
    cout << ans << endl;
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

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
    vi x(n), y(n);
    vector<pii> a, b;
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
        a.push_back({x[i], i});
        b.push_back({y[i], i});   
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vi v(n);
    for (int i = 0; i < n; i++) {
        if (i >= n / 2) {
            v[a[i].second] |= 1;
            v[b[i].second] |= 2;
        }
    }
    vvi cnt(4);
    for (int i = 0; i < n; i++) {
        cnt[v[i]].push_back(i);
    }
    vector<pii> ans;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < cnt[i].size(); j++) {
            ans.push_back({cnt[i][j], cnt[3 - i][j]});
        }
    }
    for (auto [v, w] : ans) {
        cout << v + 1 << " " << w + 1 << endl;
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

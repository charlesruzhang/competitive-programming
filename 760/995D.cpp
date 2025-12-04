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
    ll x, y;
    cin >> n >> x >> y;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll summ = accumulate(a.begin(), a.end(), 0ll);
    ll l = summ - y;
    ll r = summ - x;
    multiset<pair<ll, ll>> s;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	if (i == 0) {
    		s.insert({a[i], 0});
    		continue;
    	}
    	auto it = s.lower_bound({l - a[i], -1});
    	int lo = (it == s.end()) ? s.size() : (*it).second;
    	it = s.lower_bound({r - a[i], n});
    	int hi = (it == s.end()) ? s.size() : (*it).second;
    	ans += hi - lo;
    	s.insert({a[i], i});
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

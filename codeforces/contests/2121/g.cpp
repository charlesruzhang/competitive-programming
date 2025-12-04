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
    	if (l < 0) l = 0;
    	if (r >= n) r = n - 1;
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll offset = n;
    ll tot = 0;
    ll ans = 0;
    Fenw<int> F(2 * n + 1);
    F.update(n, 1);
    for (int i = 0; i < n; i++) {
    	int delta = (s[i] == '1') ? -1 : 1;
		offset += delta;
		tot += (s[i] == '0') ? F.range_query(0, offset - delta) : F.range_query(offset - delta, 2 * n);
		ans += tot;
		F.update(offset, 1);
		//cout << i << " " << tot << endl;
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

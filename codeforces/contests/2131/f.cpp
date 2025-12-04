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
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    Fenw<ll> F(2 * n + 1);
    Fenw<ll> G(2 * n + 1);
    Fenw<ll> H(2 * n + 1);
    for (int i = 0; i < n; i++) {
    	if (b[i] == '1') {
    		cnt++;
    	}
    	int zero = i + 1 - cnt;
    	int diff = zero - cnt;
    	F.update(n + diff, cnt);
    	//cout << n + diff << " + " << cnt << endl;
    	G.update(n + diff, zero);
    	//cout << "G " << n + diff << " + " << zero << endl;
    	H.update(n + diff, 1);
    }
    int cnt2 = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	if (a[i] == '1') {
    		cnt2++;
    	}
    	int zero = i + 1 - cnt2;
    	int diff = - zero + cnt2;
    	ans += F.range_query(n + diff, 2 * n) + 1ll * H.range_query(n + diff, 2 * n) * cnt2;
    	//cout << n + diff << " ? " << F.range_query(n + diff, 2 * n) << endl;
    	ans += G.range_query(0, n + diff - 1) + 1ll * H.range_query(0, n + diff - 1) * zero;
    	//cout << "G " << n + diff - 1 << " + " << G.range_query(0, n + diff - 1) << endl;
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

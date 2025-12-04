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
ll A = 0;
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
        for (; i >= 0; i = (i & (i + 1)) - 1) {
        	A++;
            sum += fenw[i];
        }
        return sum;
    }

    T range_query(int l, int r) {
        return query(min(r, n-1)) - (l > 0 ? query(l - 1) : 0);
    }
};
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    Fenw<ll> F(3e5+1);
    Fenw<int> G(3e5+1);
    ll ans = 0;
    ll T = 0;
    for (int i = 0; i < n; i++) {
    	int cnt = G.range_query(1, a[i]);
    	ans += T;
    	ans += 1ll * i * a[i];
    	ans += F.range_query(1, a[i]);
    	int cnt2 = i - cnt;
    	int X = 1;
    	for (int j = a[i]; j <= 300000; j+=a[i]) {
    		int y = G.range_query(j, j + a[i] - 1);
    		ans -= 1ll * y * (X++) * a[i];
    		F.update(j, -a[i]);
    	}
    	cout << ans << " ";
    	G.update(a[i], 1);
    	T += a[i];
    }
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

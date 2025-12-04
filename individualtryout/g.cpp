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
    int n, q;
    cin >> n >> q;
    Fenw<int> F(n);
    for (int i = 0; i < q; i++) {
    	string s;
    	cin >> s;
    	if (s == "?") {
    		int l, r;
    		cin >> l >> r;
    		l--; r--;
    		if (l > r) swap(l, r);
    		int x = F.range_query(l, r);
    		int y = F.range_query(r, n - 1) + F.range_query(0, l);
    		if (x == 0 || y == 0) {
    			cout << "possible" << endl;
    		} else {
    			cout << "impossible" << endl;
    		}
    	} else if (s == "+") {
    		int l;
    		cin >> l;
    		l--;
    		F.update(l, -1);
    	} else {
    		int l;
    		cin >> l;
    		l--;
    		F.update(l, 1);
    	}
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

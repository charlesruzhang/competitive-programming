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
int maxn = 2e5+1;
vvi facts(maxn);
void comp() {
	for (int x = 1; x < maxn; x++) {
		for (int i = x; i < maxn; i+=x) {
			facts[i].push_back(x);
		}	
	}
}
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
	int q;
	cin >> q;
	vector<pii> qrs(q);
    vector<ll> ans(q);
    vvi qr(maxn);
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        qrs[i] = {L, R};
        ans[i] = 1ll * (R - L + 1) * (R - L) * (R - L - 1) / 6;
    	ans[i] -= max(0, (2 * R) / 12 - (4 * L - 1) / 12);
    	ans[i] -= max(0, (2 * R) / 30 - (5 * L - 1) / 30);
        qr[R].push_back(i);
    }

    Fenw<int> F(maxn);
    for (int i = 1; i < maxn; i++) {
        for (int j = 0; j < facts[i].size() - 1; j++) {
            F.update(facts[i][j], facts[i].size() - 2 - j);
        }
        for (int z : qr[i]) {
            ans[z] -= F.range_query(qrs[z].first, i);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    comp();
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

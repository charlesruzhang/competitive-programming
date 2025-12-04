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
    vi a(n);
    mt19937 rng(31415929);
    auto P = uniform_int_distribution<int>(1, 5000);
    set<int> s;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	s.insert(a[i]);
    }
    vector<array<int, 3>> qrs(q);
    for (int i = 0; i < q; i++) {
    	int u;
    	cin >> u;
    	if (u == 2) {
    		int l, r, k;
    		cin >> l >> r >> k;
    		l--; r--;
    		qrs[i] = {l, r, k};
    	} else {
    		int id, x;
    		cin >> id >> x;
    		id--;
    		s.insert(x);
    		qrs[i] = {-1, id, x};
    	}
    }
    vi cnt(s.size());
    int timer = 0;
    map<int, int> ma;
    for (int z : s) {
    	cnt[timer] = z;
    	ma[z] = timer++;
    }
    int T = 23;
    vector<Fenw<int>> F(T, n);
    vi b;
    for (int i = 0; i < n; i++) {
    	b.push_back(ma[a[i]]);
    }
    vvi H(s.size(), vi(T));
    for (int i = 0; i < s.size(); i++) {
    	for (int j = 0; j < T; j++) {
    		H[i][j] = P(rng);
    	}
    }
    for (int i = 0; i < T; i++) {
    	for (int j = 0; j < n; j++) {
    		F[i].update(j, H[b[j]][i]);
    	}
    }
    for (int i = 0; i < q; i++) {
    	auto& [x, y, z] = qrs[i];
    	if (x == -1) {
    		int zz = ma[z];
    		for (int j = 0; j < T; j++) {
    			int yy = F[j].range_query(y, y);
    			F[j].update(y, H[zz][j] - yy);
    		}
    	} else {
    		int flag = 1;
    		for (int j = 0; j < T; j++) {
    			ll summ = F[j].range_query(x, y);
    			if (summ % z) {
    				cout << "NO" << "\n";
    				flag = 0;
    				break;
    			}
    		}
    		if (flag) {
    			cout << "YES" << "\n";
    		}
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

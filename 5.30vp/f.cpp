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
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi vec(n + 1);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	vec[a[i]] = i;
    }
    vvl ans(n);
    for (int i = n; i >= 1; i--) {
    	ans[vec[i]].assign(n / i, 0);
    	for (int j = i; j <= n; j += i) {
    		if (vec[j] < vec[i]) continue;
    		for (int k = j; k <= n; k += j) {
    			if (vec[k] < vec[j]) continue;
    			ans[vec[i]][k / i - 1] += ans[vec[j]][k / j - 1];
    		}
    	}
    	ans[vec[i]][0] = 1;
    } 
    //cout << " hi" << endl;
    vector<tuple<int,int,int>> qrs;
    for (int i = 0; i < q; i++) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	qrs.push_back({l, r, i});
    }
    sort(qrs.begin(), qrs.end(), greater<>());
    int idx = 0;
    int j = n - 1;
    Fenw<ll> F(n);
    vl res(q);
    while (idx < q) {
    	auto [l, r, z] = qrs[idx];
    	while (j >= l) {
    		for (int i = 0; i < ans[j].size(); i++) {
    			F.update(vec[a[j] * (i + 1)], ans[j][i]);
    		}
    		j--;
    	}
    	//cout << " ? " << endl;
    	res[z] = F.range_query(l, r);
    	idx++;
    }
    for (int i = 0; i < q; i++) {
    	cout << res[i] << " ";
    }
    cout << "\n";
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

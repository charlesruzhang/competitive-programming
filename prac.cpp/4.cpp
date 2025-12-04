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
const int M = 1 << 18;
class DSU {
public:
    vector<int> parent, size;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
        }
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }
     void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vi cnt(M);
    vi used(M);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	cnt[a[i]]++;
    	ans -= a[i];
    }
    cnt[0] += 1;
    DSU D(1 << 18);
    int c = (1 << 18) - 1;
    for (int i = 0; i < (1 << 18); i++) {
    	int x = c ^ i;
    	vi vec;
    	for (int j = 0; j < 18; j++) {
    		if ((1 << j) & x) {
    			vec.push_back(j);
    		}
    	}
    	for (int j = x; j > 0; (--j) &= x) {
    		if (cnt[j] == 0 || cnt[x ^ j] == 0) continue;
    		int y = x ^ j;
    		if (D.find(y) != D.find(j)) {
    			D.unite(y, j);
    			int tot = ((used[y]) ? 1 : cnt[y]) + (used[j] ? 1 : cnt[j]) - 1; 
    			ans += 1ll * x * tot;
    			used[y] = used[j] = 1;
    		}
    	}
    }
    cout << ans << endl;
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

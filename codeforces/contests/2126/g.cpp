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
class DSU {
public:
    vector<int> parent, size, l, r;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
     	l.resize(n);
     	r.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            l[i] = r[i] = i; 
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
            l[a] = min(l[a], l[b]);
            r[a] = max(r[a], r[b]);
        }
    }
};
void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<pii> b(n);
    for (int i = 0; i < n; i++) {
    	b[i] = {a[i], i};
    }
    vi mark(n);
    DSU D1(n+1), D2(n+1);
    int ans = 0;
    int minn = 1e9;
    sort(b.begin(), b.end(), greater<>());
    for (int i = 0; i < n; i++) {
    	int x = b[i].second;
		for (int t = 0; t < 2; t++) {
			int z = D1.find(x+1);
			int l = D1.l[z];
			if (l) {
				D1.unite(l - 1, l);
				minn = min(minn, a[l-1]);
			}
			z = D2.find(x);
			int r = D2.r[z];
			if (r < n) {
				D2.unite(r, r + 1);
				minn = min(minn, a[r]);
			}
		}
		ans = max(ans, a[x] - minn);
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

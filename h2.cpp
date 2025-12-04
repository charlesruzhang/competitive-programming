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
    vector<int> parent, size, maxx;
    DSU(int n, int m) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
            maxx[i] = i / m;
            minn[i] = i % (n / m);
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
            maxx[a] = max(maxx[a], maxx[b]);
            minn[a] = min(minn[a], minn[b]);
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
    	cin >> s[i];
    }
    DSU D1(n * m, n);
    for (int j = 0; j < m; j++) {
    	for (int i = 0; i < n; i++) {
    		if (i && s[i][j] == s[i-1][j] && s[i][j] == '#') {
    			D1.unite(i * m + j, i * m - m + j);
    		}
    		if (j && s[i][j] == s[i][j-1] && s[i][j] == '#') {
    			D1.unite(i * m + j, i * m + j - 1);
    		}
    	}
    }
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

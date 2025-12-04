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
    DSU D(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (i && a[i] == a[i-1] && a[i] == 0) D.unite(i, i - 1);
    }
    if (D.find(0) == D.find(n-1) && a[0] == 0) {
    	cout << 0 << endl;
    	return;
    }
    for (int i = 0; i < n; i++) {
    	if (a[i] == 0 && D.find(i) != D.find(0) && D.find(i) != D.find(n-1)) {
    		cout << 2 << endl;
    		return;
    	} 
    }
    cout << 1 << endl;
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

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
    int n, r;
    cin >> n >> r;
    r--;
    DSU D(n);
    vi a(n);
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	x--;
    	D.unite(x, i);
    	a[i] = x;
    }
    for (int i = 0; i < n; i++) {
    	if (a[i] == r && i != r) {
    		cout << -1 << endl;
    		return;
    	}
    }
    vi P(n, -1);
    vvi V(n);
    int mark = -1;
    for (int i = 0; i < n; i++) {
    	int y = D.find(i);
    	if (P[y] == -1) {
    		P[y] = a[i];
    	} else if (P[y] != a[i]) {
    		cout << -1 << endl;
    		return;
    	}
    	V[a[i]].push_back(i);
    	if (i == r) {
    		mark = a[i];
    	}
    }
    vi ans;
    for (int i = 0; i < n; i++) {
    	if (i != mark) {
    		for (int v : V[i]) {
    			if (v != i) ans.push_back(v);
    		}
    		if (V[i].size()) ans.push_back(i);
    	}
    }
    ans.push_back(r);
    for (int v : V[mark]) {
    	if (v != mark && v != r) ans.push_back(v);
    }
    if (mark != r && V[mark].size()) ans.push_back(mark);
    assert(ans.size() == n);
    for (int i = 0; i < n; i++) {
    	cout << ans[i] + 1 << " ";
    }
    cout << endl;
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

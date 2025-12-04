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
    vector<int> parent, size, L, R;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        L.resize(n);
        R.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            L[i] = R[i] = i; 
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
            L[a] = min(L[a], L[b]);
            R[a] = max(R[a], R[b]);
        }
    }
};
void solve() {
    int n;
    cin >> n;
    vi a(n);
    vvi V(n);
    DSU D(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	V[a[i]].push_back(i);
    }
    if (V[0].size() >= 2) {
    	cout << "No" << endl;
    	return;
    }
    for (int i = n - 1; i >= 1; i--) {
    	for (int x : V[i]) {
    		if (x && a[x - 1] >= a[x]) {
    			D.unite(x, x - 1);
    		}
    		if (x != n - 1 && a[x + 1] >= a[x]) {
    			D.unite(x, x + 1);
    		}
    	}
    	for (int x : V[i]) {
    		int p = D.find(x);
    		int l = D.L[p];
    		int r = D.R[p];
    		int flag = 0;
    		if (l && a[l - 1] == i - 1) {
    			flag = 1;
    		}
    		if (r != n - 1 && a[r + 1] == i - 1) {
    			flag = 1;
    		}
    		if (!flag) {
    			cout << "No" << endl;
    			return;
    		}
    	}
    }
    cout << "Yes" << endl;
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

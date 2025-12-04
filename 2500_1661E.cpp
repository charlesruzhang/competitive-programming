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
    vvi a(3, vi(n));
    for (int i = 0; i < 3; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < n; j++) {
    		a[i][j] = s[j] - '0';
    	}
    }
    vi pref(n+1);
    int tot = 0;
    DSU D(3 * n);
    DSU D2(n);
    vi v(n, -1);
    for (int j = 0; j < n; j++) {
    	for (int i = 0; i < 3; i++) {
    		if (a[i][j]) {
    			tot++;
    			if (j && a[i][j-1]) {
    				if (D.find(3 * j + i) != D.find(3 * j + i - 3)) tot--;
    				D.unite(3 * j + i, 3 * j + i - 3);
    			}
    			if (i && a[i-1][j]) {
    				if (D.find(3 * j + i) != D.find(3 * j + i - 1)) tot--;
    				D.unite(3 * j + i, 3 * j + i - 1);
    			}
    		}
    		pref[j+1] = tot;
    	}
    }
    for (int j = 0; j < n; j++) {
    	if (a[0][j] && a[2][j]) {
    		if (j && v[j-1] == -2) {
    			D2.unite(j, j-1);
    		}
    		if (a[1][j]) {
    			v[D2.find(j)] = j;
    		} else {
    			v[j] = -2;
    		}
    	}
    }
    vi w(n, -1);
    DSU D3(n);
    for (int j = n-1; j >= 0; j--) {
    	if (a[0][j] && a[2][j]) {
    		if (j != n-1 && w[j+1] == -2) {
    			D3.unite(j, j+1);
    		}
    		if (a[1][j]) {
    			w[D3.find(j)] = j;
    		} else {
    			w[j] = -2;
    		}
    	}
    }
    
    // for (int i = 0; i < n; i++) {
    // 	cout << v[i] << " " << i << " ? " << v[D2.find(i)] << endl;
    // }
    int q;
    cin >> q;
    while (q--) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	int ans = pref[r+1] - pref[l];
    	int flag = 0;
    	// cout << ans << " ? " << endl;
    	int prev = -1;
    	for (int i = 0; i < 3; i++) {
    		if (l && a[i][l] && a[i][l-1]) {
    			if (prev == -1 || D.find(prev) != D.find(3 * l + i)) flag++;
    			prev = 3 * l + i;
    		}
    	}
    	ans+=flag;
    	//cout << flag << " ? " << endl;
    	if (a[0][l] && a[2][l] && D.find(3 * l) == D.find(3 * l + 2)) {
    		int p = D2.find(l);
    		if (v[p] < 0 || (v[p] > r && w[D3.find(l)] >= 0)) {
    			ans++;
    		}
    	}
    	if (l && a[0][l-1] && a[2][l-1] && D.find(3 * l - 3) == D.find(3 * l -1)) {
    		int p = D3.find(l-1);
    		if (w[p] < 0) {
    			ans++;
    		}
    	}  
    	cout << ans << endl;
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

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
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    DSU D(n);
    int d = (x == 0) ? 0 : 32 - __builtin_clz(x);
    function <int(DSU&)> check = [&] (DSU &A) {
    	int cnt = 0;
    	for (int i = 0; i < n; i++) {
    		if (A.find(i) == i) {
    			cnt++;
    		}
    	}
    	return cnt;
    };
    function <int(DSU&, int i)> unite = [&] (DSU &A, int i) {
		int tot = 0;
    	for (int j = 0; j < n; j++) {
    		if (j && tot % 2) {
    			A.unite(j, j - 1);
    		}
    		if (a[j] & (1 << i)) tot++;
    	}
    	return tot;
    };

    for (int i = 29; i >= d; i--) {
    	if (unite(D, i) % 2) {
    		cout << -1 << endl;
    		return;
    	}
    }

    int maxx = -1;
    int flag = 1;

    for (int i = d - 1; i >= 0; i --) {
    	int z = x & (1 << i);
    	if (z) {
    		DSU D2(n);
    		for (int j = 0; j < n; j++) {
    			D2.parent[j] = D.parent[j];
    			D2.size[j] = D.size[j];
    		}
	    	if (unite(D2, i) % 2) continue;
	    	maxx = max(check(D2), maxx);
    	} else {
	    	if (unite(D, i) % 2) {
	    		flag = 0;
	    		break;
	    	}
    	}
    }
    if (flag) maxx = max(check(D), maxx);
	cout << maxx << endl;
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

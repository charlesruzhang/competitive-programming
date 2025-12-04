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
    DSU(int n, vi &a) {
        parent.resize(n);
        size.resize(n, 1);
        maxx.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            maxx[i] = a[i]; 
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
            maxx[a] |= maxx[b];
        }
    }
};
void solve() {
    int n;
    cin >> n;
    vi a(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    	if (!a[i]) {
    		a[i] = 1;
			ans++;
		}    
    }
    DSU D(n, a);
    for (int i = 0; i <= 30; i++) {
    	int prev = -1;
    	for (int j = 0; j < n; j++) {
    		if (!((1 << i) & a[j])) continue;
    		if (prev != -1) {
    			D.unite(prev, j);
    		}
    		prev =j;
    	}
    }
    if (D.size[D.find(0)] == n) {
    	cout << ans << endl;
    	for (int i = 0; i < n; i++) {
    		cout << a[i] << " ";
    	}
    	cout << endl;
    	return;
    }
    vvi vs(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
    	vs[D.find(i)].push_back(i);
    	s.insert(D.find(i));
    }
    auto it = s.begin();
    int maxx = 0;
    int idx = -1;
    while (it != s.end()) {
    	int val = D.maxx[*it];
    	int v = -1;
    	for (int i = 0; i <= 30; i++) {
    		if ((1 << i) & val) {
    			v = i;
    			break;
    		}
    	}
    	if (maxx <= v) {
    		maxx = v;
    		idx = *it;
    	}
    	++it;
    }
    for (int z = 0; z < n; z++) {
    	DSU D1(n, a);
    	a[z]--;
	    for (int i = 0; i <= 30; i++) {
	    	int prev = -1;
	    	for (int j = 0; j < n; j++) {
	    		if (!((1 << i) & a[j])) continue;
	    		if (prev != -1) {
	    			D1.unite(prev, j);
	    		}
	    		prev =j;
	    	}
	    }
    	if (D1.size[D1.find(0)] == n) {
	    	cout << ans + 1 << endl;
	    	for (int i = 0; i < n; i++) {
	    		cout << a[i] << " ";
	    	}
	    	cout << endl;
	    	return;
	    }
    	a[z]++;
    }
    for (int z = 0; z < n; z++) {
    	DSU D1(n, a);
    	a[z]++;
	    for (int i = 0; i <= 30; i++) {
	    	int prev = -1;
	    	for (int j = 0; j < n; j++) {
	    		if (!((1 << i) & a[j])) continue;
	    		if (prev != -1) {
	    			D1.unite(prev, j);
	    		}
	    		prev =j;
	    	}
	    }
    	if (D1.size[D1.find(0)] == n) {
	    	cout << ans + 1 << endl;
	    	for (int i = 0; i < n; i++) {
	    		cout << a[i] << " ";
	    	}
	    	cout << endl;
	    	return;
	    }
    	a[z]--;
    }
    cout << ans + 2 << endl;
    assert(vs[idx].size() >= 2);
    a[vs[idx][0]]++;
    a[vs[idx][1]]--;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return;
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

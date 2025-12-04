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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; i++) {
    	cin >> s[i];
    }
    vector<vector<set<int>>> vss(h, vector<set<int>>(w));
    DSU D(h * w);
    vvi valid(h, vi(w, 1));
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		if ((s[i][j] == '#') || (i && s[i-1][j] == '#') || ((i != h - 1) && s[i+1][j] == '#') || (j && s[i][j-1] == '#')||((j != w-1) && s[i][j+1] == '#')) {
    			valid[i][j] = 0;
    		}
    	}
    }
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		if (i != h - 1 && valid[i][j] && valid[i+1][j]) {
    			D.unite(i * w + j, (i+1) * w + j);
    		}

    		if (j != w - 1 && valid[i][j] && valid[i][j+1]) {
    			D.unite(i * w + j, i * w + j + 1);
    		}
    	}
    }
    int ans = 1;
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		if (s[i][j] == '#') continue;
    		if (!valid[i][j]) {
    			continue;
    		}
    		if (i && s[i-1][j] == '.') {
    			vss[i-1][j].insert(D.find(i * w + j));
    		}
    		if ((i != h-1) && s[i+1][j] == '.') {
    			vss[i+1][j].insert(D.find(i * w + j));
    		}
    		if (j && s[i][j-1] == '.') {
    			vss[i][j-1].insert(D.find(i * w + j));
    		}
    		if ((j != w-1) && s[i][j+1] == '.') {
    			vss[i][j+1].insert(D.find(i * w + j));
    		}
    		vss[i][j].insert(D.find(i * w + j));
    	}
    }
    vi answ(h * w);
    for (int i = 0; i < h; i ++) {
    	for (int j = 0; j < w; j++) {
    		auto it = vss[i][j].begin();
    		while (it != vss[i][j].end()) {
    			int val = *it;
    			answ[val]++;
    			++it;
    		}
    	}
    }
    for (int i = 0; i < h; i++) {
    	for (int j = 0; j < w; j++) {
    		ans = max(ans, answ[i * w + j]);
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

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
    vector<int> parent, size, minn, maxx;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        minn.resize(n);
        maxx.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
            minn[i] = maxx[i] = i;
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
            minn[a] = min(minn[a], minn[b]);
            maxx[a] = max(maxx[a], maxx[b]);
        }
    }
};
void solve() {
    int n, m;
    cin >> n >> m;
    int N = n, M = m;
    if (n > m) {
    	N = m;
    	M = n;
    }
    vvi a(N, vi(M));
    for (int i = 0; i < n; i++) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; j++) {
    		if (n <= m) a[i][j] = s[j] - '0';
    		else a[j][i] = s[j] - '0';
    	}
    }
    // for (int i = 0; i < N; i++) {
    // 	for (int j = 0; j < M; j++) {
    // 		cout << a[i][j];
    // 	}
    // 	cout << endl;
    // }
    vvi width(N * N, vi(M, INF));
    for (int i = 0; i < N; i++) {
    	for (int j = i + 1; j < N; j++) {
    		int minn = -INF;
    		int y = 0;
    		for (int z = 0; z < M; z++) {
    			//cout << i << " " << j << " " << a[i][z] << " " << a[j][z] << endl;
    			if (a[i][z] && a[j][z]) {
    				while (y < z) {
    					width[i * N + j][y] = min(width[i * N + j][y], z - minn + 1);
    					y++;
    				}
    				width[i * N + j][z] = min(width[i * N + j][z], z - minn + 1);
    				minn = z;
    			}
    		}
    	}
    }
    vvi ans(N, vi(M, INF));
    vector<vector<array<ll, 2>>> tot(N * M);
    for (int i = 0; i < M; i++) {
    	for (int j = 0; j < N; j++) {
    		for (int k = j + 1; k < N; k++) {
    			ll V = 1ll * width[j * N + k][i] * (k - j + 1);
    			if (V < INF) tot[V].push_back({j, k});
    		}
    	}
    	DSU D(N);
    	for (int j = 0; j < N * M; j++) {
    		while (tot[j].size()) {
    			auto [x, y] = tot[j].back();
	    		int xx = D.find(x);
	    		int yy = D.find(y);
	    		if (xx == yy) {
	    			continue;
	    		}
	    		xx = D.maxx[xx];
	    		yy = D.minn[yy];
	    		for (int z = xx; z <= yy; z++) {
	    			ans[z][i] = min(ans[z][i], j);
	    			D.unite(z, xx);
	    		}
	    		tot[j].pop_back();
    		}
    	}
    }
    if (n > m) {
    	for (int i = 0; i < M; i++) {
    		for (int j = 0; j < N; j++) {
    			if (ans[j][i] == INF) cout << 0 << " ";
    			else cout << ans[j][i] << " ";
    		}
    		cout << "\n";
    	}
    } else {
    	for (int i = 0; i < N; i++) {
    		for (int j = 0; j < M; j++) {
    			if (ans[i][j] == INF) cout << 0 << " ";
    			else cout << ans[i][j] << " ";
    		}
    		cout << "\n";
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

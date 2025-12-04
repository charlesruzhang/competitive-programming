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
    int n;
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<pii> ans = {{a, b}, {a, -b}, {b, a}, {b, -a}, {-a, b}, {-a, -b}, {-b, a}, {-b, -a}};
    vector<pii> ans2 = {{c, d}, {c, -d}, {d, c}, {d, -c}, {-c, d}, {-c, -d}, {-d, c}, {-d, -c}};
    queue<pii> q;
    q.push({0, 0});
    q.push({0, 1});
    vi vis(n * n * 2);
    vis[0] = vis[n * n] = 1;
    while (!q.empty()) {
    	auto [x, y] = q.front();
    	q.pop();
    	if (y == 0) {
    		int cx = x / n;
    		int cy = x % n;
    		for (auto [z, w] : ans2) {
    			int dx = cx + z;
    			int dy = cy + w;
    			if (0 <= dx && dx < n && 0 <= dy && dy < n && !vis[dx * n + dy + n * n]) {
    				vis[dx * n + dy + n * n] = 1;
    				q.push({dx * n + dy, 1});
    			}
    		}
    	} else {
    		int cx = x / n;
    		int cy = x % n;
    		for (auto [z, w] : ans) {
    			int dx = cx + z;
    			int dy = cy + w;
    			if (0 <= dx && dx < n && 0 <= dy && dy < n && !vis[dx * n + dy]) {
    				vis[dx * n + dy] = 1;
    				q.push({dx * n + dy, 0});
    			}
    		}
    	}
    }
    int ansA = 0;
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
    		if (vis[i * n + j] || vis[i * n + j + n * n]) {
    			ansA++;
    		}
    	}
    }
    cout << ansA << endl;
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

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
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    ofstream out("K1.out");
    while (t--) {
    	int n, w;
        cin >> n >> w;
        vector<array<int, 4>> vs(n+1);
        vs[n] = {w, 0, 0, n};
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            vs[i] = {z, x, y, i};
        }
        vector<vector<double>> dist(n + 1, vector<double>(n + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dist[i][j] = sqrt((double)(vs[i][1] - vs[j][1]) * (vs[i][1] - vs[j][1]) + (double)(vs[i][2] - vs[j][2]) * (vs[i][2] - vs[j][2]));
            }
        }
        vi used(n+1);
        while (1) {
            DSU D(n+1);
            priority_queue<tuple<double, int, int>, vector<tuple<double,int,int>>, greater<>> pq;
            for (int i = 0; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (!used[i] && !used[j] && vs[i][0] * 2 < w && vs[j][0] * 2 < w) {
                        pq.push({dist[i][j], i, j});
                    }
                }
            }
            if (pq.empty()) break;
            while (!pq.empty()) {
                auto [d, x, y] = pq.top();
                pq.pop();
                if (D.find(x) != D.find(y)) {
                    D.unite(x, y);
                    
                }
            }
        }
    }

    return 0;
}

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
    vector<int> parent, size, maxx;
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        maxx.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; 
            maxx[i] = i;
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
            maxx[a] = max(maxx[a], maxx[b]);
        }
    }
};
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vvi a(n, vi(m));
    DSU D(n * m + m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                D.unite(i * m + j, i * m + m + j);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        x--;
        int cur = x;
        int v = 0;
        while (v < n) {
            int y = D.maxx[D.find(v * m + cur)];
            if (y / m >= n) {
                cur = y % m;
                v = y / m;
                break;
            }
            int t = a[y / m][y % m];
            if (t != 2) {
                a[y / m][y % m] = 2;
                D.unite(y, y + m);
                if (t == 1) y++;
                else y--;
            }

            cur = y % m;
            v = y / m;
        }
        cout << cur + 1;
        if (i != k - 1) {
        	cout << " ";
        }
    }
    cout << endl;
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

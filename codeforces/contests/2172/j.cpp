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
    vector<int> parent, r, cnt;
    DSU(int n) {
        parent.resize(n);
        r.resize(n);
        cnt.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            r[i] = i; 
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
            parent[b] = a;
            r[a] = max(r[a], r[b]);
            cnt[a] += cnt[b];
        }
    }
};
void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    vvi W(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        W[a[i]].push_back(i);
    }
    vvi V(n+1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
        V[b[i]].push_back(i);
    }
    DSU D(n);
    vi pref(n + 1);
    pref[0] = n;
    for (int i = 0; i <= n; i++) {
        for (int u : V[i]) {
            int x = D.find(u);
            int y = D.find(u + 1);
            int c1 = D.cnt[x];
            int rx = D.r[x];
            pref[rx - c1 + 1] -= n - i;
            pref[rx + 1] += n - i;

            int c2 = D.cnt[y];
            int ry = D.r[y];
            pref[ry - c2 + 1] -= n - i;
            pref[ry + 1] += n - i;

            D.unite(x, y);

            int c = D.cnt[D.find(x)];
            int r = D.r[D.find(x)];
            pref[r - c + 1] += n - i;
            pref[r + 1] -= n - i;
        }

        for (int v : W[i]) {
            int x = D.find(v);
            D.cnt[x]--;
            int c = D.cnt[x];
            int r = D.r[x];
            pref[r - c] -= n - i;
            pref[r - c + 1] += n - i;
        }
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += pref[i];
        cout << cur << " ";
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

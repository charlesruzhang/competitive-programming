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
int query (int u, int v) {
    cout << u + 1 << " " << v + 1 << endl;
    int res = 0;
    cin >> res;
    return res;
}
void solve() {
    int n;
    cin >> n;
    vvi A(n, vi(n));
    for (int i = 0; i < n; i++) {
        A[i][i] = 1;
    }
    int cur = 2;
    while (1) {
        vvi a;
        int j = 0;
        while (j < n) {
            vi b;
            for (int i = 0; i < cur; i++) {
                b.push_back(j);
                j++;
                if (j == n) break;
            }
            a.push_back(b);
        }
        for (int i = 0; i < a.size(); i++) {
            int x = a[i].size();
            auto &vv = a[i]; 
            for (int j = 0; j < x; j++) {
                for (int k = 0; k < x; k++) {
                    int y = vv[j];
                    int z = vv[k];
                    if (A[y][z] == 0) {
                        int res = query(y, z);
                        if (res) {
                            return;
                        }
                        A[y][z] = A[z][y] = 1;
                    }
                }
            }
        }
        cur *= 2;
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

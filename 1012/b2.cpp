#include <bits/stdc++.h>
using namespace std;
#define int long long int
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
    	maxx.resize(n);
        size.resize(n, 1);
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
    int n;
    ll k;
    cin >> n >> k;
    vi a(n), b(n);
    for (int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vi c(2 * n);
    for (int i = 0; i < n; i++) {
    	cin >> b[i];
    	c[i] = a[i] - b[i];
    	c[n+i] = c[i];
    }
    vi pref(2 * n + 1);
    for (int i = 0; i < 2 * n; i++) {
    	pref[i+1] = pref[i] + c[i];
    }
    DSU D(2 * n);
    int ans = 1;
    if (k == accumulate(a.begin(), a.end(), 0ll)) {
        cout << 0 << endl;
        return;
    }
    int l = 1;
    int r = n;
    function <bool(int)> check = [&](int m) {
        ll tot = 0;
        for (int i = n-1; i >= 0; i --) {
            if (c[i] <= 0) {
                continue;
            }
            int cur = i + 1;
            int next = D.maxx[D.find(cur)];
            while (cur < 2 * n) {
                int x = pref[next+1] - pref[i];
                int curtmp = cur;
                if (x >= 0) {
                    if (curtmp - i + 1 > m) {
                        c[i] -= x;
                        tot += x;
                        break;
                    }
                    D.unite(i, cur);
                    cur = next + 1;
                    next = D.maxx[D.find(cur)];
                } 
                if (x <= 0) {
                    break;
                }
            }
        }


    };
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    
    cout << ans << endl;
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

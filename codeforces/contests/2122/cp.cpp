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
void solve() {
    int n;
    cin >> n;
    vi x(n), y(n);
    vector<pii> a, b;
    for (int i = 0; i < n; i++) {
    	cin >> x[i] >> y[i];
    }
    vi mark(n);
    vector<pii> ans;
    ll tot = 0;
    for (int i = 0; i < n / 2; i++) {
        int maxx = -1;
        int f = -1, s = -1;
    	for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (mark[j] || mark[k]) continue;
                if (maxx < abs(x[k] - x[j]) + abs(y[k] - y[j])) {
                    maxx = abs(x[k] - x[j]) + abs(y[k] - y[j]);
                    f = j;
                    s = k;
                }
            }
        }
        mark[f] = mark[s] = 1;
        tot += maxx;
        ans.push_back({f, s});
    }
    for (int i = 0; i < n / 2; i++) {
    	cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
    cout << tot << endl;
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